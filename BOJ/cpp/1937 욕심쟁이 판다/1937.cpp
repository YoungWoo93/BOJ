#include <problem.h>

#ifdef _1937_

/// 
/// problem
/// https://www.acmicpc.net/problem/1937
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> input()
{
	int size;
	cin >> size;

	vector<vector<int>> ret(size, vector<int>(size, -1));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> ret[i][j];
		}
	}

	return ret;
}

int DFS(vector<vector<int>>& map, vector<vector<int>>& memo, int xpos, int ypos)
{
	if (memo[xpos][ypos] >= 0)
		return memo[xpos][ypos];

	int ways = 4;
	int way[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	int ret = 0;
	for (int w = 0; w < ways; w++)
	{
		int nx = xpos + way[w][0];
		int ny = ypos + way[w][1];

		if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[nx].size())
			continue;

		if (map[nx][ny] > map[xpos][ypos])
		{
			int temp = DFS(map, memo, nx, ny);
			ret = ret > temp ? ret : temp;
		}
	}

	memo[xpos][ypos] = ret + 1;

	return ret + 1;
}

int travel(vector<vector<int>>& map)
{
	int ret = 0;

	vector<vector<int>> memo(map.size(), vector<int>(map[0].size(), -1));
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (memo[i][j] == -1)
			{
				auto temp = DFS(map, memo, i, j);
				ret = ret > temp ? ret : temp;
			}
		}
	}

	return ret;
}

int main()
{
	auto map = input();
	cout << travel(map) << endl;

	
	return 0;
}

#endif
