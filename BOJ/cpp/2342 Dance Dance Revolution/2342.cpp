#include <problem.h>

#ifdef _2342_

/// 170
/// problem
/// https://www.acmicpc.net/problem/2342
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


vector<int> input()
{
	int inputs = 1;
	vector<int> ret;

	while (true)
	{
		cin >> inputs;

		if (inputs == 0)
			break;

		ret.push_back(inputs);
	}

	return ret;
}

int move(int before, int after)
{
	if (before == 0)
		return 2;

	if (abs(before - after) == 2)
		return 4;

	return 3;
}
void putValue(int* target, int value)
{
	if (*target == -1)
		*target = value;
	else
		*target = min(*target, value);
}

void runCommand(int command, vector<vector<int>>* currentBoard, vector<vector<int>>* nextBoard)
{
	for (int left = 0; left < (*currentBoard).size(); left++)
	{
		for (int right = 0; right < (*currentBoard)[0].size(); right++)
		{
			if ((*currentBoard)[left][right] != -1)
			{
				if (left == command || right == command)
					putValue(&(*nextBoard)[left][right], (*currentBoard)[left][right] + 1);
				else
				{
					putValue(&(*nextBoard)[command][right], (*currentBoard)[left][right] + move(left, command));
					putValue(&(*nextBoard)[left][command], (*currentBoard)[left][right] + move(right, command));
				}
				(*currentBoard)[left][right] = -1;

			}
		}
	}
}

vector<vector<int>> simulation(vector<int> cmd)
{
	vector<vector<int>> board1(5, vector<int>(5, -1));
	vector<vector<int>> board2(5, vector<int>(5, -1));

	vector<vector<int>>* currentBoardPtr = &board1;
	vector<vector<int>>* nextBoardPtr = &board2;

	board1[0][0] = 0;

	for (int i = 0; i < cmd.size(); i++)
	{
		runCommand(cmd[i], currentBoardPtr, nextBoardPtr);

		auto temp = currentBoardPtr;
		currentBoardPtr = nextBoardPtr;
		nextBoardPtr = temp;
	}

	

	return *currentBoardPtr;
}

int main()
{
	auto command = input();
	vector<vector<int>> result = simulation(command);

	int answer = INT_MAX;
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			if (result[i][j] != -1)
				answer = min(answer, result[i][j]);
		}
	}

	cout << answer << endl;

	return 0;
}
#endif
