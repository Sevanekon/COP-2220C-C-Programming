#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls")
#define FLUSH fflush(stdin)
#define PAUSE system("pause")

#include <stdio.h>
#include <stdlib.h>

//	Actually did this assignment twice because I over complicated it with a bunch of arrays.

//	Prototype Functions Start
void mainMenu(double, int, double);
void displayCurrents(double, int, double);
double figureOutThePrice(int, int, double, double, double, double, double, double, double, double);
double getNewAverage(double, double, int);
//	Prototype Functions End

//	Main Begin
main() {

	//	Constants
	const double first = 500;
	const double firstStudent = 500;
	const double lastDay = 0.05;
	const double student = 700;
	const double veteran = 0.01;

	//	Variables Start
	int menuChoice = 0;
	int totalCars = 0;
	int yesOrNo = 0;
	int isHeBoth = 0;
	double averagePrice = 0;
	double tempPrice = 0;
	double stickerPrice = 0;
	double totalDiscount = 0;
	double totalRevenue = 0;
	double totalSalePrice = 0;
	double totalSales = 0;

	//	Menu Switch
	do {
		mainMenu(averagePrice, totalCars, totalRevenue);
		scanf("%i", &menuChoice);
		FLUSH;

		switch (menuChoice) {
		case 1:
			totalCars++;	//	Keeps track of total number of car sales during program usage
			CLS;
			displayCurrents(averagePrice, totalCars, totalRevenue);	//	displays the desired outputs on the top of the screen
			totalSalePrice = figureOutThePrice(yesOrNo, isHeBoth, tempPrice, stickerPrice, totalDiscount, first, firstStudent, lastDay, student, veteran);	//	calculates car price
			printf("\nYour final sale price is: $%.2lf\n", totalSalePrice);
			totalSales += totalSalePrice;	//	Updates total sales (for determining average sale price)
			averagePrice = getNewAverage(averagePrice, totalSales, totalCars);	//	actually determines the average
			totalRevenue += (totalSales * .05);	//	Was going to make a seperate function for this, but seemed kinda pointless since it's only one equation.
			break;
		case 9:
			printf("Exitting Program\n");
			break;
		default:
			printf("Please enter a valid option.\n");
			break;
		}
		PAUSE;
	} while (menuChoice != 9);

}	//	End of Main

//	mainMenu Start
void mainMenu(double averagePrice, int totalCars, double totalRevenue) {

	FLUSH;
	CLS;
	displayCurrents(averagePrice, totalCars, totalRevenue);
	printf("Please choose from the following options: \n");
	printf("1.\tEnter A New Sale\n");
	printf("9.\tExit Program\n\n");
	printf("Enter Selection: ");

}	//	End mainMenu

//	Just a boring banner for outputs
void displayCurrents(double averagePrice, int totalCars, double totalRevenue) {
	printf("Total Cars Sold: %i\t\tAverage Sale Price: %.2lf\t\tTotal Revenue Earned: %.2lf\n\n", totalCars, averagePrice, totalRevenue);
}

//	Pricing calculation start
double figureOutThePrice(int yesOrNo, int isHeBoth, double tempPrice, double stickerPrice, double totalDiscount,
	double first, double firstStudent, double lastDay, double student, double veteran) {

	stickerPrice = 0;	//	variable initilization
	totalDiscount = 0;
	isHeBoth = 0;
	tempPrice = 0;

	printf("What is the Sticker Price of the car you are buying?\n");	//	Input from user
	scanf("%lf", &stickerPrice);
	

	yesOrNo = 0;
	printf("Is it the last day of the month?\n1. Yes\n2. No\n");
	scanf("%i", &yesOrNo);

	if (yesOrNo == 1) {
		totalDiscount += (stickerPrice * lastDay);	//	applies 5% discount prior to others
	}

	yesOrNo = 0;
	printf("Are you a first time buyer?\n1. Yes\n2. No\n");
	scanf("%i", &yesOrNo);

	if (yesOrNo == 1) {
		totalDiscount += first;	//	applies 500
		isHeBoth++;	//	used to determine if bonus 500 is applied
	}

	yesOrNo = 0;
	printf("Are you a student?\n1. Yes\n2. No\n");
	scanf("%i", &yesOrNo);

	if (yesOrNo == 1) {
		totalDiscount += student;	//	applies 700	
		isHeBoth++;	//	bonus check
			if (isHeBoth == 2) {
				totalDiscount += firstStudent;	//	additional 500
			}
		}

	yesOrNo = 0;
	printf("Are you a veteran?\n1. Yes\n2. No\n");
	scanf("%i", &yesOrNo);

	tempPrice = totalDiscount;

	if (yesOrNo == 1) {
			totalDiscount += ((stickerPrice - tempPrice) * veteran);	//	1% of final price added
	}

	tempPrice = stickerPrice - totalDiscount;
	return tempPrice;	//	final price

}	//	End of Pricing

//	Boring average calculations
double getNewAverage(double averagePrice, double totalSales, int totalCars) {
	averagePrice = totalSales / totalCars;
	return averagePrice;
}