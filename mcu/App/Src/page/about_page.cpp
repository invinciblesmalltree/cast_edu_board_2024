// Copyright (C) 2023 ArcticLampyrid <alampy.com>
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

#include "page/about_page.h"
#include "assert/about_bottom_banner.h"
#include "oled.h"
#include "page/main_menu_page.h"
#include <cmath>
about_page about_page_instance;

about_page::about_page()
{
    // for (auto &key_handler: this->key_handlers) {
    //     key_handler.on_pressed = [this](key_state) {
    //         route_to(&main_menu_page_instance);
    //     };
    // }

    this->key_handlers[KEY_OK].on_pressed = [this](key_state) { route_to(&main_menu_page_instance); };
    this->key_handlers[KEY_X1Y1].on_pressed = [this](key_state) { this->on_encoder_changed(-4); };
    this->key_handlers[KEY_X1Y0].on_pressed = [this](key_state) { this->on_encoder_changed(4); };
    this->key_handlers[KEY_X0Y0].on_pressed = [this](key_state) { route_to(&main_menu_page_instance); };
    this->key_handlers[KEY_X2Y0].on_pressed = [this](key_state) { this->scroll_to_top(); };
    this->key_handlers[USER_KEY_1].on_pressed = [this](key_state) { route_to(&main_menu_page_instance); };
    this->key_handlers[USER_KEY_2].on_pressed = [this](key_state) { this->scroll_to_top(); };
}

void about_page::update_ui()
{
    auto y = std::lround(top_y.value());
    if (top_y.is_done())
    {
        if (y < 0)
        {
            top_y.transition(0, 250);
        }
        else if (y > 175)
        {
            top_y.transition(175, 250);
        }
    }
    u8g2_ClearBuffer(&screen);
    u8g2_SetFont(&screen, u8g2_font_wqy14_t_gb2312_lite);
    static const char *lines[] = {
        "作者:",          "    硬件:  王冕",     "    固件:",    "        极地萤火", "            @alampy",
        "        束洋帆", "            @insmtr", "        李亮", "        曾长治",   "版本:",
        "    v2024.10.19"};
    constexpr auto n_lines = std::size(lines);
    u8g2_DrawUTF8(&screen, 46, 14 - y, "关于");

    for (int i = 0; i < n_lines; i++)
    {
        u8g2_DrawUTF8(&screen, 0, 28 + i * 14 - y, lines[i]);
    }

    u8g2_DrawXBM(&screen, u8g2_GetDisplayWidth(&screen) - about_bottom_banner_width >> 1, 180 - y,
                 about_bottom_banner_width, about_bottom_banner_height, about_bottom_banner);

    u8g2_SendBuffer(&screen);

    top_y.update();
}

void about_page::enter()
{
    top_y.set(0);
}

void about_page::leave()
{
}

void about_page::scroll_to_top()
{
    top_y.transition(-16, 520);
}

void about_page::on_encoder_changed(int32_t diff)
{
    auto end_value = top_y.end_value() + (float)diff * 16;
    top_y.transition(end_value, 520);
}
