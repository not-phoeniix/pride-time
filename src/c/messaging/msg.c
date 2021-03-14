#include <pebble.h>
#include "msg.h"
#include "../main.h"
#include "../config/cfg.h"

extern ClaySettings settings;
extern int flag_num;

static void inbox_recieved_handler(DictionaryIterator *iter, void *ctx) {
    //flag
    Tuple *flag_t = dict_find(iter, MESSAGE_KEY_FlagKey);

    if (flag_t) {
        flag_num = flag_t->value->int32;
    }
    save_settings();
    update_flag();
}

void init_msg() {
    app_message_register_inbox_received(inbox_recieved_handler);
    app_message_open(256, 256);
}