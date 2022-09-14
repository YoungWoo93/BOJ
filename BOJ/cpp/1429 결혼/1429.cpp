#include <problem.h>

#ifdef _1429_

/// 
/// problem
/// https://www.acmicpc.net/problem/1429
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <numeric>

using namespace std;

void inputBoard(vector<vector<int>>& board)
{
	for (int m = 0; m < board.size(); m++)
	{
		for (int w = 0; w < board[0].size(); w++)
			cin >> board[m][w];
	}
}

unsigned int process(vector<vector<int>> board, vector<int> list, bool MtoF)
{
	int ret = 0;
	for (auto starter : list)
	{
		if (MtoF)
		{
			for (int i = 0; i < board[0].size(); i++)
			{
				if(board[starter - 1][i] == 1)

			}
		}
	}
	
	return -1;
}

int main()
{
	int man, woman;

	cin >> man >> woman;
	vector<vector<int>> board(man, vector<int>(woman));
	vector<int> manList(man);
	vector<int> womanList(woman);

	inputBoard(board);

	unsigned int answer = UINT_MAX;

	while (true)
	{
		answer = min(answer, process(board, manList, true));
		if (!next_permutation(manList.begin(), manList.end()))
			break;
	}

	while (true)
	{
		answer = min(answer, process(board, womanList, false));
		if (!next_permutation(womanList.begin(), womanList.end()))
			break;
	}

	cout << answer << endl;

	return 0;
}

#endif

