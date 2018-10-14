#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../includes/user.h"
#include "./../includes/card.h"

FILE *check_card_validity(char *card_number) {
	char file_path[40];
	FILE *card_file;

	// Initializate file path
	strcpy(file_path, "./db/");
	strcat(file_path, card_number);
	strcat(file_path, ".txt");

	// Check if file exist on the file destination
	return (!(card_file = fopen(file_path, "r+"))) ? NULL : card_file;
}

void update_card_data(char *card_number, struct User *client) {

	int balance;
	FILE *card_file;

	card_file = check_card_validity(card_number);
	if(card_file == NULL) {
		printf("\nCard number is not correct");
		return;
	}

	rewind(card_file);

	fprintf(card_file, "%s\n", client->first_name);
	fprintf(card_file, "%s\n", client->last_name);
	fprintf(card_file, "%s\n", client->card_number);
	fprintf(card_file, "%s\n", client->pin_code);
	fprintf(card_file, "%d\n", client->balance);

	fclose(card_file);
}
