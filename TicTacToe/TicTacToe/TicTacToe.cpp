// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void board(int move, int player);
bool checkGame();

char boardArray[3][3] = { {'1','2','3'},
							{'4','5','6'},
							{'7','8','9'} };

int main()
{
	int track{ 0 };
	int player{ 1 }; 
	int move{};
	int i{};
	int j{};
	char mark{};
	board(track, player);
	while (track >= 0)
	{
		
		cin >> move;
		
		if (move == 1)
		{
			i = 0;
			j = 0;
		}
		else if (move == 2)
		{
			i = 0;
			j = 1;
		}
		else if (move == 3)
		{
			i = 0;
			j = 2;
		}
		else if (move == 4)
		{
			i = 1;
			j = 0;
		}
		else if (move == 5)
		{
			i = 1;
			j = 1;
		}
		else if (move == 6)
		{
			i = 1;
			j = 2;
		}
		else if (move == 7)
		{
			i = 2;
			j = 0;
		}
		else if (move == 8)
		{
			i = 2;
			j = 1;
		}
		else if (move == 9)
		{
			i = 2;
			j = 2;
		}
		else
		{
			cout << "Error: Input is outside of the index" << endl;
			return track=-1;
		}
		boardArray[i][j] = (player == 1)? 'X':'O';
		track = track++;
		if (player == 1)
		{
			player = 2;
		}
		else
		{
			player = 1;
		}
		board(track, player);
		if (checkGame())
			track = -1;
	}
	cout << "Player: " << player << " has won!" << endl;
	return 0;
}

void board(int move, int player)
{
	system("cls");

	cout << endl;
	cout << endl;
	cout << "MOVE:   " << move << endl;
	cout << endl;
	cout << "\t     |     |      " << endl; 
	cout << "\t "<< boardArray[0][0] <<"   |  "<< boardArray[0][1] <<"  |   "<< boardArray[0][2] <<"   " << endl;
	cout << "\t     |     |      " << endl;
	cout << "      ---------------------" << endl;
	cout << "\t     |     |      " << endl;
	cout << "\t " << boardArray[1][0] << "   |  " << boardArray[1][1] << "  |   " << boardArray[1][2] << "   " << endl;
	cout << "\t     |     |      " << endl;
	cout << "      ---------------------" << endl;
	cout << "\t     |     |      " << endl;
	cout << "\t " << boardArray[2][0] << "   |  " << boardArray[2][1] << "  |   " << boardArray[2][2] << "   " << endl;
	cout << "\t     |     |      " << endl;
	cout << endl;
	cout << endl;
	cout << "----------------------------------------------\n";
	cout << "Enter Move Player_" << player << ">>";

}

bool checkGame() 
{

	//column check
	for (int i = 0; i<=2; i++)
	{
		if ((boardArray[0][i] == boardArray[1][i]) && (boardArray[1][i] == boardArray[2][i]))
		{
			return true;
		}
		
	}
	//row check
	for (int j = 0; j<=2; j++)
	{
		if ((boardArray[j][0] == boardArray[j][1]) && (boardArray[j][1] == boardArray[j][2]))
		{
			return true;
		}
	}
	// diagonal check
	if ((boardArray[0][0] == boardArray[1][1]) && (boardArray[1][1] == boardArray[2][2]))
	{
		return true;
	}
	else if ((boardArray[0][2] == boardArray[1][1]) && (boardArray[1][1] == boardArray[2][0]))
	{
		return true;
	}
	return false;
}

