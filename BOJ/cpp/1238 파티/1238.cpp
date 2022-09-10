#include <problem.h>

#ifdef _1238_

/// 
/// problem
/// https://www.acmicpc.net/problem/1238
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1238-%ED%8C%8C%ED%8B%B0
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#include <stdio.h>

using namespace std;

struct town {
	vector<pair<int, int>> wayCost;
	vector<int> cost;
	vector<int> memo;
};

vector<town> input(int& targetTown)
{
	int townCount, wayCount;
	cin >> townCount >> wayCount >> targetTown;

	town tempTown;

	tempTown.memo.assign(townCount + 1, -1);
	tempTown.cost.assign(townCount + 1, -1);

	vector<town> ret(townCount+1, tempTown);

	for (int i = 0; i < wayCount; i++)
	{
		int start, end, cost;

		cin >> start >> end >> cost;

		ret[start].wayCost.push_back(pair<int, int>(end, cost));
	}

	for (int i = 1; i < townCount + 1; i++)
	{
		ret[i].wayCost.push_back(pair<int, int>(i, 0));
	}

	return ret;
}


void dijkstra(vector<town>& towns, int startTown)
{
	set<pair<int, int>> pq;

	for (auto index : towns[startTown].wayCost)
	{
		pq.insert(pair<int, int>(index.second, index.first));
	}

	while (!pq.empty())
	{
		auto temp = *pq.begin();

		pq.erase(pq.begin());

		if (towns[temp.second].memo[startTown] == -1 || towns[temp.second].memo[startTown] > temp.first)
		{
			towns[temp.second].memo[startTown] = temp.first;
			towns[startTown].cost[temp.second] = temp.first;

			for (auto index : towns[temp.second].wayCost)
			{
				if(towns[startTown].cost[index.first] == -1 || towns[startTown].cost[index.first] > index.second + temp.first)
					pq.insert(pair<int, int>(index.second + temp.first, index.first));
			}
		}
	}
}

void travel(vector<town>& towns)
{
	for (int i = 1; i < towns.size(); i++)
	{
		dijkstra(towns, i);
	}
}


int main()
{
	int targetTown;
	auto towns = input(targetTown);

	travel(towns);

	int max = 0;
	for (int i = 0; i < towns.size(); i++)
	{
		if (towns[i].cost[targetTown] + towns[i].memo[targetTown] > max)
			max = towns[i].cost[targetTown] + towns[i].memo[targetTown];
	}

	cout << max << endl;

	return 0;
}
#endif
