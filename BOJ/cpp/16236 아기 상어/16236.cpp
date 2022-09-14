#include <problem.h>

#ifdef _16236_

/// 
/// problem
/// https://www.acmicpc.net/problem/16236
/// 
/// solution
/// 
/// 



#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool moveAble(vector<vector<int>>& map, vector<vector<bool>>& visit, int y, int x, int size)
{
	if (x < 0 || map.front().size() <= x)
		return false;
	if (y < 0 || map.size() <= y)
		return false;
	if (visit[y][x])
		return false;
	if (map[y][x] > size)
		return false;

	visit[y][x] = true;
	return true;
}

void input(vector<vector<int>>& map, int& startX, int& startY)
{
	int size;
	cin >> size;

	map.assign(size, vector<int>(size, 0));

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 9)
			{
				startX = x;
				startY = y;
				map[y][x] = 0;
			}
		}
	}
}

bool eatAble(vector<vector<int>>& map, int startX, int startY, int size, int& endX, int& endY, int& step)
{
	vector<vector<bool>> visit(map.size(), vector<bool>(map.front().size(), false));

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q2;

	auto q = &q1;
	auto temp = &q2;
	
	step = 0;

	q->push({ startY, startX });
	visit[startY][startX] = true;

	while (!q1.empty() || !q2.empty())
	{
		while (!q->empty())
		{
			auto point = q->top();
			q->pop();

			if (map[point.first][point.second] != 0 && map[point.first][point.second] < size)
			{
				map[point.first][point.second] = 0;
				endX = point.second;
				endY = point.first;

				return true;
			}

			if (moveAble(map, visit, point.first - 1, point.second, size))
				temp->push({ point.first - 1, point.second });
			if (moveAble(map, visit, point.first, point.second - 1, size))
				temp->push({ point.first, point.second - 1 });
			if (moveAble(map, visit, point.first, point.second + 1, size))
				temp->push({ point.first, point.second + 1 });
			if (moveAble(map, visit, point.first + 1, point.second, size))
				temp->push({ point.first + 1, point.second });
		}
		step++;
		swap(q, temp);
	}

	return false;
}


void printMap(vector<vector<int>>& map)
{
	for (auto v : map)
	{
		for (auto i : v)
		{
			cout << i << "\t";
		}
		cout << endl;
	}
}

//#define DRAWMAP

int main()
{
	vector<vector<int>> map;
	int startX, startY;
	int size = 2;
	input(map, startX, startY);

	int endX, endY;
	int answer = 0;
	int count = 2;
	int step = 0;
#ifdef DRAWMAP
	printMap(map);
	cout << size << endl << endl;
#endif
	while (eatAble(map, startX, startY, size, endX, endY, step))
	{
		count--;
		if (count == 0)
		{
			size++;
			count = size;
		}

		answer += step;
		startX = endX;
		startY = endY;
#ifdef DRAWMAP
		printMap(map);
		cout << size << "(" << count << ")\t" << answer << endl;
		
		cout << endl;
#endif
	}
	
	cout << answer << endl;
}


#endif
