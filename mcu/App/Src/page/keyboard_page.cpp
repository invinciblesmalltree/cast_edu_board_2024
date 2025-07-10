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

#include "page/keyboard_page.h"
#include "oled.h"
#include "page/main_menu_page.h"
keyboard_page keyboard_page_instance;

void draw_keyboard_state(key_state state, u8g2_uint_t x, u8g2_uint_t y)
{
    if (state == key_state::released)
    {
        u8g2_DrawFrame(&screen, x + 1, y + 1, 14, 14);
    }
    else
    {
        u8g2_DrawBox(&screen, x + 1, y + 1, 14, 14);
    }
}

void keyboard_page::update_ui()
{
    key_state key_states[KEY_COUNT];
    get_key_states(key_states);

    u8g2_ClearBuffer(&screen);
    draw_keyboard_state(key_states[KEY_OK], 0, 0);
    draw_keyboard_state(key_states[USER_KEY_1], 0, 16);
    draw_keyboard_state(key_states[USER_KEY_2], 0, 32);

    u8g2_SetFont(&screen, u8g2_font_6x13_tf);
    u8g2_DrawStr(&screen, 18, 13, "OK");
    u8g2_DrawStr(&screen, 18, 29, "Key1");
    u8g2_DrawStr(&screen, 18, 45, "Key2");
    u8g2_SetFont(&screen, u8g2_font_wqy12_t_gb2312_lite);
    u8g2_DrawUTF8(&screen, 0, 61, "矩阵键盘");

    // Arrow -->
    u8g2_DrawLine(&screen, 49, 57, 61, 57);
    u8g2_DrawLine(&screen, 61, 57, 57, 53);
    u8g2_DrawLine(&screen, 61, 57, 57, 61);

    auto offset_matrix_key = 64;
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            draw_keyboard_state(key_states[KEY_X0Y3 - r * 4 + c], offset_matrix_key + c * 16, r * 16);
        }
    }

    u8g2_SendBuffer(&screen);
}

void keyboard_page::on_encoder_changed(int32_t diff)
{
    route_to(&main_menu_page_instance);
}
