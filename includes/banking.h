#ifndef BANKING_H_FILE
#define BANKING_H_FILE

#include "./user.h"

int get_balance(struct User *client);
int withdraw_money(struct User *client, int amount);
void transfer_money(struct User *client, struct User *receiver);

#endif // BANKING_H_FILE
