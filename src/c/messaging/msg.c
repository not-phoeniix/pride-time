#include <pebble.h>
#include "msg.h"
#include "../main.h"
#include "../config/cfg.h"

extern ClaySettings settings;

static void inbox_recieved_handler(DictionaryIterator *iter, void *ctx) {
    Tuple *flag_t = dict_find(iter, MESSAGE_KEY_FlagKey);
    if (flag_t) {
        settings.flag_number = atoi(flag_t->value->cstring);
    }

    Tuple *bottomShadow_t = dict_find(iter, MESSAGE_KEY_BottomShadowKey);
    if(bottomShadow_t) {
        settings.BottomShadow = bottomShadow_t->value->int32 == 1;
    }

    Tuple *spacing_t = dict_find(iter, MESSAGE_KEY_SpacingKey);
    if(spacing_t) {
        settings.spacing = spacing_t->value->int32;
    }

    Tuple *bgColor_t = dict_find(iter, MESSAGE_KEY_BGColorKey);
    if(bgColor_t) {
        settings.bgColor = GColorFromHEX(bgColor_t->value->int32);
    }

    Tuple *mainColor_t = dict_find(iter, MESSAGE_KEY_MainColorKey);
    if(mainColor_t) {
        settings.mainColor = GColorFromHEX(mainColor_t->value->int32);
    }

    Tuple *accColor_t = dict_find(iter, MESSAGE_KEY_AccentColorKey);
    if(accColor_t) {
        settings.accColor = GColorFromHEX(accColor_t->value->int32);
    }

    Tuple *timeFont_t = dict_find(iter, MESSAGE_KEY_TimeFontKey);
    if(timeFont_t) {
        settings.timeFant = fonts_get_system_font(timeFont_t->value->cstring);
    }

    Tuple *bat_t = dict_find(iter, MESSAGE_KEY_EnableBatteryKey);
    if(bat_t) {
        settings.showBatBar = bat_t->value->int32 == 1;
    }

    Tuple *btbuzz_t = dict_find(iter, MESSAGE_KEY_EnableBTBuzzKey);
    if(btbuzz_t) {
        settings.doBtBuzz = btbuzz_t->value->int32 == 1;
    }

    Tuple *date_t = dict_find(iter, MESSAGE_KEY_EnableDateKey);
    if(date_t) {
        settings.doDate = date_t->value->int32 == 1;
    }

    Tuple *datefont_t = dict_find(iter, MESSAGE_KEY_DateFontKey);
    if(datefont_t) {
        settings.dateFant = fonts_get_system_font(datefont_t->value->cstring);
    }

    Tuple *dateswitch_t = dict_find(iter, MESSAGE_KEY_DateSwitchKey);
    if(dateswitch_t) {
        settings.switchDate = dateswitch_t->value->int32 == 1;
    }

    Tuple *dateseparator_t = dict_find(iter, MESSAGE_KEY_DateSeparatorKey);
    if(dateseparator_t) {
        settings.dateSeparator = dateseparator_t->value->cstring[0];
    }

    Tuple *rotflag_t = dict_find(iter, MESSAGE_KEY_RotateFlagKey);
    if(rotflag_t) {
        settings.rotFlag = atoi(rotflag_t->value->cstring);
    }

    save_settings();
    update_stuff();
}

void init_msg() {
    app_message_register_inbox_received(inbox_recieved_handler);
    app_message_open(256, 256);
}