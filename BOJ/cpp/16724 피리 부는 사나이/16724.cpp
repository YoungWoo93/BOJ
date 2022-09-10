#include <problem.h>

#ifdef _16724_

/// 
/// problem
/// https://www.acmicpc.net/problem/16724
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

void input(vector<vector<char>>& board)
{
	int height, width;

	cin >> height >> width;

	board.assign(height, vector<char>(width));

	for (auto& line : board)
	{
		for (char& c : line)
			cin >> c;
	}
}

void move(vector<vector<char>>& board, int& x, int& y)
{
	switch (board[y][x])
	{
	case 'U':
		y--;
		break;
	case 'D':
		y++;
		break;
	case 'L':
		x--;
		break;
	case 'R':
		x++;
		break;
	}
}

vector<int> value;

int travel(vector<vector<char>>& board, vector<vector<bool>>& visit, vector<int>& check, int x, int y, int count)
{
	if (visit[y][x])
	{
		if (check[y * board[0].size() + x] != -1)
		{
			value[check[y * board[0].size() + x]] += count;
			
			return check[y * board[0].size() + x];
		}
		else
		{
			value[y * board[0].size() + x] = count;

			return y * board[0].size() + x;
		}
	}
	else
	{
		visit[y][x] = true;
		
		int px = x;
		int py = y;
		count++;
		move(board, x, y);

		check[py * board[0].size() + px] = travel(board, visit, check, x, y, count);
		return check[py * board[0].size() + px];
	}
		
}

void getCheckBoard(vector<vector<char>>& board, vector<int>& check)
{
	vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
	check.assign(board.size() * board[0].size(),-1);
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
			travel(board, visit, check, j, i, 0);
	}
}

void DFS(vector<vector<char>>& board, vector<vector<bool>>& visit, int x, int y)
{
	visit[y][x] = true;

	if (x > 0 && !visit[y][x-1])
	{
		if (board[y][x - 1] == 'R')
			DFS(board, visit, x - 1, y);
	}
	if (x < board[0].size() - 1 && !visit[y][x + 1])
	{
		if (board[y][x + 1] == 'L')
			DFS(board, visit, x + 1, y);
	}

	if (y > 0 && !visit[y - 1][x])
	{
		if (board[y - 1][x] == 'D')
			DFS(board, visit, x, y - 1);
	}
	if (y < board.size() - 1 && !visit[y + 1][x])
	{
		if (board[y + 1][x] == 'U')
			DFS(board, visit, x, y + 1);
	}
}

int solution(vector<vector<char>>& board, vector<pair<int, pair<int, int>>>& spotList)
{
	int answer = 0;
	sort(spotList.begin(), spotList.end(), greater<pair<int, pair<int, int>>>());
	vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

	for (auto spot : spotList)
	{
		int x = spot.second.first;
		int y = spot.second.second;

		if (!visit[y][x])
		{
			DFS(board, visit, x, y);
			answer++;
		}
	}

	return answer;
}

int main()
{
	vector<vector<char>> board;
	input(board);
	value.assign(board.size() * board[0].size(), 0);

	vector<int> check;
	getCheckBoard(board, check);

	vector<pair<int, pair<int, int>>> spotList;

	int answer = 0;
	for (int i = 0; i < value.size(); i++)
	{
		if (value[i] != 0)
			answer++;
	}

	cout << answer << endl;
	//for (int i = 0; i < check.size(); i++)
	//	spotList.push_back({ check[i] , {i / board[0].size(), i % board[0].size()} });
	//cout << solution(board, spotList) << endl;
	
}

#endif
