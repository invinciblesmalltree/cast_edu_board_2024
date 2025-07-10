// Copyright (C) 2023 ArcticLampyrid <alampy.com>
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

#include "page/main_menu_page.h"
#include "page/about_page.h"
#include "page/buzzer_menu_page.h"
#include "page/game_menu_page.h"
#include "page/keyboard_page.h"
#include "page/laser_page.h"

static void on_enter_buzzer()
{
    buzzer_menu_page_instance.focus_to_without_transition(0);
    route_to(&buzzer_menu_page_instance);
}

static void on_enter_keyboard()
{
    route_to(&keyboard_page_instance);
}

static void on_enter_laser()
{
    route_to(&laser_page_instance);
}

static void on_enter_game()
{
    game_menu_page_instance.focus_to_without_transition(0);
    route_to(&game_menu_page_instance);
}

static void on_enter_about()
{
    route_to(&about_page_instance);
}

static menu_item items[] = {
    {
        .text = "蜂鸣器",
        .on_enter = on_enter_buzzer,
    },
    {
        .text = "矩阵键盘",
        .on_enter = on_enter_keyboard,
    },
    {
        .text = "激光测距",
        .on_enter = on_enter_laser,
    },
    {
        .text = "游戏",
        .on_enter = on_enter_game,
    },
    {
        .text = "关于",
        .on_enter = on_enter_about,
    },
};

menu_page main_menu_page_instance("[ CAST 学习板 2024 ]", items, sizeof(items) / sizeof(items[0]));
