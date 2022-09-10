#include <problem.h>

#ifdef _1577_

/// 
/// problem
/// https://www.acmicpc.net/problem/1577
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

vector<vector<unsigned long long int>> inputMap()
{
	int width;
	int height;

	cin >> height >> width;

	vector<vector<unsigned long long int>> ret(height + 1, vector<unsigned long long int>(width + 1, 0));

	
	return ret;
}

vector<vector<bool>> inputBlocked(vector<vector<unsigned long long int>>& map)
{
	int count;

	cin >> count;

	vector<vector<bool>> ret(map.size() * 2, vector<bool>(map[0].size() * 2, true));

	pair<int, int> pos1;
	pair<int, int> pos2;

	for (int i = 0; i < count; i++)
	{
		cin >> pos1.first >> pos1.second >> pos2.first >> pos2.second;

		ret[pos1.first + pos2.first][pos1.second + pos2.second] = false;
	}

	return ret;
}

void printMap(vector<vector<unsigned long long int>>& map)
{
	cout << endl << "======================" << endl;
	for (int i = map.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			unsigned long long int value = 0;

			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
}


void getDPTable(vector<vector<unsigned long long int>> &map, vector<vector<bool>> &blocks)
{
	map.back().back() = 1;
	
	for(int i = map.size() - 1; i >= 0; i--)
	{
		for (int j = map[0].size() - 1; j >= 0; j--)
		{
			if (i + 1 < map.size())
			{
				if (blocks[i*2 + 1][j * 2])
					map[i][j] += map[i + 1][j];
				
			}
			if (j + 1 < map[0].size())
			{
				if (blocks[i * 2][j * 2 + 1]) 
					map[i][j] += map[i][j + 1];
			}

			
			//printMap(map);
		}
	}

	return;
}

int main()
{
	auto dpMap = inputMap();
	auto blockList = inputBlocked(dpMap);
	
	getDPTable(dpMap, blockList);

	cout << dpMap[0][0] << endl;

	return 0;
}



#endif
