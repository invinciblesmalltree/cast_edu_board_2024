//
// Created by insmtr on 24-10-16.
//

#include "page/instrument_page.h"
#include "assert/songs.h"
#include "buzzer.h"
#include "oled.h"
#include "page/buzzer_menu_page.h"
instrument_page instrument_page_instance;

instrument_page::instrument_page()
{
    this->key_handlers[KEY_OK].on_pressed = [this](key_state state) { buzzer_start_play(single_tone + 18, 1); };
    this->key_handlers[KEY_OK].on_released = [this](key_state state) { buzzer_start_play(nullptr, 0); };
    for (uint8_t i = 0; i <= 17; i++)
    {
        this->key_handlers[USER_KEY_1 + i].on_pressed = [this, i](key_state state) {
            buzzer_start_play(single_tone + i, 1);
        };
        this->key_handlers[USER_KEY_1 + i].on_released = [this](key_state state) { buzzer_start_play(nullptr, 0); };
    }
}

void instrument_page::update_ui()
{
    u8g2_ClearBuffer(&screen);
    u8g2_SetFont(&screen, u8g2_font_wqy14_t_gb2312_lite);
    u8g2_DrawUTF8(&screen, 36, 14, "自由演奏");
    u8g2_SetFont(&screen, u8g2_font_wqy12_t_gb2312_lite);
    u8g2_DrawUTF8(&screen, 4, 37, "按下矩阵键盘开始演奏");
    u8g2_DrawUTF8(&screen, 4, 51, "旋转以退出");
    u8g2_SendBuffer(&screen);
}

void instrument_page::enter()
{
}

void instrument_page::leave()
{
    buzzer_start_play(nullptr, 0);
}

void instrument_page::on_encoder_changed(int32_t diff)
{
    route_to(&buzzer_menu_page_instance);
}
