#include <iostream>
#include <string.h>

using namespace std;

/*
* Draws the board
* X|O|X
* 0|0|0
* X|0|X
* 013467
*/
void drawBoard( string locs[], int tableSize )
{
	// Print out the board
	for( int i = 0; i < tableSize; i++ )
	{
		cout << locs[ i ];
		if( ( i + 1 ) % 3 == 0 )
			cout << endl;
		else
			cout << "|";
	}

}

bool checkEndGameConditions( string locs[], int tableSize )
{
	// If the board is full
	int count;
	for( int i = 0; i < tableSize; i++ )
	{
	}

}

int main()
{
	int tableSize = 9;
	string table [ tableSize ] = { " " };

	for( int i = 0; i < tableSize; i++ )
		table[ i ] = " ";
	drawBoard( table, tableSize );

	// Player = true is O, Player = false is X
	bool gameWin = false, player = true;
	// Which tile to change
	int move;
	while( !gameWin )
	{
		cout << "Enter player move: ";
		cin >> move;
		if( table[ move ] != " " )
			cout << "Invalid move: move already used." << endl;
		else if( move > tableSize || move < tableSize )
		{
			if( player )
			{
				table[ move ] = "O";
				player = false;
			}
			else if( !player )
			{
				table[ move ] = "X";
				player = true;
			}
		}
		else
			cout << "Invalid move: outside of play board." << endl;

		// After the move has been made, re-draw the board
		drawBoard( table, tableSize );

		// Test for game end conditions"
		if( checkEndGameConditions( table, tableSize ) )
			cout << end << "Game end.";

	}

	return 0;
}
