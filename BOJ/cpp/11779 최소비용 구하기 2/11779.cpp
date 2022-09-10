#include <problem.h>

#ifdef _11779_

/// 
/// problem
/// 
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

struct city {
	city(const int _citys) 
		: wayCost(vector<int>(_citys, -1)), from(-1), cost(LLONG_MAX){
	}

	vector<int> wayCost;
	int from;
	long long int cost;
};

void input(vector<city>& list)
{
	int citys;
	cin >> citys;
	list.assign(citys + 1, city(citys + 1));

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		if (list[start].wayCost[end] == -1)
			list[start].wayCost[end] = cost;
		else
			list[start].wayCost[end] = min(list[start].wayCost[end], cost);
	}
}


int dijkstra(vector<city>& citys, const int start, const int target)
{
	
	priority_queue< 
		pair<long long int, pair<int, int>>,
		vector<pair<long long int, pair<int, int>>>,
		greater<pair<long long int, pair<int, int>>>
	> pq;

	// visit new city block
	{
		int visitCity = start;
		citys[visitCity].cost = 0;
		citys[visitCity].from = 0;

		if (visitCity == target)
			return visitCity;

		for (int next = 1; next < citys.size(); next++)
		{
			if (citys[visitCity].wayCost[next] != -1)
			{
				auto nextCost = citys[visitCity].cost + citys[visitCity].wayCost[next];

				if (citys[next].cost > nextCost)
					pq.push({ nextCost, {visitCity, next} });
			}
		}
	} 

	while (!pq.empty())
	{
		auto temp = pq.top();

		pq.pop();
		
		// visit new city block
		{
			int prevCity = temp.second.first;
			int visitCity = temp.second.second;

			if (temp.first >= citys[visitCity].cost)
				continue;

			citys[visitCity].cost = temp.first;
			citys[visitCity].from = prevCity;

			for (int next = 1; next < citys.size(); next++)
			{
				if (citys[visitCity].wayCost[next] != -1)
				{
					long long int nextCost = citys[visitCity].cost + citys[visitCity].wayCost[next];

					if (citys[next].cost > nextCost)
						pq.push({ nextCost, {visitCity, next} });
				}
			}
		}
	}

	return target;
}


int main()
{
	vector<city> citys;

	input(citys);

	int start, end;
	cin >> start >> end;

	auto ret = dijkstra(citys, start, end);

	cout << citys[ret].cost << endl;

	stack<int> s;
	s.push(ret);
	int cur = ret;
	while (cur != start) {
		cur = citys[cur].from;
		s.push(cur);
	}

	cout << s.size() << endl;
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
#endif
