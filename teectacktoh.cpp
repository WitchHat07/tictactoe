#include <iostream>
#include <vector>

using namespace std;

void intro_text();
void display_gameboard(vector<char> boardish);

int main() {
	intro_text();
	vector<char> board;
	for (int i = 1; i <= 9; i++) {
		board.push_back('-');
	}
	display_gameboard(board);
	char one = '-', two = '-', three = '-', four = '-', five = '-', six = '-', seven = '-', eight = '-', nine = '-';
	int turn = 0;
	bool win = 0;
	while (true) {
		int move_choice;
		if (turn % 2 == 0) {
			cout << "X, it is your turn! Choose a place (1-9): ";
			cin >> move_choice;
			if (move_choice > 10 || move_choice <= 0) {
				cout << "Please choose a section on the board!\n";
				continue;
			}
			switch (move_choice) {
			case 1:
				board[0] = 'X';
				break;
			case 2:
				board[1] = 'X';
				break;
			case 3:
				board[2] = 'X';
				break;
			case 4:
				board[3] = 'X';
				break;
			case 5:
				board[4] = 'X';
				break;
			case 6:
				board[5] = 'X';
				break;
			case 7:
				board[6] = 'X';
				break;
			case 8:
				board[7] = 'X';
				break;
			case 9:
				board[8] = 'X';
				break;
			default:
				cout << "Please choose a section of the board!";
				break;
			}
			cout << "\n";
			display_gameboard(board);
			turn += 1;
			if ((one == 'X' && two == 'X' && three == 'X') || (four == 'X' && five == 'X' && six == 'X') || (seven == 'X' && eight == 'X' && nine == 'X') ||
				(one == 'X' && four == 'X' && seven == 'X') || (two == 'X' && five == 'X' && eight == 'X') || (three == 'X' && six == 'X' && nine == 'X') ||
				(one == 'X' && five == 'X' && nine == 'X') || (three == 'X' && five == 'X' && seven == 'X')) {
				win = 1;
			}
			if (!win) {
				continue;
			}
			else {
				break;
			}
		}
		else if (turn % 2 == 1) {
			cout << "O, it is your turn! Choose a place (1-9): ";
			cin >> move_choice;
			switch (move_choice) {
			case 1:
				board[0] = 'O';
				break;
			case 2:
				board[1] = 'O';
				break;
			case 3:
				board[2] = 'O';
				break;
			case 4:
				board[3] = 'O';
				break;
			case 5:
				board[4] = 'O';
				break;
			case 6:
				board[5] = 'O';
				break;
			case 7:
				board[6] = 'O';
				break;
			case 8:
				board[7] = 'O';
				break;
			case 9:
				board[8] = 'O';
				break;
			}
			cout << "\n";
			display_gameboard(board);
			turn += 1;
			if ((one == 'O' && two == 'O' && three == 'O') || (four == 'O' && five == 'O' && six == 'O') || (seven == 'O' && eight == 'O' && nine == 'O') ||
				(one == 'O' && four == 'O' && seven == 'O') || (two == 'O' && five == 'O' && eight == 'O') || (three == 'O' && six == 'O' && nine == 'O') ||
				(one == 'O' && five == 'O' && nine == 'O') || (three == 'O' && five == 'O' && seven == 'O')) {
				win = 1;
			}
			if (!win) {
				continue;
			}
			else {
				break;
			}
		}
		else {
			cout << "How even?!";
		}
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
		<< board[3]	<< "  |  " << board[4] << "  |  " << board[5] << '\n'
		<< board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n\n";
}