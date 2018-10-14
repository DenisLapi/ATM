#include <stdio.h>
#include <stdlib.h>
#include "./../includes/user.h"
#include "./../includes/utils.h"
#include "./../includes/banking.h"

void show_menu(struct User *client) {
	int amount;
	int menu_option;
	char card_number[MAX_SIZE_CARD_NUMBER];
	struct User receiver;

	printf("\n\n|--------------- MENU ---------------|\n1) Balance \n2) Withdraw \n3) Money transfer\n4) CLOSE");
	printf("\nEnter the option number: ");

	scanf("%d", &menu_option);

	switch(menu_option) {
		case 1:
			printf("\nBalance: %d", get_balance(client));
			break;
		case 2:
			printf("\nEnter amount: ");
			scanf("%d", &amount);
			withdraw_money(client, amount);
			break;
		case 3:
			transfer_money(client, &receiver);
			break;
		case 4:
			exit(0);
			break;
		default:
			show_menu(client);
			break;
	}
}
