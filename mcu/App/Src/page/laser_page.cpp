//
// Created by insmtr on 24-10-12.
//

#include "page/laser_page.h"

#include <cmath>
#include <cstdio>

#include "laser.h"
#include "oled.h"
#include "page/main_menu_page.h"

laser_page laser_page_instance;

laser_page::laser_page()
{
    this->key_handlers[KEY_OK].on_pressed = [](key_state state) { route_to(&main_menu_page_instance); };
    this->key_handlers[KEY_X0Y0].on_pressed = [this](key_state state) { route_to(&main_menu_page_instance); };
    this->key_handlers[KEY_X2Y0].on_pressed = [this](key_state state) { route_to(&main_menu_page_instance); };
    this->key_handlers[USER_KEY_1].on_pressed = [this](key_state state) { route_to(&main_menu_page_instance); };
    this->key_handlers[USER_KEY_2].on_pressed = [this](key_state state) { route_to(&main_menu_page_instance); };
}

void laser_page::update_ui()
{
    laser_measure();
    sprintf(dis_msg, "距离: %d mm", distance);
    u8g2_ClearBuffer(&screen);
    u8g2_SetFont(&screen, u8g2_font_wqy14_t_gb2312_lite);
    u8g2_DrawUTF8(&screen, 36, 14, "激光测距");
    u8g2_SetFont(&screen, u8g2_font_wqy12_t_gb2312_lite);
    uint8_t start_x = (u8g2_GetDisplayWidth(&screen) - u8g2_GetUTF8Width(&screen, dis_msg)) / 2;
    u8g2_DrawUTF8(&screen, start_x, 26, dis_msg);
    float width_radius = distance / 8140.0f;
    if (width_radius >= 1.0f)
        width_radius = 1.0f;
    else
        width_radius = 1.0f - std::pow(2.0f, -50.0f * width_radius);
    uint8_t width = static_cast<uint8_t>(u8g2_GetDisplayWidth(&screen) * width_radius); // 进度条长度
    u8g2_DrawBox(&screen, 0, 40, width, 3);
    u8g2_SendBuffer(&screen);
}

void laser_page::enter()
{
    laser_start();
}

void laser_page::leave()
{
    laser_stop();
}

void laser_page::on_encoder_changed(int32_t diff)
{
    route_to(&main_menu_page_instance);
}
