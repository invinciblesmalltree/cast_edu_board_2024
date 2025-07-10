//
// Created by insmtr on 24-10-24.
//

#pragma once
#include <cstdint>

namespace video
{
extern uint8_t video_bit[];
uint8_t next_bit(); // make the return value a bool, not an int.
} // namespace video
