// Copyright (C) 2024 ArcticLampyrid <alampy.com>
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by insmtr on 24-9-16.
//

#include "page/dino_page.h"
#include "assert/dino_images.h"
#include "dino_logic.h"
#include "main.h"
#include "oled.h"
#include "page/dino_game_over_page.h"
#include "page/main_menu_page.h"
dino_page dino_page_instance;
using namespace dino;

char score[8];

dino_page::dino_page() : rand_engine(HAL_GetTick())
{
    for (uint8_t i = 0; i < 16; i++)
        this->key_handlers[USER_KEY_1 + i].on_pressed = [this](key_state state) { logic.jump(); };
    this->key_handlers[KEY_OK].on_pressed = [this](key_state state) { logic.abort_game(); };
}

void dino_page::update_ui()
{
    u8g2_ClearBuffer(&screen);
    u8g2_SetDrawColor(&screen, 1);
    u8g2_SetBitmapMode(&screen, 1);
    u8g2_DrawBox(&screen, 0, 60, 128, 2);
    const cactus_info_t *cactus = logic.front_cactus_info;
    double accumulated_distance = 0;
    for (uint8_t i = 0; i < 3; i++)
    {
        cactus_type type = cactus->type;
        if (accumulated_distance > 128)
            break;
        u8g2_DrawXBM(&screen, static_cast<int16_t>(accumulated_distance += cactus->distance),
                     60 - cactus_pic[type].height, cactus_pic[type].width, cactus_pic[type].height,
                     cactus_pic[type].image);
        cactus = cactus->next;
    }
    u8g2_DrawXBM(&screen, static_cast<int16_t>(logic.cloud_distance), 10, cloud_pic.width, cloud_pic.height,
    cloud_pic.image);
    u8g2_DrawXBM(&screen, 30, 60 - dino_pic.height - logic.get_jump_height(), dino_pic.width, dino_pic.height,
                 dino_pic.image);
    u8g2_SetFont(&screen, u8g2_font_wqy14_t_gb2312_lite);
    sprintf(score, "%06d", logic.get_score());
    u8g2_DrawStr(&screen, 78, 14, score);
    u8g2_SendBuffer(&screen);
}

void dino_page::enter()
{
    logic.reset();

    logic.on_game_over = [this](const game_over_reason_t reason) {
        dino_game_over_page_instance.reason = reason;
        dino_game_over_page_instance.set_score(logic.get_score());
        route_to(&dino_game_over_page_instance);
    };
}

void dino_page::leave()
{
    logic.on_game_over = nullptr;
}

void dino_page::tick()
{
    logic.update_velocity();
    logic.front_cactus_info->distance -= logic.velocity;
    if (logic.front_cactus_info->distance + cactus_pic[logic.front_cactus_info->type].width < 0)
    {
        logic.front_cactus_info->next->distance += logic.front_cactus_info->distance;
        logic.create_cactus();
    }
    logic.cloud_distance -= logic.velocity;
    if (logic.cloud_distance < -23)
    {
        std::uniform_int_distribution dist(192, 384);
        logic.cloud_distance += dist(rand_engine) + 23;
    }
    if (logic.is_crashed())
    {
        logic.on_game_over.trigger(game_over_reason_t::hit_cactus);
    }
}

void dino_page::on_encoder_changed(int32_t diff)
{
    logic.abort_game();
}
