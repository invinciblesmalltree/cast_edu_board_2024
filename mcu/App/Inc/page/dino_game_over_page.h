//
// Created by insmtr on 24-10-20.
//

#pragma once
#include "ease_out_animation.h"
#include "page.h"
#include "dino_logic.h"

class dino_game_over_page : public page
{
  private:
    char score_message[12]{};
    uint16_t score_message_x = 0;
    ease_out_animation button_animation{0};
    void focus_with_increment(int increment);

  public:
    dino::game_over_reason_t reason = dino::game_over_reason_t::hit_cactus;
    dino_game_over_page();
    void update_ui() override;
    void enter() override;
    void leave() override;
    void set_score(uint16_t score);
    void on_encoder_changed(int32_t diff) override;
    void enter_menu_item();
};

extern dino_game_over_page dino_game_over_page_instance;
