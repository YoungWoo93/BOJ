#include <problem.h>

#ifdef _17143_

/// 
/// problem
/// https://www.acmicpc.net/problem/17143
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct shark {
	int x;
	int y;
	int speed;
	int dir;
	int size;
};

vector<shark> sharks;

void input(int width, int height, int count)
{
	sharks.assign(count + 1, shark());
	
	for (int i = 1; i <= count; i++)
	{
		cin >> sharks[i].y;
		sharks[i].y--;
		cin >> sharks[i].x;
		sharks[i].x--;
		cin >> sharks[i].speed;
		cin >> sharks[i].dir;
		cin >> sharks[i].size;

		if (sharks[i].dir == 1 || sharks[i].dir == 2)
			sharks[i].speed %= 2 * (height - 1);
		else
			sharks[i].speed %= 2 * (width - 1);
	}
}

int fight(int a, int b)
{
	if (sharks[b].x == -1 || sharks[a].size > sharks[b].size)
	{
		sharks[b].x = -1;
		sharks[b].y = -1;

		return a;
	}
	else
	{
		sharks[a].x = -1;
		sharks[a].y = -1;

		return b;
	}

}

void moveShark(vector<vector<int>>& before, vector<vector<int>>& after, int s)
{
	int width = before.front().size();
	int height = before.size();
	int xOffset = (width - 1) * 2;
	int yOffset = (height - 1) * 2;

	if (sharks[s].x == -1)
		return;

	before[sharks[s].y][sharks[s].x] = 0;

	switch (sharks[s].dir)
	{
	case 1:
		if (sharks[s].y <= sharks[s].speed && sharks[s].speed - sharks[s].y < height)
			sharks[s].dir = 2;

		sharks[s].y = (yOffset + sharks[s].y - sharks[s].speed) % yOffset;
		if (sharks[s].y >= height)
			sharks[s].y = yOffset - sharks[s].y;
		break;
	case 2:
		if (height - sharks[s].y <= sharks[s].speed && sharks[s].speed - (height - sharks[s].y) < height - 1)
			sharks[s].dir = 1;

		sharks[s].y = (yOffset + sharks[s].y + sharks[s].speed) % yOffset;
		if (sharks[s].y >= height)
			sharks[s].y = yOffset - sharks[s].y;
		break;
	case 3:
		if (width - sharks[s].x <= sharks[s].speed && sharks[s].speed - (width - sharks[s].x) < width - 1)
			sharks[s].dir = 4;

		sharks[s].x = (xOffset + sharks[s].x + sharks[s].speed) % xOffset;
		if (sharks[s].x >= width)
			sharks[s].x = xOffset - sharks[s].x;
		break;
	case 4:
		if (sharks[s].x <= sharks[s].speed && sharks[s].speed - sharks[s].x < width)
			sharks[s].dir = 3;

		sharks[s].x = (xOffset + sharks[s].x - sharks[s].speed) % xOffset;
		if (sharks[s].x >= width)
			sharks[s].x = xOffset - sharks[s].x;
		break;
	}

	int x = sharks[s].x;
	int y = sharks[s].y;
	if (after[y][x] == 0)
		after[y][x] = s;
	else
		after[y][x] = fight(after[y][x], s);
}

int fishing(vector<vector<int>>& map, int index)
{
	int ret = 0;

	for (int h = 0; h < map.size(); h++)
	{
		if (map[h][index] != 0)
		{
			ret = sharks[map[h][index]].size;
			sharks[map[h][index]].x = -1;
			sharks[map[h][index]].y = -1;
			map[h][index] = 0;

			break;
		}
	}

	return ret;
}


void printMap(vector<vector<int>>& map)
{
	for (auto v : map)
	{
		for (auto c : v)
			cout << c << "\t";
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

int main()
{
	int width, height, count;
	cin >> height >> width >> count;
	input(width, height, count);

	vector<vector<int>> map1(height, vector<int>(width, 0));
	vector<vector<int>> map2(height, vector<int>(width, 0));

	vector<vector<int>>* map = &map1;
	vector<vector<int>>* temp = &map2;

	for (int s = 1; s < sharks.size(); s++)
		(*map)[sharks[s].y][sharks[s].x] = s;

	int answer = 0;
	for (int i = 0; i < width; i++)
	{
		//printMap(*map);
		answer += fishing(*map, i);
		//printMap(*map);

		for (int s = 1; s < sharks.size(); s++)
			moveShark(*map, *temp, s);

		swap(map, temp);
	}

	cout << answer << endl;
}


#endif
