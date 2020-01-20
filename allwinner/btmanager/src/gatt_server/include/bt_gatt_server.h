/*
  * Copyright (c) 2019 Allwinner Technology. All Rights Reserved.
  * Author        laumy <liumingyuan@allwinnertech.com>
  * Version       0.0.1
  *
  */

#ifndef __BT_GATT_SERVER_H
#define __BT_GATT_SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef enum {
	BT_GATT_CHAR_PROPERTY_BROADCAST = 0x01,
	BT_GATT_CHAR_PROPERTY_READ = 0x02,
	BT_GATT_CHAR_PROPERTY_WRITE_NO_RESPONSE = 0x04,
	BT_GATT_CHAR_PROPERTY_WRITE = 0x08,
	BT_GATT_CHAR_PROPERTY_NOTIFY = 0x10,
	BT_GATT_CHAR_PROPERTY_INDICATE = 0x20,
	BT_GATT_CHAR_PROPERTY_AUTH_SIGNED_WRITE = 0x40
}tGattCharProperties;

typedef enum {
	BT_GATT_DESC_PROPERTY_BROADCAST = 0x01,
	BT_GATT_DESC_PROPERTY_READ = 0x02,
	BT_GATT_DESC_PROPERTY_WRITE_NO_RESPONSE = 0x04,
	BT_GATT_DESC_PROPERTY_WRITE = 0x08,
	BT_GATT_DESC_PROPERTY_NOTIFY = 0x10,
	BT_GATT_DESC_PROPERTY_INDICATE = 0x20,
	BT_GATT_DESC_PROPERTY_AUTH_SIGNED_WRITE = 0x40
}tGattDescProperties;

typedef enum {
	BT_GATT_PERM_READ = 0x01,
	BT_GATT_PERM_WRITE = 0x02,
	BT_GATT_PERM_READ_ENCYPT = 0x04,
	BT_GATT_PERM_WRITE_ENCRYPT = 0x08,
	BT_GATT_PERM_ENCRYPT = 0x04 | 0x08,
	BT_GATT_PERM_READ_AUTHEN = 0x10,
	BT_GATT_PERM_WRITE_AUTHEN = 0x20,
	BT_GATT_PERM_AUTHEN = 0x10 | 0x20,
	BT_GATT_PERM_AUTHOR = 0x40,
	BT_GATT_PERM_NONE = 0x80
}tGattPermissions;

typedef enum {
	BT_GATT_CONNECTION,
	BT_GATT_DISCONNECT,
}tGattConnectionEvent;

typedef struct {
	int svc_handle;
}tGattAddSvcMsg;

typedef struct {
	char *uuid;
	int char_handle;
}tGattAddCharMsg;

typedef struct {
	int desc_handle;
}tGattAddDescMsg;

typedef void (*BtGattAddServiceCb)(tGattAddSvcMsg *pData);
typedef void (*BtGattAddCharCb)(tGattAddCharMsg *pData);
typedef void (*BtGattAddDescCb)(tGattAddDescMsg *pData);
typedef void (*BtGattSeviceReadyCb)(int state);
typedef void (*BtGattConnectionEventCb)(tGattConnectionEvent event);

typedef struct {
	int trans_id;
	int attr_handle;
	int offset;
	bool is_blog_req;
}tGattCharReadReq;

#define AG_GATT_MAX_ATTR_LEN 600

typedef struct {
	int trans_id;
	int attr_handle;
	int offset;
	char value[AG_GATT_MAX_ATTR_LEN];
	int value_len;
	bool need_rsp;
}tGattCharWriteReq;

typedef struct {
	bool state;
}tGattNotifyReq;

typedef struct {
	int trans_id;
	int attr_handle;
	int offset;
	bool is_blog_req;
}tGattDescReadReq;

typedef struct {
	int trans_id;
	int attr_handle;
	int offset;
	char value[AG_GATT_MAX_ATTR_LEN];
	int value_len;
	bool need_rsp;
}tGattDescWriteReq;

typedef struct {

}tGattSendIndication;

typedef void (*BtGattCharReadReqCb)(tGattCharReadReq *char_read);
typedef void (*BtGattCharWriteReqCb)(tGattCharWriteReq *char_write);
typedef void (*BtGattCharNotifyReqCb)(tGattDescReadReq *char_notify);

typedef void (*BtGattDescReadReqCb)(tGattDescReadReq *desc_read);
typedef void (*BtGattDescWriteReqCb)(tGattDescWriteReq *desc_write);

typedef void (*BtGattSendIndicationCb)(tGattSendIndication *send_ind);

typedef struct {

/*gatt add ... callback*/
	BtGattAddServiceCb GattAddSvcCb;
	BtGattAddCharCb GattAddCharCb;
	BtGattAddDescCb GattAddDescCb;

/*gatt event callback*/
	BtGattConnectionEventCb GattConnectionEventcb;

	BtGattSeviceReadyCb GattServiceReadyCb;

/*gatt characteristic request callback*/
	BtGattCharReadReqCb GattCharReadReqCb;
	BtGattCharWriteReqCb GattCharWriteReqCb;
	BtGattCharNotifyReqCb GattCharNotifyReqCb;

/*gatt descriptor request callback*/
	BtGattDescReadReqCb GattDescReadReqCb;
	BtGattDescWriteReqCb GattDescWriteReqCb;

	BtGattSendIndicationCb GattSendIndicationCb;
}tGattServerCb;


typedef struct {
	char *uuid;      /*128-bit service UUID*/
	bool primary;    /* If true, this GATT service is a primary service */
	int number;
}tGattAddSvc;

typedef struct {
	char *uuid;      /*128-bit characteristic UUID*/
	int properties;        /*The GATT characteristic properties*/
	int permissions;       /*The GATT characteristic permissions*/
	int svc_handle;          /*the service atr handle*/
}tGattAddChar;

typedef struct {
	char *uuid;     /*128-bit descriptor UUID*/
	int properties;       /*The GATT descriptor properties*/
	int permissions;      /*he GATT descriptor  permissions*/
	int svc_handle;
}tGattAddDesc;

typedef struct {
	int svc_handle;
}tGattStarSvc;

typedef struct {
	int svc_handle;
}tGattStopSvc;

typedef struct {
	int svc_handle;
}tGattDelSvc;

typedef struct {
	int trans_id;
	int status;
	int svc_handle;
	char *value;
	int value_len;
	int auth_req;
}tGattSendReadRsp;

typedef enum {
	BT_GATT_REQ_FAILED,
	BT_GATT_REQ_IN_PROGRESS,
	BT_GATT_REQ_PERMITTED,
	BT_GATT_REQ_INVAILD_VALUE_LENGTH,
	BT_GATT_REQ_NOT_AUTHORIZED,
	BT_GATT_REQ_NOT_SUPPORT
}tGattState;

typedef struct {
	tGattState state;
}tGattWriteRsp;

typedef struct {
	int attr_handle;
	char *value;
	int value_len;
}tGattNotifyRsp;

typedef struct {
	int attr_handle;
	char *value;
	int value_len;
}tGattIndicationRsp;

int bt_gatt_create_server(tGattAddSvc *svc);

int bt_gatt_add_characteristic(tGattAddChar *chr);

int bt_gatt_add_descriptor(tGattAddDesc *desc);


int bt_gatt_start_service(tGattStarSvc *start_svc);

int bt_gatt_stop_service(tGattStopSvc *stop_svc);


int bt_gatt_delete_service(tGattDelSvc *del_svc);


int bt_gatt_send_read_response(tGattSendReadRsp *pData);

int bt_gatt_send_write_response(tGattWriteRsp *pData);

int bt_gatt_send_notification(tGattNotifyRsp *pData);

int bt_gatt_send_indication(tGattIndicationRsp *pData);


int bt_gatt_server_init(tGattServerCb *cb);

int bt_gatt_server_deinit();

int bt_gatt_server_disconnect(unsigned int handle, unsigned char reason);

int bt_gatt_server_clear_white_list();


extern tGattServerCb *gatt_server_cb;

#ifdef __cplusplus
}
#endif

#endif
