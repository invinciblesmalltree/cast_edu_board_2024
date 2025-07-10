//
// Created by insmtr on 24-10-18.
//

#pragma once
#include <cstdint>
struct image_info
{
    uint8_t width;
    uint8_t height;
    const uint8_t *image;
};
extern image_info dino_pic;
extern image_info cactus_pic[];
extern image_info cloud_pic;
