#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../includes/user.h"
#include "./../includes/authentication.h"
#include "./../includes/card.h"

void authenticate_user(struct User *client) {

	char first_name[MAX_SIZE_FIRST_NAME];
	char last_name[MAX_SIZE_LAST_NAME];
	char card_number[MAX_SIZE_CARD_NUMBER];
	char pin_code[MAX_SIZE_PIN_CODE];
	char pin_input[MAX_SIZE_PIN_CODE];
	int balance;
	FILE *card_file;

	printf("Enter your card number: ");
	scanf("%s", card_number);

	printf("Enter pin code: ");
	scanf("%s", pin_input);

	card_file = check_card_validity(card_number);
	if(card_file == NULL) {
		printf("\nCard number is not correct");
		return;
	}

 	rewind(card_file);

 	fscanf(card_file, "%s", first_name);
 	fscanf(card_file, "%s", last_name);
 	fscanf(card_file, "%s", card_number);
 	fscanf(card_file, "%s", pin_code);
 	fscanf(card_file, "%d", &balance);
 	if(fclose(card_file) != 0) {
		printf("\n File can't be closed");
	}

 	if(strcmp(pin_input, pin_code) == 0) {

 		// Populate data for client if PIN code is correct
 		strcpy(client->first_name, first_name);
 		strcpy(client->last_name, last_name);
 		strcpy(client->card_number, card_number);
 		strcpy(client->pin_code, pin_code);
 		client->balance = balance;
 		client->authenticated = 1;
 		printf("\nSucessfully logged in!");

 	} else {
 		printf("\nYou credentials are not correct!");
 	}
}

int get_authetication(struct User *client) {
	return client->authenticated;
}
