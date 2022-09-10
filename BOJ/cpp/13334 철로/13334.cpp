#include <problem.h>

#ifdef _13334_

/// 
/// problem
/// https://www.acmicpc.net/problem/13334
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


vector<pair<int, int>> inputs(int& rail)
{
	int count;
	scanf("%d", &count);

	vector<pair<int, int>> ret(count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d %d", &ret[i].first, &ret[i].second);

		if (ret[i].first > ret[i].second)
			swap(ret[i].first, ret[i].second);
	}

	sort(ret.begin(), ret.end(), [](pair<int, int> a, pair<int, int> b) {return a.second < b.second; });

	scanf("%d", &rail);

	return ret;
}

int process(vector<pair<int, int>>& peoples, int length)
{
	int ret = 0;
	int start = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < peoples.size(); i++)
	{
		start = peoples[i].second - length;
		pq.push(peoples[i]);
		while (!pq.empty() && pq.top().first < start)
			pq.pop();
		
		ret = max(ret, (int)pq.size());
	}

	return ret;
}

int main()
{
	int rail = 0;
	auto peoples = inputs(rail);

	int answer = process(peoples, rail);

	cout << answer << endl;

	return 0;
}
#endif
