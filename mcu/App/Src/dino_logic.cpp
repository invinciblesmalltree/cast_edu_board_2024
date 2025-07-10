//
// Created by insmtr on 24-10-17.
//

#include "dino_logic.h"
#include "assert/dino_images.h"
#include "main.h"
#include <random>

using namespace dino;

dino_logic_t::dino_logic_t() noexcept : rand_engine(HAL_GetTick())
{
    cactus_info[0].next = &cactus_info[1];
    cactus_info[1].next = &cactus_info[2];
    cactus_info[2].next = &cactus_info[0];
    front_cactus_info = &cactus_info[0];
    create_cactus();
    create_cactus();
    create_cactus();
    front_cactus_info->distance += 96;
}

void dino_logic_t::reset() noexcept
{
    this->~dino_logic_t();
    new (this) dino_logic_t();
}

uint8_t dino_logic_t::is_crashed() // 是否撞到仙人掌
{
    const uint8_t jump_height = get_jump_height();
    const cactus_info_t *current_cactus = get_closest_cactus_info();
    return jump_height + 4 < cactus_pic[current_cactus->type].height &&
           34 < current_cactus->distance + cactus_pic[current_cactus->type].width &&
           current_cactus->distance < 26 + dino_pic.width;
}

uint8_t dino_logic_t::get_jump_height() const noexcept // 当前的 y 坐标值，相对于地面
{
    const uint32_t time = HAL_GetTick() - take_off_time;
    return time < 500 ? -time * (time - 500) / 1800 : 0;
}

void dino_logic_t::jump() noexcept
{
    if (start_time == 0)
    {
        start_time = HAL_GetTick();
    }
    const uint32_t now = HAL_GetTick();
    if (now - take_off_time < 500)
    {
        return;
    }
    this->take_off_time = now;
}

void dino_logic_t::update_velocity() noexcept
{
    if (start_time)
    {
        velocity = 0.75 * (1.0 - exp(-((HAL_GetTick() - start_time + 64000) / 64000.0)));
    }
}

void dino_logic_t::create_cactus() noexcept
{
    std::uniform_int_distribution dist(static_cast<int>(120 + 250 * velocity), static_cast<int>(200 + 500 * velocity));
    front_cactus_info->distance = dist(rand_engine);
    std::uniform_int_distribution cactus_type_dist(0, 2);
    front_cactus_info->type = static_cast<cactus_type>(cactus_type_dist(rand_engine));
    front_cactus_info = front_cactus_info->next;
}

cactus_info_t *dino_logic_t::get_closest_cactus_info() noexcept
{
    double min_distance = 1000.0;
    uint8_t min_cactus_index = 0;
    for (uint8_t i = 0; i < 3; i++)
    {
        if (cactus_info[i].distance < 0)
        {
            continue;
        }
        if (cactus_info[i].distance < min_distance)
        {
            min_distance = cactus_info[i].distance;
            min_cactus_index = i;
        }
    }
    return &cactus_info[min_cactus_index];
}

uint32_t dino_logic_t::get_score() const noexcept
{
    return start_time ? HAL_GetTick() - start_time >> 7 : 0;
}

void dino_logic_t::abort_game() const noexcept
{
    on_game_over.trigger(game_over_reason_t::aborted);
}
