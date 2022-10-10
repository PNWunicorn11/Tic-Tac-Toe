#include <stdio.h>
#include <stdbool.h>
#include "tic-tac-toe.h"

//size of gameboard constants for arrays
const int BOARDSIZE = 30;
const int NUMSPACE = (BOARDSIZE/3) - 1;
const int NUMPLAYER = 2;
const int NUMCOMBO = 3;

int main(int argc, char *argv[])
{
/**************************VARIABLES*****************************/
	//Flag for detecting two human players
	bool twoPlayer = false;
	//Human player selected symbols
	char playerSymbol = 0;
	char playerSymbol2 = 0;
	//Scores
	int score[NUMPLAYER];
	//Game board information
	char board[BOARDSIZE][BOARDSIZE];
	//Human players selected spaces
	bool playerSpaces[NUMSPACE];
	bool playerSpaces2[NUMSPACE];

	int i = 0; //Counter for loops

/******************************START******************************/

	gameSetup(&twoPlayer, &playerSymbol, &playerSymbol2, score, 
		playerSpaces, playerSpaces2,board);
	do
	{
		drawBoard(twoPlayer, playerSymbol, playerSymbol2, score,
		playerSpaces, playerSpaces2, board);
		//Get moves from players
		playerMove(twoPlayer, playerSpaces, playerSpaces2);
		checkScore(playerSpaces, playerSpaces2, score);
		i++;
	} while (i < NUMSPACE);
	

	return 0;
}