#include <pebble.h>

int trans[] = {0x00AAFF, 0xFF55FF, 0xFFFFFF, 0xFF55FF, 0x00AAFF};
int demigirl[] = {0x555555, 0xAAAAAA, 0xFF55FF, 0xFFFFFF, 0xFF55FF, 0xAAAAAA, 0x555555};
int lesbian[] = {0xFF5500, 0xFFAA00, 0xFFFFFF, 0xAA55AA, 0xAA0055};
int asexual[] = {0x000000, 0xAAAAAA, 0xFFFFFF, 0xAA00AA};
int blank[] = {0x000000};

int *flag_colors[] = {trans, demigirl, lesbian, asexual, blank};
int num_stripes[] = {5, 7, 5, 4, 1};