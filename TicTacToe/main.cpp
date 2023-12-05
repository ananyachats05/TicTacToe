#include<iostream>
#include<string>
using namespace std;

const int rows = 3;
const int columns = 3;

void startGame();
void setUpGameBoard(string gameBoard[rows][columns]);
void currentBoardVisual(string gameBoard[rows][columns]);
void userEntry(bool xTurn, string gameBoard[rows][columns]);
void cellAvailableOrNot(int row, int column, string gameBoard[rows][columns]);
string decWinner(string gameBoard[rows][columns]);
bool isBoardFull(string gameBoard[rows][columns]);

int main()
{
	startGame();

	return 0;

}
// ---------------------------------------------------------\\
//------------The game loop : startGame---------------------\\
//-----------------------------------------------------------\\

void startGame()
{
	string winner = "";// signifies no winner yet
	bool xTurn = true; //X gets the first chance
	int yourRow = 0;
	int yourCol = 0;
	string gameBoard[rows][columns];
	
	setUpGameBoard(gameBoard);
	//current board print
	currentBoardVisual(gameBoard);

	while (winner == "")
	{
		if (xTurn)
		{
			cout << "It's X's turn " << endl;
		}
		else
			cout << " It's O's turn" << endl;
		userEntry(xTurn, gameBoard);
		cout<< endl;
		currentBoardVisual(gameBoard); // board visual after each entry is made by the players
		winner = decWinner(gameBoard); //check if any one has won
		xTurn = !xTurn;// chance goes to O

		if (winner == "" && isBoardFull(gameBoard))
		{
			winner = "C"; // no winner...it is a cat's game!
		}
	}// enteries for while loop done

	cout << endl;
	if (winner == "C")
	{
		cout << "It was a CAT's game hence, no winner" << endl;
	}
	else
	{
		cout << "The winner is " << winner << endl;
	}
	cout << endl;
}
//-----------------------------------------------------\\
//---------Setting Up The Board------------------------\\
//------------------------------------------------------\\

void setUpGameBoard(string gameBoard[rows][columns])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			gameBoard[i][j] = " "; //empty intially
		}
	}

}
//-----------------------------------------------------\\
//-----------Current Board Visual as a matrix----------\\
//------------------------------------------------------\\

void currentBoardVisual(string gameBoard[rows][columns])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << gameBoard[i][j];
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2)
		{
			cout << " - - - - " << endl;
		}

	}
	cout << endl;
}
//-------------------------------------------------\\
//------------Input from User in Chances-----------\\
//-------------------------------------------------\\

void userEntry(bool xTurn, string gameBoard[rows][columns])
{
	int ROW = -1;
	int COLUMN = -1;
	bool loopToAsk = true;
	while (loopToAsk)
	{
		cout << "Please enter the row followed by the column separated by space from 0,1 and 2 " << endl;
		cin >> ROW;
		cin >> COLUMN;
		if (ROW >= 0 && COLUMN >= 0 && ROW <= 2 && COLUMN <= 2)
		{
			//Input by the user is valid
			// Now checking if the place already occupied by an X or O

			if (!cellAvailableOrNot(ROW, COLUMN, gameBoard))
			{
				// row and column entered are valid and the cell isn't preoccupied
				loopToAsk = false;
			}
			else
			{
				cout << "The cell is preoccupied. Try again!" << endl;
			}
		}
	}// loopToAsk ends here

	// Now we have a valid input from the user
	// Also once out of the loop we can be assured that the cell opted for is empty

	if (xTurn)// it is an X
	{
		gameBoard[ROW][COLUMN] = "X";
	}
	else //must be O then
	{
		gameBoard[ROW][COLUMN] = "O";
	}
	
}
// defining of the cell occupancy check loop used above

//-----------------------------------------------------\\
//----------Cell Occupancy Checking--------------------\\
//-----------------------------------------------------\\

void cellAvailablbeOrNot(int rows, int columns, string gameBoard[rows][columns])
{
	return gameBoard[rows][columns] != " ";
	//if not a space then it is occupied by O or X
}//ends here

//-----------------------------------------------------\\
//---------------Check for Winner----------------------\\
//-----------------------------------------------------\\

string decWinner(string gameBoard[rows][columns])
{
	for (int i = 0; i < rows; i++)
	{
		//checking the rows
		if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
		{
			return gameBoard[i][0];
			//it is a horizontal match
		}
	}

	//checking the columns

	for (int i = 0; i < columns; i++)
	{
		if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
		{
			return gameBoard[0][i];
			//it is a vertical match
		}
	}

	//diagonal check by comparing
	//primary diagonal checking

	if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
	{
		return gameBoard[0][0];
		//it is a diagonal match
	}
	//checking for off diagonal
	if (gameBoard[2][0] != " " && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2])
	{
		return gameBoard[2][0];
		//it is a diagonal match
	}

	//if still none condition satisfied no winner yet
	return "";
}// decWinner ends

// defining board full or not checking function

//-------------Board Full Or Not-------------------\\

bool isBoardFull(string gameBoard[rows][columns])
{
	int countNonEmpty = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (gameBoard[i][j] != " ")
			{
				countNonEmpty++;
			}
		}
	}

	return countNonEmpty == 9;// if this happens ,then the matrix is full. Hence, the board is full
}
