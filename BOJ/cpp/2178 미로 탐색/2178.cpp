#include <problem.h>

#ifdef _2178_

/// 
/// problem
/// https://www.acmicpc.net/problem/2178
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-2178-%EB%AF%B8%EB%A1%9C-%ED%83%90%EC%83%89
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> input()
{
	int width, height;
	cin >> height >> width;

	vector<vector<int>> ret(height, vector<int>());

	for (int i = 0; i < height; i++)
	{
		string temp;
		cin >> temp;

		for (auto c : temp)
			ret[i].push_back(c - '0');
	}

	return ret;
}

bool moveAble(vector<vector<int>>& maze, int x, int y)
{
	if (x < 0)
		return false;

	if (x >= maze[0].size())
		return false;

	if (y < 0)
		return false;

	if (y >= maze.size())
		return false;

	if (maze[y][x] != 1)
		return false;

	return true;
}

pair<pair<int, int>, int> makePairs(int x, int y, int value)
{
	return pair<pair<int, int>, int>(pair<int, int>(x, y), value);
}

int travel(vector<vector<int>>& maze)
{
	queue<pair<pair<int, int>, int>> q;

	q.push(makePairs(0,0,1));
	maze[0][0] = 0;

	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();

		if (temp.first == pair<int, int>(maze[0].size() - 1, maze.size() - 1))
			return temp.second;

		
		if (moveAble(maze, temp.first.first + 1, temp.first.second))
		{
			q.push(makePairs(temp.first.first+1, temp.first.second, temp.second + 1));
			maze[temp.first.second][temp.first.first + 1] = 0;
		}

		if (moveAble(maze, temp.first.first - 1, temp.first.second))
		{
			q.push(makePairs(temp.first.first-1, temp.first.second, temp.second + 1));
			maze[temp.first.second][temp.first.first - 1] = 0;
		}

		if (moveAble(maze, temp.first.first, temp.first.second + 1))
		{
			q.push(makePairs(temp.first.first, temp.first.second+1, temp.second + 1));
			maze[temp.first.second + 1][temp.first.first] = 0;
		}

		if (moveAble(maze, temp.first.first, temp.first.second - 1))
		{
			q.push(makePairs(temp.first.first, temp.first.second-1, temp.second + 1));
			maze[temp.first.second - 1][temp.first.first] = 0;
		}

	}

	return -1;
}


int main()
{
	auto maze = input();

	cout << travel(maze);

	return 0;
}



#endif
