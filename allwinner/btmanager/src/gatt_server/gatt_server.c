/*
  * Copyright (c) 2019 Allwinner Technology. All Rights Reserved.
  * Author        laumy <liumingyuan@allwinnertech.com>
  * Version       0.0.1
  *
  */

#include <stdio.h>
#include <stdlib.h>

#include <lib/bluetooth.h>
#include <lib/hci.h>
#include <lib/hci_lib.h>

#include "bt_gatt_server.h"
#include "gatt_server_glue.h"

#define BLE_CONF "/etc/bluetooth/bt_init.sh ble_start"

tGattServerCb *gatt_server_cb = NULL;

int bt_gatt_server_init(tGattServerCb *cb)
{
	system(BLE_CONF);
	gatt_server_cb = cb;
	return CSM_init();
}

tGattServerCb *bt_get_gatt_server_cb()
{
	return gatt_server_cb;
}

int bt_gatt_create_server(tGattAddSvc *svc)
{
	return CSM_addService(svc->uuid,svc->primary,svc->number);
}

int bt_gatt_add_characteristic(tGattAddChar *chr)
{
	return CSM_addChar(chr->svc_handle,chr->uuid,chr->properties,
			chr->permissions);
}

int bt_gatt_add_descriptor(tGattAddDesc *desc)
{
	return CSM_addDesc(desc->svc_handle,desc->uuid,desc->permissions);
}

int bt_gatt_start_service(tGattStarSvc *start_svc)
{
	return CSM_startService(start_svc->svc_handle);
}

int bt_gatt_stop_service(tGattStopSvc *stop_svc)
{
	return CSM_stopService(stop_svc->svc_handle);
}

int bt_gatt_delete_service(tGattDelSvc *del_svc)
{
	return CSM_deleteService(del_svc->svc_handle);
}

int bt_gatt_send_read_response(tGattSendReadRsp *pData)
{
	CSM_sendResponse(pData->trans_id,pData->status,pData->svc_handle,
			pData->value,pData->value_len,pData->auth_req);
}

int bt_gatt_send_write_response(tGattWriteRsp *pData)
{
	;
	//TODO
}

int bt_gatt_send_notification(tGattNotifyRsp *pData)
{
	return CSM_sendIndication(pData->attr_handle,false,
			pData->value,pData->value_len);
}

int bt_gatt_send_indication(tGattIndicationRsp *pData)
{
	return CSM_sendIndication(pData->attr_handle,true,
			pData->value,pData->value_len);
}


int bt_gatt_server_deinit()
{
	return CSM_deinitGatts();
}

int bt_gatt_server_disconnect(unsigned int handle, unsigned char reason)
{
	struct hci_request rq;
	disconnect_cp disconnect_params_cp;
	uint8_t status;
	int dd, ret;
	int hdev = 0;

	dd = hci_open_dev(hdev);

	if (dd < 0) {
		printf("%s:%d Could not open device\n", __func__, __LINE__);
		return -1;
	}

	memset(&disconnect_params_cp, 0, sizeof(disconnect_params_cp));
	disconnect_params_cp.handle = handle; /*0x0200*/
	disconnect_params_cp.reason = reason; /*#define 	HCI_ERROR_CODE_REMOTE_USER_TERM_CONN   0x13*/

	memset(&rq, 0, sizeof(rq));
	rq.ogf = OGF_LINK_CTL;
	rq.ocf = OCF_DISCONNECT;
	rq.cparam = &disconnect_params_cp;
	rq.clen = DISCONNECT_CP_SIZE;
	rq.rparam = &status;
	rq.rlen = 1;

	ret = hci_send_req(dd, &rq, 1000);
	if (ret < 0)
		goto done;

done:
	hci_close_dev(dd);
	return -1;
}

int bt_gatt_server_clear_white_list()
{
	struct hci_request rq;
	uint8_t status;
	int dd, ret;
	int hdev = 0;

	dd = hci_open_dev(hdev);

	if (dd < 0) {
		printf("%s:%d Could not open device\n", __func__, __LINE__);
		return -1;
	}

	memset(&rq, 0, sizeof(rq));
	rq.ogf = OGF_LE_CTL;
	rq.ocf = OCF_LE_CLEAR_WHITE_LIST;
	rq.rparam = &status;
	rq.rlen = 1;

	ret = hci_send_req(dd, &rq, 1000);
	if (ret < 0)
		goto done;

done:
	hci_close_dev(dd);
	return -1;

}
