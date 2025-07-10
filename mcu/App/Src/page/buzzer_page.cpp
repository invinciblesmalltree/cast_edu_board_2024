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

#include "page/buzzer_page.h"
#include "assert/songs.h"
#include "buzzer.h"
#include "oled.h"
#include "page/buzzer_menu_page.h"
buzzer_page buzzer_page_instance;

void buzzer_page::update_ui()
{
    u8g2_ClearBuffer(&screen);
    u8g2_SetFont(&screen, u8g2_font_wqy14_t_gb2312_lite);
    uint8_t start_x = u8g2_GetUTF8Width(&screen, songs[this->song_id].name);
    u8g2_DrawUTF8(&screen, u8g2_GetDisplayWidth(&screen) - start_x >> 1, 14, songs[this->song_id].name);
    u8g2_SetFont(&screen, u8g2_font_wqy12_t_gb2312_lite);
    u8g2_DrawUTF8(&screen, 14, 37, "按下 OK 开始播放");
    u8g2_DrawUTF8(&screen, 14, 51, "旋转以退出");
    u8g2_SendBuffer(&screen);
}

void buzzer_page::enter()
{
}

void buzzer_page::leave()
{
    buzzer_start_play(nullptr, 0);
}

buzzer_page::buzzer_page()
{
    this->key_handlers[KEY_OK].on_pressed = [this](key_state) {
        buzzer_start_play(songs[this->song_id].tones, songs[this->song_id].tone_count);
    };
    this->key_handlers[KEY_X0Y0].on_pressed = [](key_state) { route_to(&buzzer_menu_page_instance); };
    this->key_handlers[KEY_X2Y0].on_pressed = [this](key_state) {
        buzzer_start_play(songs[this->song_id].tones, songs[this->song_id].tone_count);
    };
    this->key_handlers[USER_KEY_1].on_pressed = [](key_state) { route_to(&buzzer_menu_page_instance); };
    this->key_handlers[USER_KEY_2].on_pressed = [this](key_state) {
        buzzer_start_play(songs[this->song_id].tones, songs[this->song_id].tone_count);
    };
}

void buzzer_page::on_encoder_changed(int32_t diff)
{
    route_to(&buzzer_menu_page_instance);
}
