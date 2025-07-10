// Copyright (C) 2024 ArcticLampyrid <alampy.com>
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

//
// Created by insmtr on 24-9-16.
//

#pragma once
#include "dino_logic.h"
#include "page.h"

class dino_page : public page
{
  private:
    dino::dino_logic_t logic;
    std::minstd_rand rand_engine;

  public:
    dino_page();
    void update_ui() override;
    void enter() override;
    void leave() override;
    void tick() override;
    void on_encoder_changed(int32_t diff) override;
};

extern dino_page dino_page_instance;
