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
#include "page/fixed_deque.h"
#include <cstdint>
#include <event_handler.h>
#include <random>
namespace dino
{
enum cactus_type
{
    cactus1 = 0,
    cactus2,
    cactus3
};
struct cactus_info_t
{
    double distance;
    cactus_type type;
    cactus_info_t *next;
};
enum class game_over_reason_t : uint8_t
{
    aborted = 0,
    hit_cactus = 1,
};
class dino_logic_t
{
  private:
    uint32_t start_time = 0;
    uint32_t take_off_time = 0;
    cactus_info_t cactus_info[3]{};
    std::minstd_rand rand_engine;

  public:
    dino_logic_t() noexcept;
    void reset() noexcept;
    cactus_info_t *front_cactus_info;
    double cloud_distance = 0;
    double velocity = 0;
    uint8_t is_crashed() noexcept;
    [[nodiscard]] uint8_t get_jump_height() const noexcept;
    void jump() noexcept;
    void update_velocity() noexcept;
    void create_cactus() noexcept;
    cactus_info_t *get_closest_cactus_info() noexcept;
    [[nodiscard]] uint32_t get_score() const noexcept;
    void abort_game() const noexcept;
    event_handler_t<game_over_reason_t> on_game_over{};
};
} // namespace dino
