#include <problem.h>

#ifdef _1655_

/// 150
/// problem
/// https://www.acmicpc.net/problem/1655
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<int> input()
{
	int count;
	vector<int> ret;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int temp;
		scanf("%d", &temp);

		ret.push_back(temp);
	}

	return ret;
}

int process(int value, priority_queue<int, vector<int>, greater<int>>& pq_greater, priority_queue<int, vector<int>, less<int>>& pq_less)
{
	pq_less.push(value);

	if (pq_less.size() - pq_greater.size() > 1)
	{
		pq_greater.push(pq_less.top());
		pq_less.pop();
	}

	if (!pq_greater.empty() && pq_less.top() > pq_greater.top())
	{
		pq_greater.push(pq_less.top());
		pq_less.pop();

		pq_less.push(pq_greater.top());
		pq_greater.pop();
	}

	return pq_less.top();
}

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq_greater;
	priority_queue<int, vector<int>, less<int>> pq_less;
	auto orders = input();

	for (auto item : orders)
		cout << process(item, pq_greater, pq_less) << endl;

	return 0;
}
#endif
