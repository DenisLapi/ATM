#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../includes/user.h"
#include "./../includes/banking.h"
#include "./../includes/card.h"

int get_balance(struct User *client) {
	return client->balance;
}

int withdraw_money(struct User *client, int amount) {

	if(client->balance - amount < 0) {
		printf("\nYou don't have enough money. Check you balance first");
		return 0;
	}

	// Reduce money amount
	client->balance -= amount;

	// Update the card data in databasse
	update_card_data(client->card_number, client);

	// Return new balance just in case somebody needs the value from the function
	// User data is already updated using the client pointer
	return client->balance;
}
