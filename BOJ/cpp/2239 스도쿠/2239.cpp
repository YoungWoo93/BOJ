#include <problem.h>

#ifdef _2239_

/// 
/// problem
/// https://www.acmicpc.net/problem/2239
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-2239%EB%B2%88-%EC%8A%A4%EB%8F%84%EC%BF%A0
/// 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;


bool checkHorizon(int x, int y, int value, vector<vector<int>> &map)
{
	for (int i = 0; i < 9; i++)
	{
		if (map[y][i] == value)
			return false;
	}

	return true;
}


bool checkVertical(int x, int y, int value, vector<vector<int>>& map)
{
	for (int i = 0; i < 9; i++)
	{
		if (map[i][x] == value)
			return false;
	}

	return true;
}


bool checkGrid(int x, int y, int value, vector<vector<int>>& map)
{
	int startx = x / 3 * 3;
	int starty = y / 3 * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[starty + j][startx + i] == value)
				return false;
		}
	}

	return true;
}


void input(vector<vector<int>>& map)
{
	string str;

	for (int i = 0; i < 9; i++)
	{
		cin >> str;
		vector<int> temp;

		for (auto c : str)
			temp.push_back(c - '0');

		map.push_back(temp);
	}
}


bool findZero(int& x, int& y, vector<vector<int>>& map)
{
	while (x < 9 && y < 9)
	{
		if (map[y][x] == 0)
			return true;
		
		x++;
		if (x >= 9)
		{
			x = 0;
			y++;
		}
	}

	return false;
}

bool DFS(int x, int y, vector<vector<int>>& map)
{
	for (int i = 1; i <= 9; i++)
	{
		if (checkVertical(x, y, i, map) && checkHorizon(x, y, i, map) && checkGrid(x, y, i, map))
		{
			map[y][x] = i;

			int startX = x;
			int startY = y;

			if (!findZero(startX, startY, map))
				return true;

			if (DFS(startX, startY, map))
				return true;

			map[y][x] = 0;
		}
	}

	return false;
}

int main()
{
	vector<vector<int>> map;
	input(map);

	int startX = 0;
	int startY = 0;

	findZero(startX, startY, map);
	DFS(startX, startY, map);
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << map[i][j];
		cout << endl;
	}
}
#endif


