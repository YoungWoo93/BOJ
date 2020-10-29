#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _18250_
// https://www.acmicpc.net/problem/18250

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node{
	int system = 0;
	vector<node*> linkList;
}node;

void input(int routeCount, vector<node>& arr);
int getSystemCycle(vector<node>& arr);

int main()
{
	int stationCount;
	int routeCount;
	int systemCount = 0;
	int ret = 0;

	scanf("%d%d", &stationCount, &routeCount);
	vector<node> stationList(stationCount);
	

	input(routeCount, stationList);
	systemCount = getSystemCycle(stationList);

	vector<int> systemOddCount(systemCount);

	for (int i = 0; i < stationCount; i++)
	{
		if (stationList[i].linkList.size() % 2)
			systemOddCount[stationList[i].system - 1]++;
	}

	for (int i = 0; i < systemCount; i++)
	{
		if (systemOddCount[i] == 0)
			ret = ret + 1;
		else;
			ret += systemOddCount[i] / 2 + systemOddCount[i] % 2;
	}

	printf("%d", ret);

	return 0;
}

void input(int routeCount, vector<node>& arr)
{
	for (int i = 0; i < routeCount; i++)
	{
		int start, end;
		scanf("%d%d", &start, &end);

		arr[start-1].linkList.push_back(&arr[end-1]);
		arr[end-1].linkList.push_back(&arr[start-1]);
	}
}

int getSystemCycle(vector<node>& arr)
{
	int systemCount = 0;
	int temp = arr.size();
	queue<node*> Q;

	for (int i = 0; i < temp; i++)
	{
		if (arr[i].system == 0 && arr[i].linkList.size() != 0)
		{
			systemCount++;
			Q.push(&arr[i]);
		}
			

		while (!Q.empty())
		{
			for (int i = 0; i < Q.front()->linkList.size(); i++)
			{
				if (Q.front()->linkList[i]->system == 0)
				{
					Q.push(Q.front()->linkList[i]);
					Q.front()->linkList[i]->system = systemCount;
				}
			}
			Q.pop();
		}

	}
		

	return systemCount;
}
#endif