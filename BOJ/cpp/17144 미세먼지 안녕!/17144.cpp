#include <problem.h>

#ifdef _17144_

/// 
/// problem
/// https://www.acmicpc.net/problem/17144
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> input(int& time)
{
	int height, width;
	cin >> height >> width >> time;

	vector<vector<int>> ret(height, vector<int>(width, 0));

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cin >> ret[i][j];

	}

	return ret;
}

void spread(vector<vector<int>>* currentMap, vector<vector<int>>* nextMap, int width, int height)
{
	if ((*currentMap)[height][width] <= 0)
		return;

	int count = 0;
	if (width > 0)
	{
		if ((*nextMap)[height][width - 1] != -1)
		{
			(*nextMap)[height][width - 1] += (*currentMap)[height][width] / 5;
			count++;
		}
	}
	if (width < (*currentMap)[0].size() - 1)
	{
		if ((*nextMap)[height][width + 1] != -1)
		{
			(*nextMap)[height][width + 1] += (*currentMap)[height][width] / 5;
			count++;
		}
	}
	if (height > 0)
	{
		if ((*nextMap)[height - 1][width] != -1)
		{
			(*nextMap)[height - 1][width] += (*currentMap)[height][width] / 5;
			count++;
		}
	}
	if (height < (*currentMap).size() - 1)
	{
		if ((*nextMap)[height + 1][width] != -1)
		{
			(*nextMap)[height + 1][width] += (*currentMap)[height][width] / 5;
			count++;
		}
	}

	(*nextMap)[height][width] += (*currentMap)[height][width] - (*currentMap)[height][width] / 5 * count;
}

void spin(vector<vector<int>>* nextMap, int point)
{
	for (int h = point - 1; h > 0; h--)
		(*nextMap)[h][0] = (*nextMap)[h-1][0];

	for (int w = 0; w < (*nextMap)[0].size() - 1; w++)
		(*nextMap)[0][w] = (*nextMap)[0][w+1];

	for (int h = 0; h < point; h++)
		(*nextMap)[h][(*nextMap)[0].size()-1] = (*nextMap)[h+1][(*nextMap)[0].size() - 1];

	for (int w = (*nextMap)[0].size() - 1; w > 1; w--)
		(*nextMap)[point][w] = (*nextMap)[point][w - 1];

	(*nextMap)[point][1] = 0;

	
	point++;
	
	for (int h = point + 1; h < (*nextMap).size() - 1; h++)
		(*nextMap)[h][0] = (*nextMap)[h + 1][0];

	for (int w = 0; w < (*nextMap)[0].size() - 1; w++)
		(*nextMap)[(*nextMap).size() - 1][w] = (*nextMap)[(*nextMap).size() - 1][w + 1];

	for (int h = (*nextMap).size() - 1; h > point; h--)
		(*nextMap)[h][(*nextMap)[0].size() - 1] = (*nextMap)[h - 1][(*nextMap)[0].size() - 1];

	for (int w = (*nextMap)[0].size() - 1; w > 1; w--)
		(*nextMap)[point][w] = (*nextMap)[point][w - 1];
	
	(*nextMap)[point][1] = 0;
}



vector<vector<int>> simulation(vector<vector<int>> maps, int time)
{
	vector<vector<int>> tempMap(maps.size(), vector<int>(maps[0].size(), 0));
	vector<vector<int>>* currentPtr = &maps;
	vector<vector<int>>* nextPtr = &tempMap;

	int top = -1;
	for (int i = 0; i < maps.size(); i++)
	{
		if (maps[i][0] == -1)
		{
			top = i;
			break;
		}
	}

	for (int count = 0; count < time; count++)
	{
		for (int i = 0; i < maps.size(); i++)
			(*nextPtr)[i].assign(maps[0].size(), 0);
		
		(*nextPtr)[top][0] = -1;
		(*nextPtr)[top + 1][0] = -1;
		for (int h = 0; h < maps.size(); h++)
		{
			for (int w = 0; w < maps[0].size(); w++)
					spread(currentPtr, nextPtr, w, h);
		}
		spin(nextPtr, top);
		auto temp = currentPtr;
		currentPtr = nextPtr;
		nextPtr = temp;
	}

	return *currentPtr;
}


int main()
{
	int time = 0;
	auto maps = input(time);
	auto afterMap = simulation(maps, time);

	int answer = 2;
	for (int i = 0; i < afterMap.size(); i++)
	{
		for (int j = 0; j < afterMap[0].size(); j++)
			answer += afterMap[i][j];
	}
	
	cout << answer << endl;
}


#endif
