//
// Created by insmtr on 24-10-14.
//

#include "laser.h"
#include "i2c.h"
#include "main.h"

void laser_start()
{
    HAL_I2C_Mem_Write(&hi2c1, VL53L0X_ADDRESS << 1, SYSRANGE_START, I2C_MEMADD_SIZE_8BIT, &back_to_back, 1,
                      HAL_MAX_DELAY);
}

void laser_stop()
{
    HAL_I2C_Mem_Write(&hi2c1, VL53L0X_ADDRESS << 1, SYSRANGE_START, I2C_MEMADD_SIZE_8BIT, &single_shot, 1,
                      HAL_MAX_DELAY);
}

void laser_measure()
{
    HAL_I2C_Mem_Read(&hi2c1, VL53L0X_ADDRESS << 1 | 1, RESULT_RANGE_STATUS, I2C_MEMADD_SIZE_8BIT, result, 12,
                     HAL_MAX_DELAY);
    uint16_t new_distance = result[10] << 8 | result[11];
    if (new_distance == 20)
        return;
    distance = new_distance - 50;
}
