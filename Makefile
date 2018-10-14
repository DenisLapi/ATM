all:
	gcc main.c src/authentication.c src/banking.c src/card.c src/utils.c -o atm
