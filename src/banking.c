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

void transfer_money(struct User *client, struct User *receiver) {

	int amount;
	char card_number[MAX_SIZE_CARD_NUMBER];

	printf("\nEnter amount: ");
	scanf("%d", &amount);

	printf("\nEnter card number: ");
	scanf("%s", card_number);

	FILE *card_file;

	// If user enter the his/her card number stop the action and send message
	if(strcmp(card_number, client->card_number) == 0) {
		printf("\nYou can't send money to your card");
		return;
	}

	// If user enter bigger amount than he/she has on the card
	if(client->balance - amount < 0) {
		printf("\nYou don't have enough money. Check you balance first");
		return;
	}

	// Check card where user wants to send money exists. If not stop the action and show the message
	card_file = check_card_validity(card_number);
	if(card_file == NULL) {

		printf("\nCard number is not correct");
		return;

	} else {
		// Read date from file so we can use it later to update it wiwht new data (Balance value)
		rewind(card_file);

		fscanf(card_file, "%s", receiver->first_name);
		fscanf(card_file, "%s", receiver->last_name);
		fscanf(card_file, "%s", receiver->card_number);
		fscanf(card_file, "%s", receiver->pin_code);
		fscanf(card_file, "%d", &receiver->balance);

		// Reduce the balance to client and increase to receiver
		client->balance -= amount;
		receiver->balance += amount;

		// Update the client and received DB files
		update_card_data(client->card_number, client);
		update_card_data(receiver->card_number, receiver);

		printf("\n[Info] $%d successfully transferred to card number: %s", amount, receiver->card_number);

	}

	if(fclose(card_file) != 0) {
		printf("\nTransfer: File can't be closed");
	}

	return;

}
