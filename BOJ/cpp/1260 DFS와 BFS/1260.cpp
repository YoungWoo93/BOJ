#include <problem.h>

#ifdef _1260_

/// 120 / 0 (1)
/// 
/// problem
/// https://www.acmicpc.net/problem/1260
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int value;
	bool visit;
	
	vector<int> link;
};

bool sortRule(pair<int, int> first, pair<int, int> second)
{
	if (min(first.first, first.second) == min(second.first, second.second))
		return max(first.first, first.second) <= max(second.first, second.second);

	return min(first.first, first.second) < min(second.first, second.second);
}

void input(vector<node>& nodeList, vector<pair<int, int>>& linkList, int& startNode)
{
	int nodeCount, linkCount;
	cin >> nodeCount >> linkCount >> startNode;

	nodeList.assign(nodeCount, node());
	linkList.assign(linkCount, { 0, 0 });

	for (int i = 0; i < nodeCount; i++)
	{
		nodeList[i].value = i + 1;
		nodeList[i].visit = false;
	}

	for (int i = 0; i < linkCount; i++)
		cin >> linkList[i].first >> linkList[i].second;
}

void makeTree(vector<node>& nodeList, vector<pair<int, int>> linkList, int startNode)
{
	sort(linkList.begin(), linkList.end(), sortRule);

	for (auto item : linkList)
	{
		nodeList[item.first - 1].link.push_back(item.second - item.first);
		nodeList[item.second - 1].link.push_back(item.first - item.second);
	}

	for (auto &item : nodeList)
		sort(item.link.begin(), item.link.end());
}

void BFS(node* node,  int nodeCount)
{
	vector<int> travel = { 0 };
	int index = 0;

	while (index < travel.size())
	{
		node += travel[index];
		if(index != 0)
			cout << " " << node->value;

		for (auto diff : node->link)
		{
			if ((node + diff)->visit)
				continue;

			(node + diff)->visit = true;
			travel.push_back(travel[index] + diff);
		}
		node -= travel[index++];
	}

	return;
}

void DFS(node* node)
{
	for (auto diff : node->link)
	{
		if ((node + diff)->visit)
			continue;

		(node + diff)->visit = true;
		cout << " " << (node + diff)->value;

		DFS(node + diff);
	}
}

int main()
{

	vector<node> nodeList;
	vector<pair<int, int>> linkList;
	int startNode;

	input(nodeList, linkList, startNode);
	makeTree(nodeList, linkList, startNode);

	auto root = &nodeList.front() + startNode - 1;

	cout << root->value;
	root->visit = true;
	DFS(root);
	cout << endl;

	for (auto& item : nodeList)
		item.visit = false;
	cout << root->value;
	root->visit = true;
	BFS(root, nodeList.size());
	cout << endl;

	return 0;
}
#endif

