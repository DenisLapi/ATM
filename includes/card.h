#ifndef CARD_H_FILE
#define CARD_H_FILE

#include <stdio.h>

FILE *check_card_validity(char *card_number);
void update_card_data(char *card_number, struct User *client);

#endif // CARD_H_FILE
