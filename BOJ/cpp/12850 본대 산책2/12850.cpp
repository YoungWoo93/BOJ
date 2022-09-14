#include <problem.h>

#ifdef _12850_

/// 
/// problem
/// https://www.acmicpc.net/problem/12850
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;
vector<vector<unsigned long long int>> map = {
	{0, 1, 0, 1, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{0, 1, 0, 1, 1, 1, 0, 0},
	{1, 1, 1, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};

vector<vector<unsigned long long int>> process(vector<vector<unsigned long long int>>& map1, vector<vector<unsigned long long int>>& map2)
{
	vector<vector<unsigned long long int>> ret(map.size(), vector<unsigned long long int>(map.front().size(), 0));
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map.front().size(); x++)
		{
			for (int i = 0; i < map.size(); i++)
			{
				ret[y][x] += map1[y][i] * map2[i][x];
				ret[y][x] = ret[y][x] % 1000000007;
			}
		}
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;

	auto matrix = map;

	vector<vector<unsigned long long int>> answer(map.size(), vector<unsigned long long int>(map.front().size(), 0));
	for (int i = 0; i < 8; i++) 
		answer[i][i] = 1; 
	

	while (n > 0)
	{
		if (n % 2 == 0)
		{
			matrix = process(matrix, matrix);
			n /= 2;
		}
		else
		{
			answer = process(answer, matrix);
			n -= 1;
		}
	}

	cout << answer[0][0] << endl;
	
}
#endif
