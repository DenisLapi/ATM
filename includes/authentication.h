#ifndef AUTHENTICATION_H_FILE
#define AUTHENTICATION_H_FILE

#include "./user.h"

int get_authetication(struct User *client);
void authenticate_user(struct User *client);

#endif // AUTHENTICATION_H_FILE
