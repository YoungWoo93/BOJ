#include <problem.h>

#ifdef _1967_

/// 
/// problem
/// https://www.acmicpc.net/problem/1967
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>

using namespace std;

struct node {
	int cost;
	vector<node*> childs;

	node() {
		cost = 0;
	}
};

void link(node* parent, node* child, int cost)
{
	parent->childs.push_back(child);

	child->cost = cost;
}

void input(vector<node>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int parent, child, cost;

		cin >> parent >> child >> cost;

		link(&arr[parent - 1], &arr[child - 1], cost);
	}
}


int dfs(node* start, int& answer)
{
	int leftMax = 0;
	int rightMax = 0;
	vector<int> costs(2, 0);

	for (auto it = start->childs.begin(); it != start->childs.end(); it++)
	{
		costs.push_back(dfs(*it, answer) + (*it)->cost);
	}

	sort(costs.begin(), costs.end(), greater<int>());

	int ret = max(costs[0], costs[1]);
	answer = max(answer, costs[0] + costs[1]);

	return ret;
}

int main()
{
	int count;
	cin >> count;

	vector<node> inputs(count);
	input(inputs);

	int answer = 0;
	dfs(&inputs[0], answer);

	cout << answer << endl;

	return 0;
}
#endif
