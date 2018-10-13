#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../includes/user.h"
#include "./../includes/banking.h"

double get_balance(struct User *client) {
	return client->balance;
}
