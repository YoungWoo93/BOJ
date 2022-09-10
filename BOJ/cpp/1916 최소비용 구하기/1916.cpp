#include <problem.h>

#ifdef _1916_
/// 
/// problem
/// https://www.acmicpc.net/problem/1916
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1916-%EC%B5%9C%EC%86%8C%EB%B9%84%EC%9A%A9-%EA%B5%AC%ED%95%98%EA%B8%B0
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Link {
	int start;
	int end;
	unsigned long long int cost;
};

struct linkSortRule {
	bool operator()(Link first, Link second) {
		return first.cost > second.cost;
	}
};

struct Node {
	vector<Link> linkList;
	unsigned long long int cumulatCost;
	bool visit;
};

void connectLink(vector<Node>& list, Link link)
{
	list[link.start].linkList.push_back(link);
}

vector<Node> input(int& startNode, int& endNode)
{
	int nodeCount;
	int linkCount;

	cin >> nodeCount;
	cin >> linkCount;


	Node tempNode;
	tempNode.cumulatCost = 0;
	tempNode.visit = false;

	vector<Node> nodeList(nodeCount + 1, tempNode);
	nodeList[startNode].cumulatCost = 0;

	for (int i = 0; i < linkCount; i++)
	{
		Link tempLink;
		cin >> tempLink.start >> tempLink.end >> tempLink.cost;
		connectLink(nodeList, tempLink);
	}

	cin >> startNode;
	cin >> endNode;

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
			for (auto& link : nodeList[temp.end].linkList)
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
	int endNode = 0;
	auto nodes = input(startNode, endNode);
	dijkstra(nodes, startNode);
	cout << nodes[endNode].cumulatCost << endl;

	return 0;
}

#endif
