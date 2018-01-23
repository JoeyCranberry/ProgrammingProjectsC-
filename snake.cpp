#include <iostream>
#include <string.h>

using namespace std;

/*
* Draws the board
* X|O|X
* 0|0|0
* X|0|X
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

/*
* Checks the horizontal parts of the table, checkItem is an X or O.
* Returns true if the board is won.
*/
bool checkHorizontal( string locs[], int tableSize, string checkItem )
{
	// Counts up for every item in the row that is
	int count = 0;
	for( int i = 0; i < tableSize; i++ )
	{
		if( locs[ i ] == checkItem )
			count++;
		// If all the items in the row are the same, return true
		if( count == 3 )
			return true;
		// Reset the count once a new row is met
		if( ( i + 1 ) % 3 == 0 )
			count = 0;
	}
	return false;
}

/*
* Checks the vertical parts of the table, checkItem is an X or O.
* Returns true if the board is won.
*/
bool checkVertical( string locs[], int tableSize, string checkItem )
{
	int count = 0;
	for( int i = 0; i < 3; i++ )
	{
		if( locs[ i ] == checkItem )
			count++;
		// Check the vertical column
		// When i = 0, it checks ( 0 + ( 1 * 3 ) ) = 3, then:
		// 						 ( 0 + ( 2 * 3 ) ) = 6
		for( int j = 1; j < 3; j++ )
		{
			if( locs[ i + ( j * 3 )] == checkItem )
				count++;
		}
		if( count == 3 )
			return true;
		else
			count = 0;

	}
	return false;
}

/*
* Checks the diagonal parts of the table, checkItem is an X or O.
* Returns true if the board is won.
*/
bool checkDiagonal( string locs[], int tableSize, string checkItem )
{
	int count = 0;
	// Pass One - for a board of three checks: 0, 4, 8
	for( int i = 0; i < ( 3 * 3 ); i += ( 3 + 1 ) )
	{
		if( locs[ i ] == checkItem )
			count++;
	}
	if( count == 3 )
		return true;
	else
		count = 0;

	// Pass Two - for a board of three checks: 2, 4, 6
	for( int j = ( 3 - 1 ); j < ( 3 * ( 3 - 1 ) ) + 1 ; j += ( 3 - 1 ) )
	{
		if( locs[ j ] == checkItem )
			count++;
	}
	if( count == 3 )
		return true;

	return false;
}

/*
* Checks the board for an end game condition:
* Full board
* Horizontal Win
* Vertical Win
* Diagonal Win
*/
bool checkEndGameConditions( string locs[], int tableSize )
{
	// If the board is full
	int count = 0;
	for( int i = 0; i < tableSize; i++ )
	{
		if( locs[ i ] != " " )
			count++;
	}
	if( count == tableSize )
	{
		cout << "Board Full - Game Draw." << endl;
		return true;
	}

	// If there is a horizontal win
	if( checkHorizontal( locs, tableSize, "X" ) ||
	checkVertical( locs, tableSize, "X" )  ||
	checkDiagonal( locs, tableSize, "X" ) )
	{
		cout << "X Wins." << endl;
		return true;
	}

	if( checkHorizontal( locs, tableSize, "O" ) ||
	checkVertical( locs, tableSize, "O" )  ||
	checkDiagonal( locs, tableSize, "O" ) )
	{
		cout << "O Wins.";
		return true;
	}


	return false;
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
		{
			cout << "Game end." << endl;
			gameWin = true;
		}

	}

	return 0;
}
