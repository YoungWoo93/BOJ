#include <problem.h>

#ifdef _1005_

/// 
/// problem
/// https://www.acmicpc.net/problem/1005
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1005%EB%B2%88-ACM-Craft
/// 


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Building {
	int prevBuilds;
	int buildTime;
	int buildOrderTime;
	vector<struct Building*> next;
}build;

void input(vector<int>& time, vector<pair<int, int>>& buildOrder, int& targetBuilding);
vector<build> registBuilding(vector<int>& time, vector<pair<int, int>>& buildOrder);
void buildProcess(vector<build>& buildings);

void input(vector<int>& time, vector<pair<int, int>>& buildOrder, int& targetBuilding)
{
	int buildingCount;
	int buildOderCount;

	cin >> buildingCount;
	cin >> buildOderCount;

	for (int i = 0; i < buildingCount; i++)
	{
		int temp;
		cin >> temp;

		time.push_back(temp);
	}

	for (int i = 0; i < buildOderCount; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;

		buildOrder.push_back(temp);
	}
	
	cin >> targetBuilding;
}

vector<build> registBuilding(vector<int>& time, vector<pair<int, int>>& buildOrder)
{
	Building init;
	init.prevBuilds = 0;
	init.buildOrderTime = 0;
	init.buildTime = 0;
	vector<build> ret(time.size() + 1, init);
	for (int i = 1; i < time.size() + 1; i++)
	{
		ret[0].next.push_back(&ret[i]);
		ret[i].prevBuilds++;
	}

	for (int i = 0; i < time.size(); i++)
	{
		ret[i + 1].buildTime = time[i];
	}

	for (auto i : buildOrder)
	{
		ret[i.first].next.push_back(&ret[i.second]);
		ret[i.second].prevBuilds++;
	}

	return ret;
}

void buildProcess(vector<build>& buildings)
{
	queue<build*> q;
	q.push(&buildings[0]);

	while (!q.empty())
	{
		for (auto& i : q.front()->next)
		{
			if (i->buildOrderTime < q.front()->buildOrderTime + q.front()->buildTime)
				i->buildOrderTime = q.front()->buildOrderTime + q.front()->buildTime;

			i->prevBuilds--;

			if (i->prevBuilds == 0)
				q.push(i);
		}
		
		q.pop();
	}

}

int main()
{
	int cycle;
	cin >> cycle;

	for (int i = 0; i < cycle; i++)
	{
		vector<int> time;
		vector<pair<int, int>> buildOrder;
		int targetBuilding;

		input(time, buildOrder, targetBuilding);
		auto buildings = registBuilding(time, buildOrder);
		buildProcess(buildings);

		cout << buildings[targetBuilding].buildOrderTime + buildings[targetBuilding].buildTime << endl;
	}

	return 0;
}

#endif
