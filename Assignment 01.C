/*//////////////////////////////////////////////
	Written by: Michael Braddy
	Written on: 1/15/17
//////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause")

#include <stdio.h>
#include <stdlib.h>

//	Prototype Functions Start
void notReallyALoop(int, int);
//	Prototype Functions End

//	Start Main
main(){	
	int countDown = 10;
	int countUp = 1;

	//	Fake Loop Start
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	countDown--;
	countUp++;
	notReallyALoop(countDown, countUp);
	//	Fake Loop End

	PAUSE;
}	//	End Main

//	Function Allowance Start
void notReallyALoop (int countDown,int countUp){
	printf("%i. x equals %i.\n", countUp, countDown);

}	//	Spent All My Allowance In One Place
