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
	bool spaces[NUMSPACE], bool spaces2[NUMSPACE], char setBoard[][BOARDSIZE])
{
	int row = 0; //counter for rows of board
	int col = 0; //counter for columns of board
	int j = 0; //counter for loops
	int i = 0; //counter for loops
	char str[10]; //Used for converting integers to char

	//Print player info
	for (int i = 0; i < (BOARDSIZE/3); i++)
		printf(" ");
	printf("Player 1  ");
	printf("%c", symbol);

	for (int i = 0; i < (BOARDSIZE/3); i++)
		printf(" ");
	if (twoPlayer == true)
		printf ("Player 2  ");
	else
		printf ("Computer  ");
	printf ("%c\n", symbol2);

	for(int i = 0; i < (BOARDSIZE/3); i++)
			printf(" ");
		printf("%d", score_num[j]);

	for(int i = 0; i < (BOARDSIZE/3) + 10; i++)
		printf(" ");
	printf("%d\n", score_num[j]);
	printf("\n");

	//Preparing to print board
	//Store first row of spaces
	for (row = 0; row < (BOARDSIZE/3); row++)
		for (col = 0; col < BOARDSIZE; col++)
		{	
			//Store vertical lines
			if (col == ((BOARDSIZE/3) - 1) || col == (2*(BOARDSIZE/3) - 1))
				setBoard[row][col] = '|';
			//Store space numbers 
			else if (row == 1 && (col == 2 || col == ((BOARDSIZE/3) + 1)
				|| col == (2*(BOARDSIZE/3) + 1)))
			{
				//store counter as char
				sprintf(str, "%d", j + 1);
				setBoard[row][col] = str[0];
				j++;
			} //Store horizontal line
			else if (row == ((BOARDSIZE/3) - 6) && col < (BOARDSIZE - 1))
				setBoard[row][col] = '-';
			else if (col == (BOARDSIZE - 1))
				setBoard[row][col] = '\n';
			else
				setBoard[row][col] = ' ';
			
		}
	//Store second row of spaces
	/*for (row = (BOARDSIZE/3) + 1; row < BOARDSIZE; row++)
		for (col = 0; col <= BOARDSIZE; col++)
		{
			//Store space numbers
			if (row == ((BOARDSIZE/3) + 1) && (col == 2 ||
				col == ((BOARDSIZE/3) + 2) ||
				col == (2*(BOARDSIZE/3))))
			{
				//store counter as char
				sprintf(str, "%d", j + 1);
				setBoard[row][col] = str[0];
				j++;
			}
			else if (col == BOARDSIZE)
				setBoard[row][col] = '\n';
			else
				setBoard[row][col] = ' ';
		}*/

	//Print two rows of spaces
		for (row = 0; row < BOARDSIZE; row++)
		{
			//Center board
			while (i < 7)
			{
				printf(" ");
				i++;
			}
			i = 0;
		
			for (col = 0; col < BOARDSIZE; col++)
			{	
				printf("%c", setBoard[row][col]);
			}
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