//	Written by: Michael Braddy
//	Written on: 1/22/17

#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls")
#define FLUSH fflush(stdin)
#define PAUSE system("pause")

#include <stdlib.h>
#include <stdio.h>

//	Prototype Functions
void displayTheAverage(int, int, int);
void displayTheSum(int, int, int);
void displayTheLowest(int, int, int);
void displayTheProduct(int, int, int);
void getAnInteger(int *input);
//	End Prototype

//	Main start
main() {
	int inputOne = 0, inputTwo = 0, inputThree = 0;	//	User inputs
	char menuChoice = 'Z';	//	user menu choice w/ initiation

	do {	//	Menu Loop Start

		CLS;
		printf("Please choose from the following options: \n");
		printf("A.\tGet Three Integers\n");
		printf("B.\tDisplay The Sum\n");
		printf("C.\tDisplay The Product\n");
		printf("D.\tDisplay The Average\n");
		printf("E.\tDisplay The Lowest\n");
		printf("F.\tQuit\n\n");
		printf("Enter Selection: ");
		FLUSH;
		scanf(" %c", &menuChoice);	//	Detect Entry (Didnt feel like adding the capitalizations if statements so just made them invalid inputs)

		switch (menuChoice) {	//	menu switch start
		case 'A':
			getAnInteger(&inputOne);	//	Call by reference to input the integers
			getAnInteger(&inputTwo);
			getAnInteger(&inputThree);
			break;
		case 'B':
			displayTheSum(inputOne, inputTwo, inputThree);	//	call by values for everything else
			break;
		case 'C':
			displayTheProduct(inputOne, inputTwo, inputThree);
			break;
		case 'D':
			displayTheAverage(inputOne, inputTwo, inputThree);
			break;
		case 'E':
			displayTheLowest(inputOne, inputTwo, inputThree);
			break;
		case 'F':
			printf("Exitting Program\n");
			break;
		default:
			printf("Please enter a valid option. (Check Case)\n");	//	error checking for menu
			break;
		}	//	menu switch end
		PAUSE;

	} while (menuChoice != 'F');	//	End of Menu loop
}
//	Main End

//	All display functions follow same format, Error check for inputs followed by print the math request

// Display Functions Start
void displayTheAverage(int one, int two, int three) {
	if (one == 0 && two == 0 && three == 0){
		printf("Either you entered three zeroes thinking you were slick, or you haven't entered anything yet dummy.\n");
	}
	else {
		printf("%i\n", ((one + two + three) / 3));
	}
}

void displayTheSum(int one, int two, int three) {
	if (one == 0 && two == 0 && three == 0) {
		printf("Either you entered three zeroes thinking you were slick, or you haven't entered anything yet dummy.\n");
	}
	else {
		printf("%i\n", (one + two + three));
	}
}

void displayTheLowest(int one, int two, int three) {
	if (one == 0 && two == 0 && three == 0) {
		printf("Either you entered three zeroes thinking you were slick, or you haven't entered anything yet dummy.\n");
	}
	else {
		if (one <= two && one <= three) {	//	Nested If else statement for determining lowest value
			printf("%i\n", one);
		}
		else if (two <= one && two <= three) {
			printf("%i\n", two);
		}
		else {
			printf("%i\n", three);
		}
	}
}

void displayTheProduct(int one, int two, int three) {
	if (one == 0 && two == 0 && three == 0) {
		printf("Either you entered three zeroes thinking you were slick, or you haven't entered anything yet dummy.\n");
	}
	else {
		printf("%i\n", (one*two*three));
	}
}
//	Display Functions End

//	Get integer by reference Start
void getAnInteger(int *input) {
	int userInput = 0;
	printf("\nPlease enter a number: ");
	scanf("%i", &userInput);
	(*input) = userInput;
	FLUSH;
}
//	Get Integer End