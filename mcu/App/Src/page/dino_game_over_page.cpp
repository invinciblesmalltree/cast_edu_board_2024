//
// Created by insmtr on 24-10-20.
//

#include "oled.h"
#include "page/dino_game_over_page.h"
#include "page/dino_page.h"
#include "page/game_menu_page.h"

dino_game_over_page dino_game_over_page_instance;

dino_game_over_page::dino_game_over_page()
{
    this->key_handlers[KEY_OK].on_pressed = [this](key_state) { enter_menu_item(); };
    this->key_handlers[KEY_X0Y0].on_pressed = [this](key_state) { focus_with_increment(-1); };
    this->key_handlers[KEY_X2Y0].on_pressed = [this](key_state) { focus_with_increment(+1); };
    this->key_handlers[KEY_X1Y0].on_pressed = [this](key_state) { enter_menu_item(); };
    this->key_handlers[USER_KEY_1].on_pressed = [this](key_state) { route_to(&game_menu_page_instance); };
    this->key_handlers[USER_KEY_2].on_pressed = [this](key_state) { enter_menu_item(); };
}

void dino_game_over_page::update_ui()
{
    button_animation.update();

    u8g2_ClearBuffer(&screen);
    u8g2_SetFont(&screen, u8g2_font_wqy14_t_gb2312_lite);
    switch (reason)
    {
    case dino::game_over_reason_t::aborted:
        u8g2_DrawUTF8(&screen, 50, 14, "中断");
        break;
    case dino::game_over_reason_t::hit_cactus:
        u8g2_DrawUTF8(&screen, 22, 14, "撞仙人掌啦!");
        break;
    }
    u8g2_DrawUTF8(&screen, score_message_x, 28, score_message);

    u8g2_DrawUTF8(&screen, 4, 50, "再来一次");
    u8g2_DrawUTF8(&screen, 82, 50, "退出");

    u8g2_SetDrawColor(&screen, 2);
    u8g2_DrawRBox(&screen, std::lround(2 + 64 * button_animation.value()), 36, 60, 18, 2);
    u8g2_SetDrawColor(&screen, 1);

    u8g2_SendBuffer(&screen);
}

void dino_game_over_page::enter()
{
    button_animation.set(0);
}

void dino_game_over_page::leave()
{
}

void dino_game_over_page::set_score(uint16_t score)
{
    snprintf(score_message, sizeof(score_message), "得分: %d", score);
    score_message_x = 64 - u8g2_GetUTF8Width(&screen, score_message) / 2;
}

void dino_game_over_page::focus_with_increment(int increment)
{
    auto value = std::fmod(button_animation.end_value() + (float)increment, 2.0f);
    if (value < 0)
        value += 2;
    button_animation.transition(value, 200);
}

void dino_game_over_page::on_encoder_changed(int32_t diff)
{
    focus_with_increment(diff);
}

void dino_game_over_page::enter_menu_item()
{
    if (button_animation.end_value() < 1)
    {
        route_to(&dino_page_instance);
    }
    else
    {
        route_to(&game_menu_page_instance);
    }
}
