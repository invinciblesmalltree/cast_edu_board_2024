//
// Created by insmtr on 24-10-12.
//

#pragma once
#include "page.h"
class laser_page : public page
{
  public:
    laser_page();
    void update_ui() override;
    void enter() override;
    void leave() override;
    void on_encoder_changed(int32_t diff) override;
};
extern laser_page laser_page_instance;
