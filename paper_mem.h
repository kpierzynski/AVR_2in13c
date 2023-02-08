#ifndef __PAPER_MEM_H_
#define __PAPER_MEM_H_

#define PANEL_SETTING_CMD 0x00
#define POWER_SETTING_CMD 0x01
#define POWER_OFF_CMD 0x02
#define POWER_OFF_SEQUENCE_SETTING_CMD 0x03
#define POWER_ON_CMD 0x04
#define POWER_MEASURE_CMD 0x05
#define BOOSTER_SOFT_START_CMD 0x06
#define DEEP_SLEEP_CMD 0x07
#define DISPLAY_START_TRANSMISSION1_CMD 0x10
#define DATA_STOP_CMD 0x11
#define DISPLAY_REFRESH_CMD 0x12
#define DISPLAY_START_TRANSMISSION2_CMD 0x13
#define VCOM_LUT_CMD 0x20
#define W2W_LUT_CMD 0x21
#define B2W_LUT_CMD 0x22
#define W2B_LUT_CMD 0x23
#define B2B_LUT_CMD 0x24
#define PLL_CONTROL_CMD 0x30
#define TEMPERATURE_SENSOR_CALIBRATION_CMD 0x40
#define TEMPERATURE_SENSOR_SELECTION_CMD 0x41
#define TEMPERATURE_SENSOR_WRITE_CMD 0x42
#define TEMPERATURE_SENSOR_READ_CMD 0x43
#define VCOM_AND_DATA_INVERVAL_SETTING_CMD 0x50
#define LOWER_POWER_DETECTION_CMD 0x51
#define TCON_SETTING_CMD 0x60
#define RESOLUTION_SETTING_CMD 0x61
#define GET_STATUS_CMD 0x71
#define AUTO_MEASUREMENT_VCOM_CMD 0x80
#define READ_VCOM_VALUE_CMD 0x81
#define VCM_DC_SETTING_CMD 0x82
#define PARTIAL_WINDOW_CMD 0x90
#define PARTIAL_IN_CMD 0x91
#define PARTIAL_OUT_CMD 0x92
#define PROGRAM_MODE_CMD 0xA0
#define ACTIVE_PROGRAMMING_CMD 0xA1
#define READ_OTP_CMD 0xA2
#define POWER_SAVING_CMD 0xE3

#endif