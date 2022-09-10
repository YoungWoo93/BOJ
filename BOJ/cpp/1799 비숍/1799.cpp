#include <problem.h>

#ifdef _1799_

/// 150
/// problem
/// https://www.acmicpc.net/problem/1799
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<bool>> input()
{
	int size = 0;
	cin >> size;

	vector<vector<bool>> ret(size, vector<bool>(size, true));

	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> temp;
			ret[i][j] = temp;
		}
	}

	return ret;
}

vector<vector<bool>> putBishop(vector<vector<bool>> board, int x, int y)
{
	vector<vector<bool>> ret(board);

	for (int i = 0; x + i < board.size() && y + i < board.size(); i++)
		ret[y + i][x + i] = false;

	return ret;
}

int globalCount = 1;
void printMap(vector<vector<bool>> maps, int index)
{

	cout << endl;
	cout << "index " << index << " global call " << globalCount++;
	for (int y = 0; y < maps.size(); y++)
	{
		cout << endl;
		for (int i = 0; i < index; i++)
			cout << " ";

		for (int x = 0; x < maps.size(); x++)
		{
			if (maps[y][x])
				cout << "1 ";
			else
				cout << "0 ";
		}
	}
	cout << endl;
}

int travel(vector<vector<bool>> board, int index, int cur)
{
	int ret = 0;
	
	if (index > board.size() * 2)
		return ret;

	int x = 0;
	int y = 0;

	if (index < board.size())
	{
		x = 0;
		y = index;
	}
	else
	{
		x = index - board.size() + 1;
		y = board.size() - 1;
	}

	for (;x<board.size() && y>=0;x++,y--)
	{
		if (board[y][x])
		{
			auto map = putBishop(board, x, y);
			//printMap(map, index);
			ret = max(ret, travel(map, index + 1, cur + 1) + 1);

			if (cur + ret == (board.size() - 1) * 2)
				return ret;
			if (ret >= (board.size() * 2) - index)
				return ret;
		}
	}
	if(ret == 0)
		ret = max(ret, travel(board, index + 1, cur));

	return ret;
}



int main()
{
	auto board = input();

	int answer = travel(board, 0, 0);

	cout << answer << endl;
	
}
#endif
