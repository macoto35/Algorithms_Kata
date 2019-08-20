#include <iostream>

using namespace std;

bool isSafe(char** board, int n, int row, int col)
{
	cout << "is safe at board[" << row << "][" << col << "] to place queen? ";
	for (int i = 0; i < n; i++) {
		// vertical / horizontal / diagonal
		if (board[row][i] == 'Q' || board[i][col] == 'Q'
		    || (row - 1 >= 0 && col - 1 >= 0 && board[row-1][col-1] == 'Q')
		    || (row + 1 < n  && col + 1 < n  && board[row+1][col+1] == 'Q')
		    || (row - 1 >= 0 && col + 1 < n  && board[row-1][col+1] == 'Q')
		    || (row + 1 < n  && col - 1 >= 0 && board[row+1][col-1] == 'Q'))
			return false;
	}
	return true;
}

void placeQueen(char** board, int row, int col)
{
	board[row][col] = 'Q';
}

void removeQueen(char** board, int row, int col)
{
	board[row][col] = '_';
}

bool solve(char** board, int n, int col)
{
	if (col >= n) {
		return true;
	} else {
		for (int row = n-1; row >= 0; row--) {
			if (isSafe(board, n, row, col)) {
				cout << "true, place queen." << endl;
				placeQueen(board, row, col);
				bool result = solve(board, n, col + 1);
				if (result == false)
					removeQueen(board, row, col);
				else
					return true;
			}
			cout << "false, check next." << endl;
		}
		return false;
	}
}

void main()
{
	int n;
	cin >> n;

	char** board = new char*[n];
	for(int i = 0; i < n; i++)
		board[i] = new char[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = '_';

	solve(board, n, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}

	delete[] board;

}
