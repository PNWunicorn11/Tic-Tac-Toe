#include <stdio.h>
#include <stdbool.h>
#include "tic-tac-toe.h"

void gameSetup(bool twoPlayer, char symbol, char symbol2, bool comPlayer,
	int score_num[NUMPLAYER], int spaces[NUMSPACE],
	int spaces2[NUMSPACE], space board[][BOARDSIZE])
{
	//Welcome player and ask if two human players
	printf("Welcome to Tic Tac Toe!\n");
	printf("Two player (y/n)?\n");
	symbol = get_answer();
	//Check for correct letter. If not correct, ask again
	while (symbol != 'n' && symbol != 'y')
	{
		printf("Please enter 'y' for yes or 'n' for no.\n");
		symbol = get_answer();
		
	}

	if (symbol == 'y')
			twoPlayer = true;
		if (symbol == 'n')
			comPlayer = true;
	//Get player symbol and set player 2 or computer symbol
	//If incorrect letter is entered, ask again
	printf("Please enter your symbol (x/o)\n");
	symbol = get_answer();


	while (symbol != 'x' && symbol != 'o')
	{
		printf("You must enter 'x' or 'o'\n");
		symbol = get_answer();
	}

	if (symbol == 'x')
		symbol2 = 'o';
	if (symbol == 'o')
		symbol2 = 'x';

	//Initialize score value
	for (int i = 0; i < NUMPLAYER; i++)
	{
		score_num[i] = 0;
	}

	//Initialize spaces value
	for (int i = 0; i < NUMSPACE; i++)
	{
		spaces[i] = 0;
		spaces2[i] = 0;
	}

	//Initialize game board
	for (int i; i < BOARDSIZE; i++)
	{
		board[i][i].spaceNum = i + 1;
		board[i][i].spaceSymbol = 0;
	}

}

int get_answer(void)
{
	int c;
	int answer = 0;

	while ((c = getchar()) != EOF && c != '\n')
	{
		if (answer == 0)
			answer = c;
	}

	return answer;
}