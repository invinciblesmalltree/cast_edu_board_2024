//
// Created by insmtr on 24-10-23.
//

#include "page/game_menu_page.h"
#include "page/snake_page.h"
#include "page/dino_page.h"
#include "page/main_menu_page.h"

static void on_enter_snake()
{
    route_to(&snake_page_instance);
}

static void on_enter_dino()
{
    route_to(&dino_page_instance);
}

static void on_enter_exit()
{
    route_to(&main_menu_page_instance);
}

static menu_item items[] = {
    {
        .text = "贪吃蛇",
        .on_enter = on_enter_snake,
    },
    {
        .text = "恐龙快跑",
        .on_enter = on_enter_dino,
    },
    {
        .text = "退出",
        .on_enter = on_enter_exit,
    },
};

menu_page game_menu_page_instance("[ 游戏 ]", items, std::size(items), &main_menu_page_instance);
