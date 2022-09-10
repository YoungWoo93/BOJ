#include <problem.h>

#ifdef _1389_

/// 30 / 17 (3)
/// 
/// problem
/// https://www.acmicpc.net/problem/1389
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1389%EB%B2%88-%EC%BC%80%EB%B9%88-%EB%B2%A0%EC%9D%B4%EC%BB%A8%EC%9D%98-6%EB%8B%A8%EA%B3%84-%EB%B2%95%EC%B9%99
/// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct node {
	int value;
	bool visit;
	int KB;
	int temp;

	vector<int> link;
};

bool sortRule(pair<int, int> first, pair<int, int> second)
{
	if (min(first.first, first.second) == min(second.first, second.second))
		return max(first.first, first.second) <= max(second.first, second.second);

	return min(first.first, first.second) < min(second.first, second.second);
}

void input(vector<node>& nodeList, vector<pair<int, int>>& linkList)
{
	int nodeCount, linkCount;
	cin >> nodeCount >> linkCount;

	nodeList.assign(nodeCount, node());
	linkList.assign(linkCount, { 0, 0 });

	for (int i = 0; i < nodeCount; i++)
	{
		nodeList[i].value = i + 1;
		nodeList[i].visit = false;
		nodeList[i].KB = 0;
	}

	for (int i = 0; i < linkCount; i++)
	{
		cin >> linkList[i].first >> linkList[i].second;

		if (linkList[i].first != min(linkList[i].first, linkList[i].second))
			swap(linkList[i].first, linkList[i].second);
	}
}

void makeTree(vector<node>& nodeList, vector<pair<int, int>> linkList)
{
	linkList.erase(unique(linkList.begin(), linkList.end()), linkList.end());
	sort(linkList.begin(), linkList.end(), sortRule);

	for (auto item : linkList)
	{
		nodeList[item.first - 1].link.push_back(item.second - item.first);
		nodeList[item.second - 1].link.push_back(item.first - item.second);
	}

	for (auto& item : nodeList)
		sort(item.link.begin(), item.link.end());
}

void BFS(node* node, int nodeCount)
{
	vector<int> travel = { 0 };
	int index = 0;
	node->temp = 0;

	while (index < travel.size())
	{
		node += travel[index];

		for (auto diff : node->link)
		{
			if ((node + diff)->visit)
				continue;

			(node + diff)->visit = true;
			(node + diff)->temp += node->temp + 1;
			travel.push_back(travel[index] + diff);
		}
		node -= travel[index++];
	}

	for (int i = 0; i < travel.size(); i++)
	{
		(node + travel[i])->KB += (node + travel[i])->temp;
		//cout << node->value << "¹ø(" << node->KB <<") <-> " << (node + travel[i])->value << "¹ø(" << (node + travel[i])->KB  << ") " << (node + travel[i])->temp << endl;
	}

	//cout << endl << endl;
	return;
}

int process(vector<node>& nodeList)
{
	int ret = 0;
	int min = INT_MAX;

	for (int i = 0; i < nodeList.size(); i++)
	{
		auto root = &nodeList.front() + i;

		root->visit = true;
		BFS(root, nodeList.size());

		for (auto& item : nodeList)
		{
			item.visit = false;
			item.temp = 0;
		}
	}

	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList[i].KB < min)
		{
			min = nodeList[i].KB;
			ret = i + 1;
		}
	}

	return ret;
}

int main()
{

	vector<node> nodeList;
	vector<pair<int, int>> linkList;

	input(nodeList, linkList);
	makeTree(nodeList, linkList);
	cout << process(nodeList) << endl;
	

	return 0;
}
#endif

