//
// Created by insmtr on 24-11-21.
//

#pragma once
#include "menu_page.h"
#include "page.h"
class video_page : public page
{
  public:
    video_page();
    void update_ui() override;
    void enter() override;
    void leave() override;
    void on_encoder_changed(int32_t diff) override;
    int song_id = 4;
};
extern video_page video_page_instance;
