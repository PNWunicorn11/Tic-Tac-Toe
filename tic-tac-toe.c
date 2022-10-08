#include <stdio.h>
#include <stdbool.h>
#include "tic-tac-toe.h"

void gameSetup(bool *twoPlayer, char *symbol, char *symbol2, bool *comPlayer,
	int score_num[NUMPLAYER], bool spaces[NUMSPACE],
	bool spaces2[NUMSPACE], char setBoard[][BOARDSIZE])
{
	//Welcome player and ask if two human players
	printf("Welcome to Tic Tac Toe!\n");
	printf("Two player (y/n)?\n");
	*symbol = get_answer();
	//Check for correct letter. If not correct, ask again
	while (*symbol != 'n' && *symbol != 'y')
	{
		printf("Please enter 'y' for yes or 'n' for no.\n");
		*symbol = get_answer();
		
	}

	if (*symbol == 'y')
		*twoPlayer = true;
	if (*symbol == 'n')
		*comPlayer = true;
	//Get player symbol and set player 2 or computer symbol
	//If incorrect letter is entered, ask again
	printf("Please enter your symbol (x/o)\n");
	*symbol = get_answer();


	while (*symbol != 'x' && *symbol != 'o')
	{
		printf("You must enter 'x' or 'o'\n");
		*symbol = get_answer();
	}

	if (*symbol == 'x')
	{
		*symbol = 'X';
		*symbol2 = 'O';
	}
	else
	{
		*symbol = 'O';
		*symbol2 = 'X';
	}

	//Initialize score value
	for (int i = 0; i < NUMPLAYER; i++)
	{
		score_num[i] = 0;
	}

	//Initialize spaces value
	for (int i = 0; i < NUMSPACE; i++)
	{
		spaces[i] = false;
		spaces2[i] = false;
	}

	//Initialize game board
	for (int i = 0; i < BOARDSIZE; i++)
		for (int j = 0; j < BOARDSIZE; j++)
		{
			setBoard[i][j] = 0;
		}

}

void drawBoard(bool twoPlayer, char symbol, char symbol2, int score_num[NUMPLAYER], 
	bool spaces[NUMSPACE], bool spaces2[NUMSPACE], char printBoard[][BOARDSIZE])
{
	int row = 0; //counter for rows of board
	int col = 0; //counter for columns of board
	//Print player info
	for (int i = 0; i < (BOARDSIZE/3); i++)
		printf(" ");
	printf("Player 1\t");
	printf("%c", symbol);

	for (int i = 0; i < (BOARDSIZE/3) - 25; i++)
		printf(" ");
	if (twoPlayer == true)
		printf ("Player 2\t");
	else
		printf ("Computer\t");
	printf ("%c\n", symbol2);

	for(int i = 0; i < (BOARDSIZE/3); i++)
			printf(" ");
		printf("%d", score_num[j]);

	for(int i = 0; i < (BOARDSIZE/3) - 15; i++)
		printf(" ");
	printf("%d\n", score_num[j]);
	j++;

	//Print board
	for (int row = 0; row < (BOARDSIZE/3); row++)
		for (col = 0; col < BOARDSIZE; col++)
		{	//Store first or last row
			if (row == 0 || row == BOARDSIZE)
				if (col == (BOARDSIZE/3) || col == 2(BOARDSIZE/3))
					setBoard[i][j] = '|';
			//Store space numbers 
			if (row == 2 && (col == 2 || col == (BOARDSIZE/3) + 2)) 
				setBoard[i][j] = ;
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