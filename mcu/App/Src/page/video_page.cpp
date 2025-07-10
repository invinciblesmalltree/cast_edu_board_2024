//
// Created by insmtr on 24-11-21.
//

#include "page/video_page.h"
#include "assert/songs.h"
#include "assert/video.h"
#include "buzzer.h"
#include "oled.h"
#include "page/buzzer_menu_page.h"
video_page video_page_instance;

void video_page::update_ui()
{
    u8g2_ClearBuffer(&screen);
    u8g2_SetFont(&screen, u8g2_font_wqy14_t_gb2312_lite);
    uint8_t start_x = u8g2_GetUTF8Width(&screen, songs[this->song_id].name);
    u8g2_DrawUTF8(&screen, u8g2_GetDisplayWidth(&screen) - start_x >> 1, 14, songs[this->song_id].name);
    u8g2_SetFont(&screen, u8g2_font_wqy12_t_gb2312_lite);
    u8g2_DrawUTF8(&screen, 14, 37, "Bad Apple");
    u8g2_DrawUTF8(&screen, 14, 51, "旋转以退出");
    u8g2_SendBuffer(&screen);
}

void video_page::enter()
{
}

void video_page::leave()
{
    buzzer_start_play(nullptr, 0);
}

video_page::video_page()
{
    buzzer_start_play(songs[this->song_id].tones, songs[this->song_id].tone_count);

    this->key_handlers[KEY_OK].on_pressed = [this](key_state) { route_to(&buzzer_menu_page_instance); };
    this->key_handlers[KEY_X0Y0].on_pressed = [](key_state) { route_to(&buzzer_menu_page_instance); };
    this->key_handlers[USER_KEY_1].on_pressed = [](key_state) { route_to(&buzzer_menu_page_instance); };
    this->key_handlers[USER_KEY_2].on_pressed = [this](key_state) {
        buzzer_start_play(songs[this->song_id].tones, songs[this->song_id].tone_count);
    };
}

void video_page::on_encoder_changed(int32_t diff)
{
    route_to(&buzzer_menu_page_instance);
}
