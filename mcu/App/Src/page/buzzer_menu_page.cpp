//
// Created by insmtr on 24-10-14.
//

#include "page/buzzer_menu_page.h"
#include "page/buzzer_page.h"
#include "page/video_page.h"
#include "page/instrument_page.h"
#include "page/main_menu_page.h"

static void on_enter_song1()
{
    buzzer_page_instance.song_id = 0;
    route_to(&buzzer_page_instance);
}

static void on_enter_song2()
{
    buzzer_page_instance.song_id = 1;
    route_to(&buzzer_page_instance);
}

static void on_enter_song3()
{
    buzzer_page_instance.song_id = 2;
    route_to(&buzzer_page_instance);
}

static void on_enter_song4()
{
    buzzer_page_instance.song_id = 3;
    route_to(&buzzer_page_instance);
}

static void on_enter_song5()
{
    buzzer_page_instance.song_id = 4;
    route_to(&video_page_instance);
}

static void on_enter_instrument()
{
    route_to(&instrument_page_instance);
}

static void on_enter_exit()
{
    route_to(&main_menu_page_instance);
}

static menu_item items[] = {
    {
        .text = "追光者",
        .on_enter = on_enter_song1,
    },
    {
        .text = "起风了",
        .on_enter = on_enter_song2,
    },
    {
        .text = "天使にふれたよ!",
        .on_enter = on_enter_song3,
    },
    {
        .text = "错位时空",
        .on_enter = on_enter_song4,
    },
    {
        .text = "Bad Apple!",
        .on_enter = on_enter_song5,
    },
    {
        .text = "自由演奏",
        .on_enter = on_enter_instrument,
    },
    {
        .text = "退出",
        .on_enter = on_enter_exit,
    },
};

menu_page buzzer_menu_page_instance("[ 蜂鸣器测试 ]", items, std::size(items), &main_menu_page_instance);
