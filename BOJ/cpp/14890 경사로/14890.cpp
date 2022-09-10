#include <problem.h>

#ifdef _14890_

/// 
/// problem
/// https://www.acmicpc.net/problem/14890
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> input(int& length)
{
	int size;
	cin >> size >> length;

	vector<vector<int>> ret(size, vector<int>(size, 0));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> ret[i][j];
		}
	}

	return ret;
}

int travel(vector<vector<int>>& map, int length)
{
	int ret = 0;
	
	for (int i = 0; i < map.size(); i++)
	{
		bool success = true;
		int flatCount = 0;
		for (int j = 0; j < map[i].size() - 1; j++)
		{
			flatCount++;

			if (map[i][j] < map[i][j + 1])
			{
				if (flatCount < length || abs(map[i][j] - map[i][j + 1]) > 1)
				{
					success = false;
					break;
				}

				flatCount = 0;
			}
			if (map[i][j] > map[i][j + 1])
			{
				if (flatCount < 0 || abs(map[i][j] - map[i][j + 1]) > 1)
				{
					success = false;
					break;
				}

				flatCount = -length;
			}
		}
		flatCount++;

		if (success && flatCount >= 0)
			ret++;
	}

	for (int i = 0; i < map.size(); i++)
	{
		bool success = true;
		int flatCount = 0;
		for (int j = 0; j < map[i].size() - 1; j++)
		{
			flatCount++;

			if (map[j][i] < map[j + 1][i])
			{
				if (flatCount < length || abs(map[j][i] - map[j + 1][i]) > 1)
				{
					success = false;
					break;
				}

				flatCount = 0;
			}
			if (map[j][i] > map[j + 1][i])
			{
				if (flatCount < 0 || abs(map[j][i] - map[j + 1][i]) > 1)
				{
					success = false;
					break;
				}
				flatCount = -length;
			}
		}
		flatCount++;

		if (success && flatCount >= 0)
			ret++;
	}

	return ret;
}

int main()
{
	int length = 0;
	auto map = input(length);
	cout << travel(map, length) << endl;

	return 0;
}

#endif
