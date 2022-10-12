#include <iostream>
#include <vector>
#include <limits>

using namespace std;

<<<<<<< Updated upstream
void display_gameboard(vector<char> boardish);
vector<char> board;
int turn = 0;
char player;
bool win = 0;
char champ;
char continue_choice = 'y';
int move_choice;

int Main() {
	IntroText();

	for (int i = 1; i <= 9; i++) {
		board.push_back('-');
=======
// Params
vector<char> board;
int boardSize = 9;
int turn = 0;
char player;
char champ;
int xWins = 0;
int oWins = 0;
char isWantingToPlay = 'y';
int playerChoice = -1;

// Helper Methods
void ShowIntroText() {
	cout << "> Witch-Tet-Su!\n"
		<< "> Rules: X starts first! Type 1-9 to input your move! The game will automatically alternate turns.\n"
		<< "> This is the gameboard. It is sorted like a numpad: \n"
		<< "> 7  |  8  |  9\n"
		<< "> 4  |  5  |  6\n"
		<< "> 1  |  2  |  3\n"
		<< "> Three X's or O's wins!\n"
		<< "> Let's Begin, bitch!\n\n";
}
void ShowGameBoard() {
	cout << board[6] << "  |  " << board[7] << "  |  " << board[8] << '\n'
		<< board[3] << "  |  " << board[4] << "  |  " << board[5] << '\n'
		<< board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n\n";
}
void ResetGameBoard() {
	board.clear();
	for (int i = 0; i < boardSize; i++) board.push_back('-');
	turn = 0;
}
void DeterminePlayer() {
	if (turn % 2 == 0) player = 'X';
	else player = 'O';
}
bool ValidChoice(int input) {
	if(input < 1 || input > 9) {
		cout << "> That's not a valid input dude. Gotta be a number between 1 and 9 atleast...\n";	
		return false;
>>>>>>> Stashed changes
	}
	else if(board[input - 1] != '-') {
		cout << "> That spot isn't free, champ. Try again!\n";	
		return false;
	}
	else return true;
}
int GetPlayerChoice() {
	cout << "> " << player << ", it is your turn! Choose a place (1-9):\n";

<<<<<<< Updated upstream
	while (tolower(continue_choice) == 'y') {
		display_gameboard(board);
		while (!win) {
			if (turnIsOdd()) player = 'X';
			else player = 'O';

			for (;;) {
				cout << player << ", it is your turn! Choose a place (1-9): ";
				if (cin >> move_choice) {
					break;
				}
				else {
					cout << "\nPlease enter a position 1-9!\n\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
			if (move_choice > 10 || move_choice <= 0 || board[move_choice - 1] != '-') {
				cout << "\nPlease choose an available section on the board!\n\n";
				continue;
			}

			board[move_choice - 1] = player;
			cout << "\n";
			display_gameboard(board);
			
			turn++;
		}

		board.clear();
		for (int i = 1; i <= 9; i++) {
			board.push_back('-');
=======
	cin >> playerChoice;
	while(true)
	{
		if(!ValidChoice(playerChoice))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//cout << "Uhh bad input\n";
			cin >> playerChoice;
>>>>>>> Stashed changes
		}
		else break;
	}
	return playerChoice;
}
void MarkGameBoard(int index) {
	board[index] = player;
	cin.clear();
}
bool PlayerHasWon() {
	if ((board[0] == player && board[1] == player && board[2] == player) || (board[3] == player && board[4] == player && board[5] == player) || (board[6] == player && board[7] == player && board[8] == player) ||
		(board[0] == player && board[3] == player && board[6] == player) || (board[1] == player && board[4] == player && board[7] == player) || (board[2] == player && board[5] == player && board[8] == player) ||
		(board[0] == player && board[4] == player && board[8] == player) || (board[2] == player && board[4] == player && board[6] == player)) {

<<<<<<< Updated upstream
void IntroText() {
	cout << "Tic-Tac-Toe!\n\n"
		<< "Rules: X starts first! Type 1-9 to input your move! The game will automatically alternate turns.\n"
		<< "This is the gameboard. It is sorted like a numpad: \n\n"
		<< "7  |  8  |  9\n"
		<< "4  |  5  |  6\n"
		<< "1  |  2  |  3\n"
		<< "\nThree X's or O's wins!\n"
		<< "Let's Begin!\n\n";
}

bool PlayerHasWon() {
	if ((board[0] == player && board[1] == player && board[2] == player) || (board[3] == player && board[4] == player && board[5] == player) || (board[6] == player && board[7] == player && board[8] == player) ||
		(board[0] == player && board[3] == player && board[6] == player) || (board[1] == player && board[4] == player && board[7] == player) || (board[2] == player && board[5] == player && board[8] == player) ||
		(board[0] == player && board[4] == player && board[8] == player) || (board[2] == player && board[4] == player && board[6] == player)) 
	{
		win = 1;
		champ = player;
		return true;
	}
	else return false;
}

bool TurnIsOdd()
{
	turn % 2 == 0
}

bool diagonal_win

void ClearBoard()
{
	
}

void display_gameboard(vector<char> charVec) {
	vector<char> board = charVec;
	cout << board[6] << "  |  " << board[7] << "  |  " << board[8] << '\n'
		<< board[3] << "  |  " << board[4] << "  |  " << board[5] << '\n'
		<< board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n\n";
=======
		champ = player;
		if(player == 'X') xWins++;
		else oWins++;

		return true;
	} else return false;
}
bool EndOrContinue() {
	cout << "> " << champ << " is victorious!\n"
		 << "> score: X " << xWins << ", O " << oWins
		<< "\n> Play another game? (y/n):\n";
	cin >> isWantingToPlay;
}

// Main
int main() {
	ShowIntroText();

	while (tolower(isWantingToPlay) == 'y') {
		ResetGameBoard();
		ShowGameBoard();
		while (!PlayerHasWon()) {
			int choice;
			DeterminePlayer();
			choice = GetPlayerChoice();
			MarkGameBoard(choice - 1);
			ShowGameBoard();
			turn++;
		}

		EndOrContinue();
	}

	cout << "> Alright, さようなら.";
	return 0;
>>>>>>> Stashed changes
}