//	Created by: Michael Braddy
//	Created on: 1/29/17
//	Created for: Assignment 04, Arrays 1D + 2D

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")
#define FLUSH fflush(stdin)
#define CLS system("cls")
#define SIZE 1000
#define TEAMS 2

//	Prototype Functions:
void mainMenu(int gameScores[TEAMS][SIZE]);
//	End Prototype

#include <stdio.h>
#include <stdlib.h>

//	Main Start
main() {

	int gameScores[TEAMS][SIZE];	//	2D array

	mainMenu(gameScores);	//	Function Call

}	//	End Main

void mainMenu(int gameScores[TEAMS][SIZE]) {

	int mSelection = 0;	//	Menu choice
	int gamesEntered = 0;	//	Tracker of how many entered
	int myScore, theirScore;	//	Scores input
	int wins = 0, losses = 0;	//	Wins and Losses counters

	do {	// Begin Menu Loop

		CLS;

		printf("What would you like to do? \n");
		printf("\n 1. Enter game results");
		printf("\n 2. Current Record (# of Wins and # of Losses)");
		printf("\n 3. Display ALL results from all games WON");
		printf("\n 4. Display ALL results");
		printf("\n 5. Quit");

		printf("\n Enter Selection: ");
		scanf("%i", &mSelection); FLUSH;

		switch (mSelection) { // Begin switch

		case 1:
			printf("\nEnter your team's score: ");	//	Score gathering
			scanf("%i", &myScore); FLUSH;
			printf("\nEnter their Opponent's score: ");
			scanf("%i", &theirScore); FLUSH;

			gameScores[0][gamesEntered] = myScore;	//	Element 0 our team
			gameScores[1][gamesEntered] = theirScore;	//	Element 1 their team

			if (myScore > theirScore) {	//	counters
				wins++;
			}
			else if (myScore < theirScore) {
				losses++;
			}

			gamesEntered++;	//	total tracking
			break;

		case 2:
			if (gamesEntered == 0) {	//	error check
				printf("Your team hasn't played any games yet.\n");
			}
			else {
				printf("Your team has won %i games and lost %i games.\n", wins, losses);	//	simple print counters
			}
			break;

		case 3:
			if (gamesEntered == 0) {	//	thought you were slick eh?
				printf("Your team hasn't played any games yet.\n");
			}
			else {
				printf("Scores of Won Games: \n");
				for (int i = 0; i < gamesEntered; i++) {	//	checking our team vs their team against all games entered
					if (gameScores[0][i] > gameScores[1][i]) {
						printf("Your team: %i\t Opposing team: %i\n", gameScores[0][i], gameScores[1][i]);
					}
				}
			}
			break;

		case 4:
			if (gamesEntered == 0) {	//	you werent that slick
				printf("Your team hasn't played any games yet.\n");
			}
			else {
				printf("Scores of all games: \n");
				for (int i = 0; i < gamesEntered; i++) {	//	rolling print statement
					printf("Your team: %i\t Opposing team: %i\n", gameScores[0][i], gameScores[1][i]);
					}
			}
			break;

		case 5:
			printf("\nExitting\n");
			break;

		default:	//	more error checks
			printf("Please enter a valid option \n");
			break;
		} // End switch

		PAUSE;

	} while (mSelection != 5);	//	End Menu Loop

}