#include <problem.h>

#ifdef _3193_

/// 
/// problem
/// https://www.acmicpc.net/problem/3193
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define	down	0
#define	right	1
#define	up		2
#define	left	3

void inputBoard(vector<vector<char>>& board, int& x, int& y)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'L')
			{
				x = j;
				y = i;
			}
		}
	}
}

bool moveAble(vector<vector<char>>& board, int x, int y, int dir)
{
	if (x < 0 || board.size() <= x)
		return false;
	if (y < 0 || board.size() <= y)
		return false;

	if (board[y][x] != '.')
		return false;

	return true;
}

void commandProcess(vector<vector<char>>& board, int& x, int& y, int dir)
{
	board[y][x] = '.';
	switch (dir)
	{
	case down:
		while (moveAble(board, x, y + 1, dir))
			y++;
		break;
	case right:
		while (moveAble(board, x + 1, y, dir))
			x++;
		break;
	case up:
		while (moveAble(board, x, y - 1, dir))
			y--;
		break;
	case left:
		while (moveAble(board, x - 1, y, dir))
			x--;
		break;
	}

	board[y][x] = 'L';
}

void printBoard(vector<vector<char>>& board, int dir)
{
	switch (dir)
	{
	case down:
		for (int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board.size(); x++)
				cout << board[y][x];
			cout << endl;
		}
		break;
	case right:
		for (int x = 0; x < board.size(); x++)
		{
			for (int y = board.size() - 1; y >= 0; y--)
				cout << board[y][x];
			cout << endl;
		}
		break;
	case up:
		for (int y = board.size() - 1; y >= 0; y--)
		{
			for (int x = board.size() - 1; x >= 0; x--)
				cout << board[y][x];
			cout << endl;
		}
		break;
	case left:
		for (int x = board.size() - 1; x >= 0; x--)
		{
			for (int y = 0; y < board.size(); y++)
				cout << board[y][x];
			cout << endl;
		}
		break;
	}


}

int main()
{
	int boardSize, commandCount;
	int x, y;

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> boardSize >> commandCount;

	vector<vector<char>> board(boardSize, vector<char>(boardSize));
	inputBoard(board, x, y);

	
	int dir = down;
	for (int i = 0; i < commandCount; i++)
	{
		char cmd;
		cin >> cmd;

		if (cmd == 'D')
			dir = (dir + 5) % 4;
		else
			dir = (dir + 3) % 4;

		commandProcess(board, x, y, dir);
	}

	printBoard(board, dir);

	return 0;
}
#endif
