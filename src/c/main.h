#pragma once
#include <pebble.h>

typedef struct ClaySettings {
    int flag_number;
    bool BottomShadow;
    int spacing;
    GColor bgColor;
    GColor mainColor;
    GColor accColor;
    GFont timeFant;
    bool doBatBar;
    bool doBtBuzz;
} ClaySettings;

void update_stuff();