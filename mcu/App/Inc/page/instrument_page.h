//
// Created by insmtr on 24-10-16.
//

#pragma once
#include "page.h"
class instrument_page : public page
{
  public:
    instrument_page();
    void update_ui() override;
    void enter() override;
    void leave() override;
    void on_encoder_changed(int32_t diff) override;
};
extern instrument_page instrument_page_instance;
