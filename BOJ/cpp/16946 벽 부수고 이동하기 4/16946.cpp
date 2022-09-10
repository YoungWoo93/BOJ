#include <problem.h>

#ifdef _16946_

/// 
/// problem
/// https://www.acmicpc.net/problem/16946
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

void input(vector<vector<int>>& map)
{
	int height;
	int width;
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	{
		string str;
		map.push_back(vector<int>());
		cin >> str;

		for (auto c : str)
		{
			if (c == '1')
				map.back().push_back(-1);
			else
				map.back().push_back(0);
		}
	}
}

void DFS(vector<vector<int>>& board, int& count, int x, int y, int index)
{
	board[y][x] = index;
	count++;

	if (x > 0 && !board[y][x - 1])
		DFS(board, count, x - 1, y, index);

	if (x < board[0].size() - 1 && !board[y][x + 1])
		DFS(board, count, x + 1, y, index);


	if (y > 0 && !board[y - 1][x])
		DFS(board, count, x, y - 1, index);

	if (y < board.size() - 1 && !board[y + 1][x])
		DFS(board, count, x, y + 1, index);


}

void makeBoard(vector<vector<int>>& board, vector<int>& indexInfo)
{
	indexInfo.push_back(0);

	int index = 1;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (!board[i][j])
			{
				int count = 0;

				DFS(board, count, j, i, index++);
				indexInfo.push_back(count);
			}
		}
	}
}

void getIndexs(vector<vector<int>>& board, vector<int>& indexInfo, int x, int y, vector<int>& indexs)
{
	if (x > 0 && board[y][x - 1] != -1)
		indexs.push_back(board[y][x - 1]);
	if (x < board[0].size() - 1 && board[y][x + 1] != -1)
		indexs.push_back(board[y][x + 1]);


	if (y > 0 && board[y - 1][x] != -1)
		indexs.push_back(board[y - 1][x]);
	if (y < board.size() - 1 && board[y + 1][x] != -1)
		indexs.push_back(board[y + 1][x]);

	sort(indexs.begin(), indexs.end());
	indexs.erase(unique(indexs.begin(), indexs.end()), indexs.end());
}

int main()
{
	vector<vector<int>> board;
	vector<int> indexInfo;

	input(board);
	makeBoard(board, indexInfo);



	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] != -1)
				cout << "0";
			else
			{
				vector<int> indexs;
				int sum = 1;

				getIndexs(board, indexInfo, j, i, indexs);

				for (auto index : indexs)
					sum += indexInfo[index];

				cout << sum % 10;
			}
		}
		cout << endl;
	}
}

#endif
