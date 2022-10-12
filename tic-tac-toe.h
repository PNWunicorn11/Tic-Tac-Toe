#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

//size of game board
extern const int BOARDSIZE;
extern const int NUMSPACE;
extern const int NUMPLAYER;
//Number of spaces in a winning combo
extern const int NUMCOMBO;
extern const int WINGAME[][3];

/*//Info needed for each space of board
typedef const struct
{
	int win1_row[(BOARDSIZE/3) - 1] = {1, 2, 3};
	int win1_col[(BOARDSIZE/3) - 1] = {1, 4, 7};
	int win1_diag[(BOARDSIZE/3) - 1] = {1, 5, 9};
	int win2_col[(BOARDSIZE/3) - 1] = {2, 5, 8};
	int win3_col[(BOARDSIZE/3) - 1] = {3, 6, 9};
	int win4_row[(BOARDSIZE/3) - 1] = {4, 5, 6};
	int win7_row[(BOARDSIZE/3) -1] = {7, 8, 9};
} winGame;*/

//Sets up the game initial values
void gameSetup(bool *twoPlayer, char *symbol, char *symbol2, int score_num[], 
	bool spaces[], bool spaces2[], char setBoard[][BOARDSIZE]);
//Gets each player (or computer) move
void playerMove(const bool twoPlayer, bool spaces[], bool spaces2[]);
//Checks score and updates
void checkScore(const bool twoPlayer, const bool spaces[], const bool spaces2[], 
	int currentScore[], int match);
//Prints player scores and game board
void drawBoard(const bool twoPlayer, const char symbol, const char symbol2, const int score_num[], 
	const bool spaces[], const bool spaces2[], char printBoard[][BOARDSIZE]);
//Gets input from stdin
int get_answer(void);
//Compares move combo with win combo
int compareWin(const int compCombo[]);
void createCombo(const bool spaces[], const int *match, int combo[]);

#endif