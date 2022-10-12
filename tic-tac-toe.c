#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

void playerMove(const bool twoPlayer, bool spaces[NUMSPACE], bool spaces2[NUMSPACE])
{
	char getSpace = 0;
	printf("Player 1, please select a space by entering its number.\n");
	getSpace = get_answer();
	
	//Check for valid space choice and update space
	if ((getSpace - '0') > 0 && (getSpace - '0') < 10)
		spaces[(getSpace - '0') - 1] = true;
	if (twoPlayer == true)
	{
		printf("Player 2, please select a space by entering its number.\n");
		getSpace = get_answer();
	}
	
	//Check for valid space choice and update space
	if ((getSpace - '0') > 0 && (getSpace - '0') < 10)
		spaces2[(getSpace - '0') - 1] = true;
}

void checkScore(const bool twoPlayer, const bool spaces[NUMSPACE], const bool spaces2[NUMSPACE], 
	int currentScore[NUMPLAYER], int matchNum)
{
	//Compare to wins
	int comp[3] = {0, 0, 0};
	//Flag for winner
	int winner1 = 0;
	int winner2 = 0;
	//counter for loops
	int counter = 0;

	//While there are still combos of moves to compare

	//Get combo
	createCombo(spaces, &matchNum, comp);
	//While not a winner
	while (matchNum < (NUMSPACE/3) && !winner1 && comp[matchNum] != 0)
	{
		//Get combo
		createCombo(spaces, &matchNum, comp);
				
		//Compare combo
		winner1 = compareWin(comp);

		matchNum++;

	}

	matchNum = 0;

	//Get combo
	createCombo(spaces2, &matchNum, comp);
	
	//Get player 2 moves
	while (matchNum < (NUMSPACE/3) && !winner2 && comp[matchNum] != 0)
	{
		//Get combo
		createCombo(spaces2, &matchNum, comp);
				
		//Compare combo
		winner2 = compareWin(comp);

		matchNum++;
	}

	//If winner, update score
	if (winner1)
	{
		currentScore[0]++;
		printf("Player 1 won!\n");
	}
	else if (winner2)
	{
		currentScore[1]++;
		if (twoPlayer)
			printf("Player 2 won!\n");
		else
			printf("Computer won!\n");

	}
	else
	{
		if (matchNum > NUMSPACE/3)
			printf("It is a tie!\n");
	}
}

void drawBoard(const bool twoPlayer, const char symbol, const char symbol2, const int score_num[NUMPLAYER], 
	const bool spaces[NUMSPACE], const bool spaces2[NUMSPACE], char setBoard[][BOARDSIZE])
{
	int row = 0; //counter for rows of board
	int col = 0; //counter for columns of board
	int j = 0; //counter for loops
	int i = 0; //counter for loops
	char str[10]; //Used for converting integers to char

	//Print player info
	for (i = 0; i < (BOARDSIZE/3); i++)
		printf(" ");
	printf("Player 1  ");
	printf("%c", symbol);

	for (i = 0; i < (BOARDSIZE/3); i++)
		printf(" ");
	if (twoPlayer == true)
		printf ("Player 2  ");
	else
		printf ("Computer  ");
	printf ("%c\n", symbol2);

	for(i = 0; i < (BOARDSIZE/3); i++)
			printf(" ");
		printf("%d", score_num[j]);
		j++;
	for(i = 0; i < 2*(BOARDSIZE/3); i++)
		printf(" ");
	printf("%d\n", score_num[j]);
	printf("\n");
	i = 0;
	j = 0;

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
			else if (row == (BOARDSIZE/3) && (col == 1 ||
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
			//End line
			else if (col == (BOARDSIZE - 1))
				setBoard[row][col] = '\n';
			//Otherwise insert space
			else
				setBoard[row][col] = ' ';
		}
	
	i = 0;
	
	//Print board
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

	printf("\n");

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

int compareWin(const int compCombo[NUMSPACE/3])
{
	//Flag for winner
	int winner = 0;
	//Flag for empty or incomplete combo
	int empty = 0;
	//Counter for loops
	int i = 0;
	int j = 0;
	//buffer for getting winning combo
	int winCombo[3] = {0, 0, 0};

	//Check for empty combo
	for (i = 0; i < NUMCOMBO; i++)
	{
		if (compCombo[i] == winCombo[i])
			empty = 1;
	}
	
	//If empty combo, don't compare
	if (!empty)
	{
		//Compare move combo with all win combos
		for (i = 0; i < (NUMSPACE - 1); i++)
		{
			//Isolate winning combo for comparison
			for (j = 0; j < 3; j++)
				winCombo[j] = WINGAME[i][j];
			
			//If combo matches win combo, flag for winner
			if (!memcmp(compCombo, winCombo, sizeof(int)*NUMCOMBO))
				winner = 1;			
		}
	}
	
	return winner;
}

void createCombo(const bool spaces[], const int *match, int combo[])
{
	//Initialize
	int allSpaces[NUMSPACE];

	//Counter for loops
	int j = 0;

	for (int i = 0; i < NUMSPACE; i++)
		allSpaces[i] = 0;
	
	//Get all spaces occupied by player or computer
	for (int i = 0; i < NUMSPACE; i++)
	{
		if (spaces[i] == true)
		{
			allSpaces[j] = i + 1;
			j++;
		}
	}

	//Create Combo
	for (int i = 0; i < (NUMSPACE/3); i++)
		combo[i] = allSpaces[(*match) + i];
}