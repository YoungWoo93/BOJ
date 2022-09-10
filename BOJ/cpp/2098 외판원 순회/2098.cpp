#include <problem.h>

#ifdef _2098_

/// 
/// problem
/// https://www.acmicpc.net/problem/2098
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

void preprocess(vector<vector<int>> &map, vector<bool>& visitTable, int& returnAble)
{
	visitTable.assign(map.size(), false);

	returnAble = 0;
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i][0] != 0)
			returnAble++;
	}
}

int travel(vector<vector<int>>& map, vector<bool>& visitTable, int& returnAble, int cityNo, int leftCity)
{
	int ret = -1;
	if (visitTable[cityNo])
		return ret;

	if (map[cityNo][0] != 0)
	{
		if (leftCity > 1 && returnAble <= 1)
			return ret;
		if (leftCity == 1)
			return map[cityNo][0];

		returnAble--;
	}

	visitTable[cityNo] = true;
	leftCity--;

	for (int i = 0; i < map.size(); i++)
	{
		if (map[cityNo][i] != 0)
		{
			auto result = travel(map, visitTable, returnAble, i, leftCity);

			if (result < 0)
				continue;

			result += map[cityNo][i];
			if (ret < 0)
				ret = result;
			else
				ret = ret < result ? ret : result;
		}
	}

	leftCity++;
	visitTable[cityNo] = false;
	if (map[cityNo][0] != 0)
		returnAble++;

	return ret;
}

int main()
{
	vector<bool> visitTable;
	int returnAble;
	
	auto map = input();
	preprocess(map, visitTable, returnAble);

	cout << travel(map, visitTable, returnAble, 0, map.size()) << endl;

	return 0;
}
#endif
