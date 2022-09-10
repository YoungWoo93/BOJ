#include <problem.h>

#ifdef _1504_

/// 
/// problem
/// https://www.acmicpc.net/problem/1504
/// 
/// solution
/// 
/// 



#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>

using namespace std;


void input(vector<vector<long long int>>& nodes, vector<int>& requiresNode)
{
	int nodeCount, wayCount;
	cin >> nodeCount >> wayCount;

	nodes.assign(nodeCount + 1, vector<long long int>(nodeCount + 1, -1));
	requiresNode.assign(2, 0);

	for (int i = 0; i < wayCount; i++)
	{
		int start, end, cost;

		cin >> start >> end >> cost;

		nodes[start][end] = cost;
		nodes[end][start] = cost;
	}

	cin >> requiresNode[0] >> requiresNode[1];
}


vector<long long int> travel(int start, vector<vector<long long int>>& nodes)
{
	vector<long long int> ret(nodes.size(), -1);
	vector<bool> visits(nodes.size(), false);

	visits[start] = true;
	ret[start] = 0;




	set<pair<long long int, int>> pq;

	for (int i = 1; i< nodes[start].size(); i++)
	{
		if(nodes[start][i] > 0)
			pq.insert(pair<long long int, int>(nodes[start][i], i));
	}

	while (!pq.empty())
	{
		auto temp = *pq.begin();
		visits[temp.second] = true;
		pq.erase(pq.begin());
		
		if (ret[temp.second] < 0 || ret[temp.second] > temp.first)
		{
			ret[temp.second] = temp.first;

			for (int i = 1; i < nodes[temp.second].size(); i++)
			{
				if (nodes[temp.second][i] > 0) // && !visits[i])
					pq.insert(pair<long long int, int>(nodes[temp.second][i] + ret[temp.second], i));
			}
		}
	}


	return ret;
}



int main()
{
	vector<vector<long long int>> nodes;
	vector<int> requiresNode;

	input(nodes, requiresNode);

	vector<long long int> startCostMap = travel(1, nodes);
	vector<long long int> point1CostMap = travel(requiresNode[0], nodes);
	vector<long long int> point2CostMap = travel(requiresNode[1], nodes);

	long long int cost1 = -1;
	long long int cost2 = -1;
	if (startCostMap[requiresNode[0]] >= 0 && point1CostMap[requiresNode[1]] >= 0 && point2CostMap[nodes.size() - 1] >= 0)
		cost1 = startCostMap[requiresNode[0]] + point1CostMap[requiresNode[1]] + point2CostMap[nodes.size() - 1];

	if (startCostMap[requiresNode[1]] >= 0 && point2CostMap[requiresNode[0]] >= 0 && point1CostMap[nodes.size() - 1] >= 0)
		cost2 = startCostMap[requiresNode[1]] + point2CostMap[requiresNode[0]] + point1CostMap[nodes.size() - 1];

	long long int answer = 0;

	if (cost1 < 0 && cost2 < 0)
		answer = -1;
	else
	{
		if (min(cost1, cost2) < 0)
			answer = max(cost1, cost2);
		else
			answer = min(cost1, cost2);
	}

	cout << answer << endl;

	return 0;
}


#endif
