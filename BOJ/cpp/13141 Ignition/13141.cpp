#include <problem.h>

#ifdef _13141_

/// 
/// problem
/// https://www.acmicpc.net/problem/13141
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <limits.h>

using namespace std;

struct node {
	vector<pair<int, int>> way_cost;
	unsigned int cost;
};

void input(vector<node>& list)
{
	int nodes;
	cin >> nodes;
	list.assign(nodes + 1, node());

	int way;
	cin >> way;

	for (int i = 0; i < way; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		list[start].way_cost.push_back({ end, cost });
		list[end].way_cost.push_back({ start, cost });
	}
}


void dijkstra(vector<node>& nodes, const int start)
{

	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> pq;

	// visit new node block
	{
		int visitnode = start;
		nodes[visitnode].cost = 0;

		for (auto& link : nodes[visitnode].way_cost)
		{
			auto nextCost = nodes[visitnode].cost + link.second;

			if (nodes[link.first].cost > nextCost) {
				nodes[link.first].cost = nextCost;
				pq.push({ link.first, nextCost });
			}
		}
	}

	while (!pq.empty())
	{
		auto temp = pq.top();

		pq.pop();

		// visit new node block
		{
			int visitnode = temp.first;

			for (auto& link : nodes[visitnode].way_cost)
			{
				auto nextCost = nodes[visitnode].cost + link.second;

				if (nodes[link.first].cost > nextCost) {
					nodes[link.first].cost = nextCost;
					pq.push({ link.first, nextCost });
				}
			}
		}
	}
}


float getMinTime(vector<node>& nodes, int start)
{
	float ret = 0;

	for (auto& n : nodes) {
		for (auto& way : n.way_cost) {
			float dt = abs((int)(nodes[way.first].cost - n.cost));

			if (dt >= way.second)
				ret = max(ret, (float)n.cost);
			else
				ret = max(ret, (((float)way.second - dt) / 2) + n.cost);
			
		}
	}

	return ret;
}

int main()
{
	vector<node> nodes;

	input(nodes);
	float answer = INFINITY;
	for (int i = 1; i < nodes.size(); i++)
	{
		for (auto& n : nodes)
			n.cost = -1;

		dijkstra(nodes, i);
		answer = min(answer, getMinTime(nodes, i));
		
	}

	printf("%.1f\n", answer);
}
#endif
