#ifndef BT_ADV_H
#define BT_ADV_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

typedef struct aw_adv_data_t {
	uint8_t data[32];
	uint8_t data_len;
} aw_adv_data_t;

typedef struct aw_rsp_data_t {
	uint8_t data[32];
	uint8_t data_len;
} aw_rsp_data_t;

int enableAdv(bool enable);

int setAdvData(int flag,char *ble_name,char *uuid);

int aw_enable_adv(bool enable);

int aw_set_adv_ind_data(aw_adv_data_t *adv_data);

int aw_set_rsp_data(aw_rsp_data_t *rsp_data);

#ifdef __cplusplus
}
#endif

#endif //AG_GATT_API_H
