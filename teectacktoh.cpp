#include <iostream>
#include <vector>

using namespace std;

void intro_text();
void display_gameboard(char oneP, char twoP, char threeP, char fourP, char fiveP, char sixP, char sevenP, char eightP, char nineP);

int main() {
	intro_text();
	/* TODO: integrate gameboard into an array or vector of some sort
	vector<char> board;
	for (int i = 1; i <= 9; i++) {
		board.push_back('-');
	}
	*/
	char one = '-', two = '-', three = '-', four = '-', five = '-', six = '-', seven = '-', eight = '-', nine = '-';
	display_gameboard(one, two, three, four, five, six, seven, eight, nine);
	int turn = 0;
	bool win = 0;
	while (true) {
		int move_choice;
		if (turn % 2 == 0) {
			cout << "X, it is your turn! Choose a place (1-9): ";
			cin >> move_choice;
			switch (move_choice) {
			case 1:
				one = 'X';
				break;
			case 2:
				two = 'X';
				break;
			case 3:
				three = 'X';
				break;
			case 4:
				four = 'X';
				break;
			case 5:
				five = 'X';
				break;
			case 6:
				six = 'X';
				break;
			case 7:
				seven = 'X';
				break;
			case 8:
				eight = 'X';
				break;
			case 9:
				nine = 'X';
				break;
			}
			cout << "\n";
			display_gameboard(one, two, three, four, five, six, seven, eight, nine);
			turn += 1;
			if ((one == 'X' && two == 'X' && three == 'X') || (four == 'X' && five == 'X' && six == 'X')) {
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
				one = 'O';
				break;
			case 2:
				two = 'O';
				break;
			case 3:
				three = 'O';
				break;
			case 4:
				four = 'O';
				break;
			case 5:
				five = 'O';
				break;
			case 6:
				six = 'O';
				break;
			case 7:
				seven = 'O';
				break;
			case 8:
				eight = 'O';
				break;
			case 9:
				nine = 'O';
				break;
			}
			cout << "\n";
			display_gameboard(one, two, three, four, five, six, seven, eight, nine);
			turn += 1;
			continue;
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

void display_gameboard(char oneP, char twoP, char threeP, char fourP, char fiveP, char sixP, char sevenP, char eightP, char nineP) {
	cout << sevenP << "  |  " << eightP << "  |  " << nineP << endl
		<< fourP << "  |  " << fiveP << "  |  " << sixP << endl
		<< oneP << "  |  " << twoP << "  |  " << threeP << endl << endl;
}