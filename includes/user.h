#ifndef USER_H_FILE
#define USER_H_FILE

// Sizes
#define MAX_SIZE_FIRST_NAME 50
#define MAX_SIZE_LAST_NAME 50
#define MAX_SIZE_CARD_NUMBER 17 // 16 digits + null char
#define MAX_SIZE_PIN_CODE 5 // 4 digits + null char
#define MAX_SIZE_BALANCE_IN_STRING 11 // 10 digits (C limit) + null char

// Structures
struct User {
	char first_name[MAX_SIZE_FIRST_NAME];
	char last_name[MAX_SIZE_LAST_NAME];
	char card_number[MAX_SIZE_CARD_NUMBER];
	char pin_code[MAX_SIZE_PIN_CODE];
	double balance;
	int authenticated;
};

#endif // USER_H_FILE
