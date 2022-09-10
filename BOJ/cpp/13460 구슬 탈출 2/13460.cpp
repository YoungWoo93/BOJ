#include <problem.h>

#ifdef _13460_

/// 
/// problem
/// https://www.acmicpc.net/problem/13460
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> input()
{
	int width, height;
	
	cin >> height >> width;

	vector<vector<char>> ret(height, vector<char>(width, -1));

	for (int i = 0; i < height; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < width; j++)
		{
			ret[i][j] = temp[j];
		}
	}

	return ret;
}

void findRadBlueBall(vector<vector<char>>& map, pair<int, int>& radPos, pair<int, int>& bluePos)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 'R')
			{
				radPos.first = i;
				radPos.second = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B')
			{
				bluePos.first = i;
				bluePos.second = j;
				map[i][j] = '.';
			}
		}
	}
}

pair<int, int> move(vector<vector<char>>& map, pair<int, int> pos, pair<int, int> dir)
{
	if (pos == make_pair(-1, -1))
		return pos;

	pair<int, int> tempPos;

	char temp = map[pos.first][pos.second];
	map[pos.first][pos.second] = '.';

	while (tempPos != make_pair(-1, -1))
	{
		tempPos.first = pos.first + dir.first;
		tempPos.second = pos.second + dir.second;

		if (tempPos.first < 0 || map.size() <= tempPos.first)
		{
			tempPos.first -= dir.first;
			tempPos.second -= dir.second;
			break;
		}

		if (tempPos.second < 0 || map[0].size() <= tempPos.second)
		{
			tempPos.first -= dir.first;
			tempPos.second -= dir.second;
			break;
		}

		if (map[tempPos.first][tempPos.second] == '#' || map[tempPos.first][tempPos.second] == 'R' || map[tempPos.first][tempPos.second] == 'B')
		{
			tempPos.first -= dir.first;
			tempPos.second -= dir.second;
			break;
		}

		if (map[tempPos.first][tempPos.second] == 'O')
		{
			tempPos = { -1, -1 };
			break;
		}

		pos = tempPos;
	}

	if (tempPos != make_pair(-1, -1))
		map[tempPos.first][tempPos.second] = temp;

	return tempPos;
}

bool moves(vector<vector<char>>& map, pair<int, int> &radPos, pair<int, int> &bluePos, pair<int, int> dir)
{
	map[radPos.first][radPos.second] = 'R';
	map[bluePos.first][bluePos.second] = 'B';

	auto radTemp = move(map, radPos, dir);
	auto blueTemp = move(map, bluePos, dir);
	radTemp = move(map, radTemp, dir);


	if (radTemp == radPos && blueTemp == bluePos)
	{
		map[radTemp.first][radTemp.second] = '.';
		map[blueTemp.first][blueTemp.second] = '.';
		return false;
	}
	
	if (blueTemp == make_pair(-1, -1))
	{
		if (radTemp != make_pair(-1, -1))
			map[radTemp.first][radTemp.second] = '.';
		return false;
	}
	
	radPos = radTemp;
	bluePos = blueTemp;

	if (radTemp != make_pair(-1, -1))
		map[radTemp.first][radTemp.second] = '.';
	map[blueTemp.first][blueTemp.second] = '.';

	return true;
}
int gCount = 0;

int play(vector<vector<char>> map, pair<int, int> radPos, pair<int, int> bluePos, int count)
{
	if (count > 10)
		return -1;
	if (radPos == make_pair(-1, -1))
		return count;

	int ret = -1;
	vector< pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	for (int i = 0; i < dirs.size(); i++)
	{
		pair<int, int> radTemp = radPos;
		pair<int, int> blueTemp = bluePos;

		if (moves(map, radTemp, blueTemp, dirs[i]))
		{
			int result = play(map, radTemp, blueTemp, count + 1);

			if (ret == -1 || (result != -1 && ret > result))
				ret = result;
		}
	}

	return ret;
}



int main()
{
	auto map = input();
	pair<int, int> radPos, bluePos;

	findRadBlueBall(map, radPos, bluePos);
	cout << play(map, radPos, bluePos, 0);
	return 0;
}
#endif
