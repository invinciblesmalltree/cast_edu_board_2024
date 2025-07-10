//
// Created by insmtr on 24-10-16.
//

#pragma once

#include <buzzer.h>
#include <cstddef>

struct song_info
{
    tone_info *tones;
    size_t tone_count;
    const char *name;
};

extern song_info songs[];
extern tone_info single_tone[];
