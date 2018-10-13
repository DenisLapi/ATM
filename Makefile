all:
	gcc main.c includes/user.h includes/authentication.h src/authentication.c includes/banking.h src/banking.c includes/card.h src/card.c includes/utils.h  src/utils.c -o atm
