#include <problem.h>

#ifdef _1202_

/// 
/// problem
/// https://www.acmicpc.net/problem/1202
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1202%EB%B2%88-%EB%B3%B4%EC%84%9D-%EB%8F%84%EB%91%91
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#include <stdio.h>

using namespace std;

struct sortRule {
	bool operator()(pair<int, int> first, pair<int, int> second)
	{
		//if(first.second != second.second)
			return first.second < second.second;

		//return first.first < second.first;
	}
};

void input(priority_queue<pair<int, int>, vector<pair<int, int>>, sortRule>& jewelList, multiset<int>& bagList)
{
	int jewalCount;
	int bagCount;

	cin >> jewalCount >> bagCount;

	for (int i = 0; i < jewalCount; i++)
	{
		pair<int, int> temp;

		//cin >> temp.first >> temp.second;
		scanf("%d %d", &temp.first, &temp.second);

		jewelList.push(temp);
	}

	for (int i = 0; i < bagCount; i++)
	{
		int temp;
		
		//cin >> temp;
		scanf("%d", &temp);

		bagList.insert(temp);
	}
}

int main()
{
	priority_queue<pair<int, int>, vector<pair<int,int>>, sortRule> jewelList;
	multiset<int> bagList;
	unsigned long long result = 0;

	input(jewelList, bagList);

	while (!jewelList.empty() && !bagList.empty())
	{
		auto item = jewelList.top();
		jewelList.pop();

		auto iter = bagList.lower_bound(item.first);
		if (iter != bagList.end())
		{
			result += item.second;
			bagList.erase(iter);
		}
	}

	cout << result;

	return 0;
}
#endif
