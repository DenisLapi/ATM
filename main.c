#include <stdio.h>
#include <stdlib.h>
#include "./includes/user.h"
#include "./includes/authentication.h"
#include "./includes/utils.h"

int main() {

	// Create variable where we will store the data of user
	struct User client;

	// Reset client authentication to false
	client.authenticated = 0;

	// Show user login inputs while he/she is not logged in
	while(!get_authetication(&client)) {
		printf("\n\nPlease enter your card credentials\n");
		authenticate_user(&client);
	}

	// Show menu with banking options
	while(1) {
		show_menu(&client);
	}

	return 0;
}