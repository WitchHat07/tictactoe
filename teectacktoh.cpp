#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void intro_text();
void display_gameboard(vector<char> boardish);

int main() {
	intro_text();
	vector<char> board;
	for (int i = 1; i <= 9; i++) {
		board.push_back('-');
	}

	int turn = 0;
	char player;
	bool win = 0;
	char champ;
	char continue_choice = 'y';
	int move_choice;

	while (tolower(continue_choice) == 'y') {
		display_gameboard(board);
		while (!win) {
			if (turn % 2 == 0) {
				player = 'X';
			}
			else {
				player = 'O';
			}

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
			
			if ((board[0] == player && board[1] == player && board[2] == player) || (board[3] == player && board[4] == player && board[5] == player) || (board[6] == player && board[7] == player && board[8] == player) ||
				(board[0] == player && board[3] == player && board[6] == player) || (board[1] == player && board[4] == player && board[7] == player) || (board[2] == player && board[5] == player && board[8] == player) ||
				(board[0] == player && board[4] == player && board[8] == player) || (board[2] == player && board[4] == player && board[6] == player)) {
				win = 1;
				champ = player;
			}
			turn += 1;
		}

		board.clear();
		for (int i = 1; i <= 9; i++) {
			board.push_back('-');
		}
		turn = 0;
		win = 0;
		cout << champ << " is victorious!\n"
			<< "Play another game? (y/n): ";
		cin >> continue_choice;
		cout << '\n';
	}
	return 0;
}

void intro_text() {
	cout << "Tic-Tac-Toe!\n\n"
		<< "Rules: X starts first! Type 1-9 to input your move! The game will automatically alternate turns.\n"
		<< "This is the gameboard. It is sorted like a numpad: \n\n"
		<< "7  |  8  |  9\n"
		<< "4  |  5  |  6\n"
		<< "1  |  2  |  3\n"
		<< "\nThree X's or O's wins!\n"
		<< "Let's Begin!\n\n";
}

void display_gameboard(vector<char> boardish) {
	vector<char> board = boardish;
	cout << board[6] << "  |  " << board[7] << "  |  " << board[8] << '\n'
		<< board[3] << "  |  " << board[4] << "  |  " << board[5] << '\n'
		<< board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n\n";
}