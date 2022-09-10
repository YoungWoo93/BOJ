#include <problem.h>

#ifdef _1753_

/// 
/// problem
/// https://www.acmicpc.net/problem/1753
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1753%EB%B2%88-%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C
/// 

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Link {
	int start;
	int end;
	int cost;
};

struct linkSortRule {
	bool operator()(Link first, Link second) {
		return first.cost > second.cost;
	}
};

struct Node {
	vector<Link> linkList;
	int cumulatCost;
	bool visit;
};

void connectLink(vector<Node>& list, Link link)
{
	list[link.start].linkList.push_back(link);
}

vector<Node> input(int& startNode)
{
	int nodeCount;
	int linkCount;

	//cin >> nodeCount;
	//cin >> linkCount;
	//cin >> startNode;
	scanf("%d %d %d", &nodeCount, &linkCount, &startNode);
	Node tempNode;
	tempNode.cumulatCost = -1;
	tempNode.visit = false;

	vector<Node> nodeList(nodeCount + 1, tempNode);
	nodeList[startNode].cumulatCost = 0;

	for (int i = 0; i < linkCount; i++)
	{
		Link tempLink;
		//cin >> tempLink.start >> tempLink.end >> tempLink.cost;
		scanf("%d %d %d", &tempLink.start, &tempLink.end, &tempLink.cost);
		connectLink(nodeList, tempLink);
	}

	return nodeList;
}

void dijkstra(vector<Node>& nodeList, int startNode)
{
	priority_queue<Link, vector<Link>, linkSortRule> pqLink;
	nodeList[startNode].visit = true;
	nodeList[startNode].cumulatCost = 0;
	for (auto link : nodeList[startNode].linkList)
	{
		pqLink.push(link);
	}

	while (!pqLink.empty())
	{
		auto temp = pqLink.top();
		pqLink.pop();

		if (!nodeList[temp.end].visit)
		{
			nodeList[temp.end].visit = true;
			nodeList[temp.end].cumulatCost = temp.cost;
			for (auto &link : nodeList[temp.end].linkList)
			{
				link.cost = nodeList[temp.end].cumulatCost + link.cost;
				pqLink.push(link);
			}
		}
		else
		{
			if (temp.cost < nodeList[temp.end].cumulatCost)
				nodeList[temp.end].cumulatCost = temp.cost;
		}


	}

}

int main()
{
	int startNode = 0;
	auto nodes = input(startNode);

	dijkstra(nodes, startNode);

	for (int i = 1; i < nodes.size(); i++)
	{
		if (nodes[i].cumulatCost >= 0)
			printf("%d\n", nodes[i].cumulatCost);
			//cout << nodes[i].cumulatCost << endl;
		else
			printf("INF\n");
			//cout << "INF" << endl;
	}

	return 0;
}
#endif
