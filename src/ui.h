#ifndef UI_H_
#define UI_H_

#include "config.h"

extern void ui_indicate_uncalibrated_imu();
extern void ui_indicate_power_off();
extern void ui_indicate_fault_MS5611();
extern void ui_indicate_fault_MPU9250();
extern void ui_indicate_battery_voltage(float batV);
extern void ui_calibrate_accel(CALIB_PARAMS_t &calib);
extern void ui_calibrate_gyro(CALIB_PARAMS_t &calib);
#ifdef USE_9DOF_AHRS
extern void ui_calibrate_accel_gyro_mag();
extern void ui_calibrate_mag(CALIB_PARAMS_t &calib);
#else 
extern void ui_calibrate_accel_gyro();
#endif

extern void ui_button_init(void);
extern bool ui_button_pressed(void);

#endif
