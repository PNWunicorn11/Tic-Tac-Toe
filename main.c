#include <stdio.h>
#include <stdbool.h>
#include "tic-tac-toe.h"

//size of gameboard constants for arrays
const int BOARDSIZE = 90;
const int NUMSPACE = BOARDSIZE/10;
const int NUMPLAYER = 2;

int main(int argc, char *argv[])
{
/**************************VARIABLES*************************/
	//Flag for detecting two human players
	bool twoPlayer = false;
	//Human player selected symbols
	char playerSymbol = 0;
	char playerSymbol2 = 0;
	//Flag for detecting if computer will play
	bool comActive = false;
	//Scores
	int score[NUMPLAYER];
	//Game board information
	space board[BOARDSIZE][BOARDSIZE];
	//Human players selected spaces
	int playerSpaces[NUMSPACE];
	int playerSpaces2[NUMSPACE];

/************************START******************************/

	gameSetup(twoPlayer, playerSymbol, playerSymbol2,
		comActive, score, playerSpaces, playerSpaces2,
		board);

	printf("Hello World!");

	return 0;
}