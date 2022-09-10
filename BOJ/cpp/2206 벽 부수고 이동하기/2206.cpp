#include <problem.h>

#ifdef _2206_

/// 60 / 0 (1)
/// 
/// problem
/// https://www.acmicpc.net/problem/2206
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

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

vector<vector<int>> moveMask(vector<vector<int>> mask, int able = 1)
{
	vector<vector<int>> ret;

	int cx = mask.size() / 2;
	int cy = mask[0].size() / 2;

	for (int x = 0; x < mask.size(); x++)
	{
		for (int y = 0; y < mask[0].size(); y++)
		{
			if (mask[x][y] == able)
			{
				vector<int> temp;
				temp.push_back(x - cx);
				temp.push_back(y - cy);

				ret.push_back(temp);
			}
		}
	}

	return ret;
}

int move(vector<vector<int>>& map, int x, int y, int impossible = 1)
{
	int ret = -1;

	if (x < 0)
		return ret;

	if (x >= map.size())
		return ret;

	if (y < 0)
		return ret;

	if (y >= map[0].size())
		return ret;

	if (map[x][y] == impossible)
		return ret;

	return map[x][y];
}

vector<vector<int>> BFS(vector<vector<int>> maze, pair<int, int> start, pair<int, int> end)
{
	vector<vector<int>> ret(maze.size(), vector<int>(maze[0].size(), -1));
	queue<pair<int, int>> q;
	auto moving = moveMask(
		{ {0, 1, 0},
		  {1, 0, 1},
		  {0, 1, 0} });

	q.push(start);
	maze[start.first][start.second] = 1;
	ret[start.first][start.second] = 1;

	while (!q.empty())
	{
		for (auto offset : moving)
		{
			int x = q.front().first;
			int y = q.front().second;
			if (move(maze, x + offset[0], y + offset[1], 1) == -1)
				continue;

			ret[x + offset[0]][y + offset[1]] = ret[x][y] + 1;
			q.push({ x + offset[0], y + offset[1] });
			maze[x + offset[0]][y + offset[1]] = 1;
		}
		q.pop();
	}

	return ret;
}

int process(vector<vector<int>>& maze)
{
	
	pair<int, int> start = { 0, 0 };
	pair<int, int> end = { maze.size() - 1, maze[0].size() - 1 };
	vector<vector<int>> startToEndDPtable = BFS(maze, start, end);
	vector<vector<int>> endToStartDPtable = BFS(maze, end, start);

	auto moving = moveMask(
		{ {0, 0, 1, 0, 0},
		  {0, 1, 0, 1, 0},
		  {1, 0, 0, 0, 1},
		  {0, 1, 0, 1, 0},
		  {0, 0, 1, 0, 0}, });
	int ret = INT_MAX;

	if (startToEndDPtable[end.first][end.second] != -1)
		ret = startToEndDPtable[end.first][end.second];

	for (int i = 0; i < startToEndDPtable.size(); i++)
	{
		for (int j = 0; j < startToEndDPtable[0].size(); j++)
		{
			if (startToEndDPtable[i][j] == -1)
				continue;

			for (auto offset : moving)
			{
				int temp = move(endToStartDPtable, i + offset[0], j + offset[1], -1);
				if (temp == -1)
					continue;

				ret = min(ret, temp + startToEndDPtable[i][j] + 1);
			}
		}
	}

	if (ret == INT_MAX)
		ret = -1;

	return ret;
}


int main()
{
	auto maze = input();
	auto result = process(maze);
	
	cout << result << endl;
	return 0;
}
#endif


