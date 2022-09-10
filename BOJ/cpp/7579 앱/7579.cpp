#include <problem.h>

#ifdef _7579_

/// 
/// problem
/// https://www.acmicpc.net/problem/7579
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-7579%EB%B2%88-%EC%95%B1
/// 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;


#define MaxCost	100
#define Memory	first
#define Cost	second

void input(vector<pair<int, int>>& list, int &M)
{
	int N;

	cin >> N >> M;
	list.assign(N, pair<int, int>());

	for (int i = 0; i < N; i++)
		cin >> list[i].Memory;
	
	for (int i = 0; i < N; i++)
		cin >> list[i].Cost;
	
}

void getDPtable(vector<pair<int, int>>& list, vector<int>& table)
{
	table.assign(list.size() * MaxCost + 2, -1);

	for (auto app : list)
	{
		for (int i = list.size() * MaxCost; i >= 0; i--)
		{
			if (table[i] != -1)
				table[i + app.Cost] = (table[i + app.Cost] == -1 || table[i + app.Cost] < table[i] + app.Memory ? table[i] + app.Memory : table[i + app.Cost]);
		}

		table[app.Cost] = (table[app.Cost] == -1 || table[app.Cost] < app.Memory ? app.Memory : table[app.Cost]);
	}

}

int main()
{
	vector<pair<int, int>> list;
	int target;
	input(list, target);

	vector<int> DPtable;
	getDPtable(list, DPtable);

	for (int i = 0; i < DPtable.size() - 1; i++)
	{
		if (DPtable[i] >= target)
		{
			cout << i << endl;
			break;
		}
	}
	
}

#endif
