#include <problem.h>

#ifdef _14500_

/// 
/// problem
/// https://www.acmicpc.net/problem/14500
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<vector<int>>& map)
{
	int height, width;
	cin >> height >> width;
	map.assign(height, vector<int>(width));

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
			cin >> map[h][w];
	}
}

int DFS(vector<vector<int>>& map, vector<vector<bool>>& visits, int x, int y, int length)
{
	if (map.size() <= y || y < 0)
		return 0;
	if (map[0].size() <= x || x < 0)
		return 0;
	if (visits[y][x])
		return 0;

	int ret = map[y][x];

	if (length <= 1)
		return ret;

	visits[y][x] = true;

	int temp = DFS(map, visits, x - 1, y, length - 1);
	temp = max(temp, DFS(map, visits, x + 1, y, length - 1));
	temp = max(temp, DFS(map, visits, x, y - 1, length - 1));
	temp = max(temp, DFS(map, visits, x, y + 1, length - 1));

	visits[y][x] = false;

	return temp + ret;
}

int checkValue(vector<vector<int>>& map, vector<vector<bool>>& visits, int x, int y)
{
	if (map.size() <= y || y < 0)
		return 0;
	if (map[0].size() <= x || x < 0)
		return 0;
	if (visits[y][x])
		return 0;

	return map[y][x];
}


int BFS(vector<vector<int>>& map, vector<vector<bool>>& visits, int x, int y)
{
	int ret = checkValue(map, visits, x, y);


	int temp = checkValue(map, visits, x - 1, y);
	int temp2 = temp;
	ret += temp;
	
	temp = checkValue(map, visits, x + 1, y);
	temp2 = min(temp2, temp);
	ret += temp;

	temp = checkValue(map, visits, x, y - 1);
	temp2 = min(temp2, temp);
	ret += temp;

	temp = checkValue(map, visits, x, y + 1);
	temp2 = min(temp2, temp);
	ret += temp;

	return ret - temp2;
}



int main()
{
	vector<vector<int>> map;
	input(map);

	vector<vector<bool>> visits(map.size(), vector<bool>(map[0].size(), false));

	int answer = 0;
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[0].size(); x++)
		{
			answer = max(answer, DFS(map, visits, x, y, 4));
			answer = max(answer, BFS(map, visits, x, y));
		}
	}

	cout << answer << endl;
}

#endif
