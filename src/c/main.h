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
    GFont dateFant;
    bool showBatBar;
    bool doBtBuzz;
    bool doDate;
    bool switchDate;
    char dateSeparator;
} ClaySettings;

void update_stuff();