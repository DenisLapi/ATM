#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
