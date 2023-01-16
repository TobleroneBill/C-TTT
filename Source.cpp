// Draw Board
// Update Board
// Take input
// Check Lines

#include <iostream>

// Know this is bad practice, but just to make my life easier (std:: is carpal city D: )
using namespace std;

//Actual Chars used in board
char Positions[9] = {
' ',' ',' ',
' ',' ',' ',
' ',' ',' ',
};

bool CheckWinner(char Letter){
	// Check all winning streaks positions
	// Left to right
	if (Positions[0] == Letter and Positions[1] == Letter and Positions[2] == Letter) { return false; }
	if (Positions[3] == Letter and Positions[4] == Letter and Positions[5] == Letter) { return false; }
	if (Positions[6] == Letter and Positions[7] == Letter and Positions[8] == Letter) { return false; }

	// Top down
	if (Positions[0] == Letter and Positions[3] == Letter and Positions[6] == Letter) { return false; }
	if (Positions[1] == Letter and Positions[4] == Letter and Positions[7] == Letter) { return false; }
	if (Positions[2] == Letter and Positions[5] == Letter and Positions[8] == Letter) { return false; }

	// Diagonals
	if (Positions[0] == Letter and Positions[4] == Letter and Positions[8] == Letter) { return false; }
	if (Positions[2] == Letter and Positions[4] == Letter and Positions[6] == Letter) { return false; }
	//true if no matches
	return true;
}

// Renders the board
void DrawBoard() {
	std::cout << Positions[0] << "|" << Positions[1] << "|" << Positions[2]<< std::endl;
	std::cout << "-----" << std::endl;
	std::cout << Positions[3] << "|" << Positions[4] << "|" << Positions[5] << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << Positions[6] << "|" << Positions[7] << "|" << Positions[8] << std::endl;
}

// sets position in array to be x or o
bool PickSpace(int Position, int Player){
	if (Positions[Position] != ' ') {
		cout << "This Space is already taken";
		return false;
	}
	
	if (Player == 1) {
		Positions[Position] = 'x';

	}
	else {
		Positions[Position] = 'o';
	}
	return true;
}

int ErrorInput(){
	cin.clear();
	cin.ignore();
	printf("Incorrect Data Type\nTry again!\n");
	int input;
	cin >> input;
	return input;
}

int main() {
	bool Gaming = true;
	int Player = 1;
	int TurnCount = 0;
	while (Gaming) {
		system("CLS");
		DrawBoard();
		cout << "Player" << Player << endl;
		cout << "Pick a Position from 1-9: ";
		int Choice;
		cin >> Choice;
		// cin automatically checks for user input, but has to explicitly be used for it to matter. Otherwise It loops like crazy HAHAHAHAHAHAHAH (joker mode)
		// Keeps Checking for valid input
		while (cin.fail())
		{
			Choice = ErrorInput();
		}
		//-1 because of Array index
		if(!PickSpace(Choice-1, Player)){
			continue;
		}


		if (Player == 1) {
			if (!CheckWinner('x')) {
				system("CLS");
				DrawBoard();
				cout << "Player 1 Wins ;)\n";
				Gaming = false;
			}
		}
		else {
			if (!CheckWinner('o')) {
				system("CLS");
				DrawBoard();
				cout << "Player 2 Wins :D\n";
				Gaming = false;
			}
		}

		TurnCount++;
		if (TurnCount == 9) {
			cout << "U both suck and drew\n";
			Gaming = false;
		}
		// Swap Player
		if (Player == 1) {
			Player = 2;
		}
		else {
			Player = 1;
		}
	}

	system("pause");
}
