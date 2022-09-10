#include <problem.h>

#ifdef _1012_

/// 
/// problem
/// https://www.acmicpc.net/problem/1012
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


vector<vector<int>> input()
{
	int width, height, pointCount;

	cin >> width >> height >> pointCount;

	vector<vector<int>> ret(width, vector<int>(height, 0));

	for (int i = 0; i < pointCount; i++)
	{
		int xpos, ypos;

		cin >> xpos >> ypos;

		ret[xpos][ypos] = 1;
	}

	return ret;
}

void travel(int xpos, int ypos, vector<vector<int>>& arr)
{
	queue<pair<int, int>> q;
	int width = arr.size() -1;
	int height = arr[0].size() - 1;
	q.push(make_pair(xpos, ypos));

	while (!q.empty())
	{
		pair<int, int> temp = q.front();

		if (temp.first > 0)
		{
			if (arr[temp.first - 1][temp.second] == 1)
			{
				arr[temp.first - 1][temp.second] = 2;
				q.push(make_pair(temp.first - 1, temp.second));
			}
		}
		if (temp.second > 0)
		{
			if (arr[temp.first][temp.second - 1] == 1)
			{
				arr[temp.first][temp.second - 1] = 2;
				q.push(make_pair(temp.first, temp.second - 1));
			}
		}
		if (temp.first < width)
		{
			if (arr[temp.first + 1][temp.second] == 1)
			{
				arr[temp.first+1][temp.second] = 2;
				q.push(make_pair(temp.first + 1, temp.second));
			}
		}
		if (temp.second < height)
		{
			if (arr[temp.first][temp.second + 1] == 1)
			{
				arr[temp.first][temp.second + 1] = 2;
				q.push(make_pair(temp.first, temp.second + 1));
			}
		}

		q.pop();
	}
}

int process(vector<vector<int>>& arr)
{
	int width = arr.size();
	if (width == 0)
		return 0;

	int height = arr[0].size();
	if (height == 0)
		return 0;

	int ret = 0;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (arr[i][j] == 1)
			{
				ret++;
				travel(i, j, arr);
			}
		}
	}

	return ret;
}


int main()
{
	int testcase;

	cin >> testcase;
	for(int i=0; i<testcase; i++)
	{
		auto arr = input();

		cout << process(arr);
	}
	return 0;
}



#endif