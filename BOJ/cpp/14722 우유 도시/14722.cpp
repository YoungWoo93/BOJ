#include <problem.h>

#ifdef _14722_

/// 
/// problem
/// https://www.acmicpc.net/problem/14722
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NEXT(n)		(n + 1) % 3
#define PREV(n)		(3 + n - 1) % 3


void printGrid(vector<vector<int>>& grid)
{
	for (auto v : grid)
	{
		for (auto c : v)
			cout << c << "\t";
		cout << endl;
	}
}

void input(vector<vector<int>>& map)
{
	int n;
	cin >> n;

	map.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
}

int eat(vector<vector<int>>& map, vector<vector<int>>& table, int current, int x, int y)
{
	if (x < 0 || map[0].size() <= x)
		return 0;
	if (y < 0 || map.size() <= y)
		return 0;

	if (map[y][x] == NEXT(current))
		return table[y][x] + 1;
	
	return table[y][x];
}

void getDPtable(vector<vector<int>>& map, vector<vector<int>>& table)
{
	table.assign(map.size(), vector<int>(map.size(), 0));

	int n = map.size() - 1;
	table[n][n] = 1;

	for (int i = n; i >= 0; i--)
	{
		for (int j = n; j >= 0; j--)
		{
			int right = eat(map, table, map[i][j], j + 1, i);
			int left = eat(map, table, map[i][j], j, i + 1);

			table[i][j] = max(table[i][j], max(right, left));
		}
	}
}



int main()
{
	vector<vector<int>> map;
	vector<vector<int>> dpTable;

	input(map);
	getDPtable(map, dpTable);

	//cout << "map" << endl;
	//printGrid(map);

	//cout << endl << endl << "dpTable" << endl;
	//printGrid(dpTable);

	cout << dpTable[0][0] << endl;
	return 0;
}

#endif
