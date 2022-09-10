#include <problem.h>

#ifdef _14939_

/// 
/// problem
/// https://www.acmicpc.net/problem/14939
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void input(vector<vector<bool>>& board)
{
	for (int i = 0; i < 10; i++)
	{
		string str;
		board.push_back(vector<bool>());
		cin >> str;

		for (auto c : str)
		{
			if (c == '#')
				board.back().push_back(false);
			else
				board.back().push_back(true);
		}
	}
}

void push(vector<vector<bool>>& board, int x, int y)
{
	board[y][x] = !board[y][x];

	if (x >= 1)
		board[y][x - 1] = !board[y][x - 1];
	if (x < 9)
		board[y][x + 1] = !board[y][x + 1];

	if (y >= 1)
		board[y - 1][x] = !board[y - 1][x];
	if (y < 9)
		board[y + 1][x] = !board[y + 1][x];
}

void simulation(vector<vector<bool>> board, int& answer)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i - 1][j])
			{
				push(board, j, i);
				answer++;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (board.back()[i])
			answer = -1;
	}
}

void countTrueBit(vector<int>& bits, int n)
{
	for (int i = 0; i < 10; i++)
	{
		if (n & 1 << i)
		{
			bits.push_back(i);
		}
	}
}

void process(vector<vector<vector<int>>>& pushSet)
{
	pushSet.assign(11, vector<vector<int>>());

	for (int i = 0; i < 1024; i++)
	{
		vector<int> temp;

		countTrueBit(temp, i);
		pushSet[temp.size()].push_back(temp);
	}
}

int main()
{
	vector<vector<bool>> board;
	vector<vector<vector<int>>> pushSet;
	input(board);
	process(pushSet);

	int answer = -1;

	for (int i = 0; i <= 10; i++)
	{
		for (auto setList : pushSet[i])
		{
			for (auto set : setList)
				push(board, set, 0);

			int caseAnswer = i;
			simulation(board, caseAnswer);

			for (auto set : setList)
				push(board, set, 0);

			if (answer == -1)
				answer = caseAnswer;
			else if (caseAnswer != -1)
				answer = min(answer, caseAnswer);
		}
	}


	cout << answer << endl;
}


#endif
