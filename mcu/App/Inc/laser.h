//
// Created by insmtr on 24-10-14.
//

#pragma once
#include "page/laser_page.h"

void laser_start();
void laser_stop();
void laser_measure();
inline uint8_t result[12]{};
inline uint16_t distance = 0;
inline char dis_msg[20]{};
constexpr uint8_t VL53L0X_ADDRESS = 0x29;
constexpr uint8_t SYSRANGE_START = 0x00;
constexpr uint8_t RESULT_RANGE_STATUS = 0x14;
inline uint8_t single_shot = 0x00;
inline uint8_t back_to_back = 0x02;
