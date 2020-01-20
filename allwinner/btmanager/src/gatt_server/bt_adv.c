#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include <lib/bluetooth.h>
#include <lib/hci.h>
#include <lib/hci_lib.h>

#include "gatt_server_glue.h"
#include "bt_adv.h"

#include "log.h"

static bool adv_enable;

#define MANUFACTURER_DATA_LEN	8
#define WIFI_LEN				6

static void hex_dump(char *pref, int width, unsigned char *buf, int len)
{
	register int i,n;

	for (i = 0, n = 1; i < len; i++, n++) {
		if (n == 1)
			printf("%s", pref);
		printf("%2.2X ", buf[i]);
		if (n == width) {
			printf("\n");
			n = 0;
		}
	}
	if (i && n!=1)
		printf("\n");
}

int enableAdv(bool enable)
{
	struct hci_request rq;
	le_set_advertising_parameters_cp adv_params_cp;
	le_set_advertise_enable_cp advertise_cp;
	uint8_t status;
	int dd, ret;
	int hdev = 0;
	char *opt = NULL;

	dd = hci_open_dev(hdev);

	if (dd < 0) {
		pr_error("Could not open device");
		return -1;
	}

	memset(&adv_params_cp, 0, sizeof(adv_params_cp));
	adv_params_cp.min_interval = htobs(0x0020);
	adv_params_cp.max_interval = htobs(0x0020);
	adv_params_cp.own_bdaddr_type = LE_RANDOM_ADDRESS;
	if (opt)
		adv_params_cp.advtype = atoi(opt);
	adv_params_cp.chan_map = 7;

	memset(&rq, 0, sizeof(rq));
	rq.ogf = OGF_LE_CTL;
	rq.ocf = OCF_LE_SET_ADVERTISING_PARAMETERS;
	rq.cparam = &adv_params_cp;
	rq.clen = LE_SET_ADVERTISING_PARAMETERS_CP_SIZE;
	rq.rparam = &status;
	rq.rlen = 1;

	ret = hci_send_req(dd, &rq, 1000);
	if (ret < 0)
		goto done;

	memset(&advertise_cp, 0, sizeof(advertise_cp));
	advertise_cp.enable = (uint8_t)enable;

	memset(&rq, 0, sizeof(rq));
	rq.ogf = OGF_LE_CTL;
	rq.ocf = OCF_LE_SET_ADVERTISE_ENABLE;
	rq.cparam = &advertise_cp;
	rq.clen = LE_SET_ADVERTISE_ENABLE_CP_SIZE;
	rq.rparam = &status;
	rq.rlen = 1;

	ret = hci_send_req(dd, &rq, 1000);
	if (ret < 0) {
		pr_error("cannot send enable advertising");
		goto done;
	} else {
		if(status == 0)
			pr_info("set adv enable");
		else if (status == 12)
			pr_info("likely already advertising...");
		else
			pr_info("UnExpected status");

		//if(cbs.onAdvEnable)
		//	cbs.onAdvEnable(0);
	}

	hci_close_dev(dd);
	return 0;

done:
//	if(cbs.onAdvEnable)
//		cbs.onAdvEnable(1);
	hci_close_dev(dd);
	return -1;
}

int setAdvData(int flag,char *ble_name,char *uuid)
{
	int dd;
	uint8_t manuf_len;
	uint16_t ogf, ocf;
	int index;
	char advdata[32] = { 0 };

//    CHAR manufacturer_data[MANUFACTURER_DATA_LEN + WIFI_LEN]=
//   {
//        0x54,0x4d,0x5f,0x47,0x45,0x4e,0x49,0x45,0,0,0,0,0,0
//    };//"TMALL_GENIE";

	dd = hci_open_dev(0);
	if (dd < 0) {
		pr_error("Could not open device");
		return -1;
	}


//#define AD_LEN_MANUF	16
#define AD_LEN_FLAG		3
//#define AD_LEN_APPEARANCE	4
//#define AD_LEN_LIST_OF_UUID	4
#define AD_LEN_LOCAL_NAME	10

	index = 1;
//	manuf_len = 1 + 14;
//	advdata[index] = manuf_len;	/* manuf len */
//	advdata[index + 1] = 0xff;		/* ad type */
//	memcpy(advdata + 3, manufacturer_data, MANUFACTURER_DATA_LEN + WIFI_LEN);

//	index += AD_LEN_MANUF;
	advdata[index] = 2;			/* flag len */
	advdata[index + 1] = 0x01;		/* type for flag */
	advdata[index + 2] = flag;  //0x05

//	index += AD_LEN_FLAG;
//	advdata[index] = 3;				/* appearance len */
//	advdata[index + 1] = 0x19;		/* type for appearance */
//	advdata[index + 2] = 0x01;
//	advdata[index + 3] = 0x00;

//	index += AD_LEN_APPEARANCE;
//	advdata[index] = 0x03;			/* uuid len */
//	advdata[index + 1] = 0x03;		/* type for complete list of 16-bit uuid */
//	advdata[index + 2] = 0x20;
//	advdata[index + 3] = 0x9e;

//	index += AD_LEN_LIST_OF_UUID;
	index += AD_LEN_FLAG;
	advdata[index] = 0x0A;			/* uuid len */
	advdata[index + 1] = 0x09;		/* type for local name */
	index+=2;
	int i,name_len;
	name_len = strlen(ble_name);
	for(i=0;i<=name_len;i++) {
		advdata[index + i] = ble_name[i];
	}
//	advdata[index + 2] = 0x50;
//	advdata[index + 3] = 0x65;
//	advdata[index + 4] = 0x64;
//	advdata[index + 5] = 0x6F;
//	advdata[index + 6] = 0x6D;
//	advdata[index + 7] = 0x65;
//	advdata[index + 8] = 0x75;
//	advdata[index + 9] = 0x65;
//	advdata[index + 10] = 0x72;

	// total length
//	advdata[0] = AD_LEN_MANUF + AD_LEN_FLAG + AD_LEN_APPEARANCE	+ AD_LEN_LIST_OF_UUID + AD_LEN_LOCAL_NAME;
	advdata[0] = AD_LEN_FLAG + (name_len + 2);
	hex_dump("  ", 8, (unsigned char *)advdata , 32); fflush(stdout);

	ogf = 0x0008; ocf = 0x0008;
	if (hci_send_cmd(dd, ogf, ocf, 32, advdata) < 0) {
		pr_info("Send failed");
		return -2;
	}

	hci_close_dev(dd);
	return 0;
}

int aw_enable_adv(bool enable)
{
	struct hci_request rq;
	le_set_advertising_parameters_cp adv_params_cp;
	le_set_advertise_enable_cp advertise_cp;
	uint8_t status;
	int dd, ret;
	int hdev = 0;
	char *opt = NULL;

	dd = hci_open_dev(hdev);

	if (dd < 0) {
		pr_error("Could not open device");
		return -1;
	}

	memset(&adv_params_cp, 0, sizeof(adv_params_cp));
	adv_params_cp.min_interval = htobs(0x01E0);
	adv_params_cp.max_interval = htobs(0x01E0);
	adv_params_cp.own_bdaddr_type = LE_PUBLIC_ADDRESS;
	adv_params_cp.advtype = 0; /*ADV_IND*/
	adv_params_cp.chan_map = 7;
	adv_params_cp.filter = 0;

	memset(&rq, 0, sizeof(rq));
	rq.ogf = OGF_LE_CTL;
	rq.ocf = OCF_LE_SET_ADVERTISING_PARAMETERS;
	rq.cparam = &adv_params_cp;
	rq.clen = LE_SET_ADVERTISING_PARAMETERS_CP_SIZE;
	rq.rparam = &status;
	rq.rlen = 1;

	ret = hci_send_req(dd, &rq, 1000);
	if (ret < 0)
		goto done;

	memset(&advertise_cp, 0, sizeof(advertise_cp));
	if (enable)
		advertise_cp.enable = (uint8_t)1;
	else
		advertise_cp.enable = (uint8_t)0;

	memset(&rq, 0, sizeof(rq));
	rq.ogf = OGF_LE_CTL;
	rq.ocf = OCF_LE_SET_ADVERTISE_ENABLE;
	rq.cparam = &advertise_cp;
	rq.clen = LE_SET_ADVERTISE_ENABLE_CP_SIZE;
	rq.rparam = &status;
	rq.rlen = 1;

	ret = hci_send_req(dd, &rq, 1000);
	if (ret < 0) {
		pr_error("cannot send enable advertising");
		goto done;
	} else {
		if(status == 0)
			pr_info("set adv enable");
		else if (status == 12)
			pr_info("likely already advertising...");
		else
			pr_info("UnExpected status");

		//if(cbs.onAdvEnable)
		//	cbs.onAdvEnable(0);
	}

	hci_close_dev(dd);
	return 0;

done:
//	if(cbs.onAdvEnable)
//		cbs.onAdvEnable(1);
	hci_close_dev(dd);
	return -1;
}

int aw_set_adv_ind_data(aw_adv_data_t *adv_data)
{
	int dd;
	uint8_t manuf_len;
	uint16_t ogf, ocf;
	int index;
	char advdata[32] = { 0 };

	dd = hci_open_dev(0);
	if (dd < 0) {
		pr_error("Could not open device");
		return -1;
	}

	advdata[0] = adv_data->data_len;
	memcpy(&advdata[1], adv_data->data, adv_data->data_len);

	ogf = 0x0008; ocf = 0x0008;
	if (hci_send_cmd(dd, ogf, ocf, 32, advdata) < 0) {
		pr_info("Send failed");
		return -2;
	}

	hci_close_dev(dd);
	return 0;
}

int aw_set_rsp_data(aw_rsp_data_t *rsp_data)
{
	int dd;
	uint8_t manuf_len;
	uint16_t ogf, ocf;
	int index;
	char rspdata[32] = { 0 };

	dd = hci_open_dev(0);
	if (dd < 0) {
		pr_error("Could not open device");
		return -1;
	}

	rspdata[0] = rsp_data->data_len;
	memcpy(&rspdata[1], rsp_data->data, rsp_data->data_len);

	ogf = 0x0008; ocf = 0x0009;
	if (hci_send_cmd(dd, ogf, ocf, 32, rspdata) < 0) {
		pr_info("Send failed");
		return -2;
	}

	hci_close_dev(dd);
	return 0;
}
