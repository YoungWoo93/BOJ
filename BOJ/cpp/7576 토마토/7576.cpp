#include <problem.h>

#ifdef _7576_

/// 
/// problem
/// https://www.acmicpc.net/problem/7576
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-7576-%ED%86%A0%EB%A7%88%ED%86%A0
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> input(queue<pair<int, int>>& mellows, int& tomatoCount)
{
	int width, height;

	cin >> width >> height;

	vector<vector<int>> ret(height, vector<int>(width, -1));

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> ret[i][j];

			if (ret[i][j] == 1)
			{
				mellows.push(pair<int, int>(i, j));
				ret[i][j] = -1;
			}
			else if(ret[i][j] == 0)
				tomatoCount++;
		}
	}

	return ret;
}

bool UnmellowCheck(vector<vector<int>>& map, int x, int y)
{
	if (x < 0 || map.size() <= x)
		return false;

	if (y < 0 || map[0].size() <= y)
		return false;

	if (map[x][y] == 0)
		return true;

	return false;
}

int travel(vector<vector<int>>& map, queue<pair<int, int>>& mellows, int& tomatoCount)
{
	int ret = 0;
	queue<pair<int, int>> tempQueue;

	queue<pair<int, int>>* cur1 = &mellows;
	queue<pair<int, int>>* cur2 = &tempQueue;

	while (!mellows.empty() || !tempQueue.empty())
	{

		if (tomatoCount == 0)
			break;

		while (!cur1->empty())
		{
			auto tomatoPos = cur1->front();
			cur1->pop();

			if (UnmellowCheck(map, tomatoPos.first + 1, tomatoPos.second))
			{
				map[tomatoPos.first + 1][tomatoPos.second] = -1;
				tomatoCount--;
				cur2->push(pair<int, int>(tomatoPos.first + 1, tomatoPos.second));
			}
			if (UnmellowCheck(map, tomatoPos.first - 1, tomatoPos.second))
			{
				map[tomatoPos.first - 1][tomatoPos.second] = -1;
				tomatoCount--;
				cur2->push(pair<int, int>(tomatoPos.first - 1, tomatoPos.second));
			}
			if (UnmellowCheck(map, tomatoPos.first, tomatoPos.second + 1))
			{
				map[tomatoPos.first][tomatoPos.second + 1] = -1;
				tomatoCount--;
				cur2->push(pair<int, int>(tomatoPos.first, tomatoPos.second + 1));
			}
			if (UnmellowCheck(map, tomatoPos.first, tomatoPos.second - 1))
			{
				map[tomatoPos.first][tomatoPos.second - 1] = -1;
				tomatoCount--;
				cur2->push(pair<int, int>(tomatoPos.first, tomatoPos.second - 1));
			}

		}

		auto temp = cur1;
		cur1 = cur2;
		cur2 = temp;

		ret++;
	}

	if (tomatoCount == 0)
		return ret;

	return -1;
}

int main()
{
	queue<pair<int, int>> mellows;
	int tomatoCount = 0;
	auto map = input(mellows, tomatoCount);

	cout << travel(map, mellows, tomatoCount) << endl;

	return 0;
}
#endif
