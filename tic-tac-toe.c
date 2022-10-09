#include <stdio.h>
#include <stdbool.h>
#include "tic-tac-toe.h"

void gameSetup(bool *twoPlayer, char *symbol, char *symbol2, int score_num[NUMPLAYER], 
	bool spaces[NUMSPACE], bool spaces2[NUMSPACE], char setBoard[][BOARDSIZE])
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
	i = 0;
	//Preparing to print board
	//Store first row of spaces
	for (row = 0; row < (BOARDSIZE/3); row++)
		for (col = 0; col < BOARDSIZE; col++)
		{	
			//Store vertical lines
			if (col == ((BOARDSIZE/3) - 1) || col == (2*(BOARDSIZE/3) - 1))
				setBoard[row][col] = '|';
			//Store space numbers 
			else if (row == 0 && (col == 1 || col == ((BOARDSIZE/3) + 1)
				|| col == (2*(BOARDSIZE/3) + 1)))
			{
				//store counter as char
				sprintf(str, "%d", j + 1);
				setBoard[row][col] = str[0];
				j++;
			}
			//Store space symbol
			else if (row == ((BOARDSIZE/3) - 8) && (col == 3 ||
				col == ((BOARDSIZE/3) + 3) || col == (2*(BOARDSIZE/3) + 3)))
			{
				if (spaces[i] == true)
					setBoard[row][col] = symbol;
				else if (spaces2[i] == true)
					setBoard[row][col] = symbol2;
				else
					setBoard[row][col] = ' ';
				i++;

			}	 
			//Store horizontal line
			else if (row == ((BOARDSIZE/3) - 6) && col < (BOARDSIZE - 1))
				setBoard[row][col] = '-';
			else if (col == (BOARDSIZE - 1))
				setBoard[row][col] = '\n';
			else
				setBoard[row][col] = ' ';
			
		}
	//Store second and third rows of spaces
	for (row = (BOARDSIZE/3) - 5; row < (2*(BOARDSIZE/3) - 6); row++)
		for (col = 0; col < BOARDSIZE; col++)
		{
			//Store vertical lines
			if (col == ((BOARDSIZE/3) - 1) || col == (2*(BOARDSIZE/3) - 1))
				setBoard[row][col] = '|';
			//Store second row space numbers
			else if (row == ((BOARDSIZE/3) - 5) && (col == 1 ||
				col == ((BOARDSIZE/3) + 1) ||
				col == (2*(BOARDSIZE/3) + 1)))
			{
				//store counter as char
				sprintf(str, "%d", j + 1);
				setBoard[row][col] = str[0];
				j++;
			}
			//Store third row space numbers
			else if (row == (2*(BOARDSIZE/3) - 10) && (col == 1 ||
				col == ((BOARDSIZE/3) + 1) ||
				col == (2*(BOARDSIZE/3) + 1)))
			{
				//Store counter as char
				sprintf(str, "%d", j + 1);
				setBoard[row][col] = str[0];
				j++;
			}
			//Store second row symbols
			else if (row == (2*(BOARDSIZE/3) - 13) && (col == 3 ||
				col == ((BOARDSIZE/3) + 3) || col == (2*(BOARDSIZE/3) + 3)))
			{
				if (spaces[i] == true)
					setBoard[row][col] = symbol;
				else if (spaces2[i] == true)
					setBoard[row][col] = symbol2;
				else
					setBoard[row][col] = ' ';
				i++;

			}
			//Store third row symbols
			else if (row == (2*(BOARDSIZE/3) - 8) && (col == 3 ||
				col == ((BOARDSIZE/3) + 3) || col == (2*(BOARDSIZE/3) + 3)))
			{
				if (spaces[i] == true)
					setBoard[row][col] = symbol;
				else if (spaces2[i] == true)
					setBoard[row][col] = symbol2;
				else
					setBoard[row][col] = ' ';
				i++;

			}
			//Store horizontal line
			else if (row == (2*(BOARDSIZE/3) - 11) && col < (BOARDSIZE - 1))
				setBoard[row][col] = '-';
			else if (col == (BOARDSIZE - 1))
				setBoard[row][col] = '\n';
			else
				setBoard[row][col] = ' ';
		}
	i = 0;
	//Print two rows of spaces
	for (row = 0; row < BOARDSIZE; row++)
	{
		//Center board
		while (i < 9)
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