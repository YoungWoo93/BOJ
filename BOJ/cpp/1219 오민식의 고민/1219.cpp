#include <problem.h>

#ifdef _1219_

/// 
/// problem
/// https://www.acmicpc.net/problem/1219
/// 
/// solution
/// 
/// 

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;


struct Link {
	int start;
	int end;
	int cost;
};

struct Node {
	vector<Link> linkList;
	//int cumulatCost;
	bool goalAble;
	int income;
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
	cin >> startNode;
	cin >> endNode;
	cin >> linkCount;
	//scanf("%d %d %d", &nodeCount, &linkCount, &startNode);
	Node tempNode;
	//tempNode.cumulatCost = -1;
	tempNode.goalAble = false;
	//tempNode.postMoney = LLONG_MIN;

	vector<Node> nodeList(nodeCount, tempNode);
	//nodeList[startNode].cumulatCost = 0;

	for (int i = 0; i < linkCount; i++)
	{
		Link tempLink;
		cin >> tempLink.start >> tempLink.end >> tempLink.cost;
		//scanf("%d %d %d", &tempLink.start, &tempLink.end, &tempLink.cost);
		connectLink(nodeList, tempLink);
	}

	for (int i = 0; i < nodeCount; i++)
	{
		cin >> nodeList[i].income;
	}

	return nodeList;
}

vector<int> test(vector<Node>& nodeList, int startNode, int endNode)
{
	vector<int> visitList;

	visitList.push_back(startNode);

	for (int count = 0; count < nodeList.size() + 1; count++)
	{
		int cycle = visitList.size();
		for (int i = 0; i < cycle; i++)
		{
			for (int j = 0; j < nodeList[visitList[i]].linkList.size(); j++)
			{
				if (find(visitList.begin(), visitList.end(), nodeList[visitList[i]].linkList[j].end) == visitList.end())
					visitList.push_back(nodeList[visitList[i]].linkList[j].end);
			}
		}
	}

	return visitList;
}

bool goalAbleCheck(vector<Node>& nodeList, int startNode, int endNode)
{
	vector<int> visitList;

	visitList.push_back(startNode);

	for (int count = 0; count < nodeList.size() + 1; count++)
	{
		int cycle = visitList.size();
		for (int i = 0; i < cycle; i++)
		{
			for (int j = 0; j < nodeList[visitList[i]].linkList.size(); j++)
			{
				if (nodeList[nodeList[visitList[i]].linkList[j].end].goalAble)
					return true;
				if (nodeList[visitList[i]].linkList[j].end == endNode)
					return true;

				if (find(visitList.begin(), visitList.end(), nodeList[visitList[i]].linkList[j].end) == visitList.end())
					visitList.push_back(nodeList[visitList[i]].linkList[j].end);
			}
		}
	}

	return false;
}


bool bellman(vector<Node>& nodeList, int startNode, int endNode)
{
	vector<int> visitList;

	visitList.push_back(startNode);
	nodeList[startNode].postMoney = nodeList[startNode].income;

	for(int count = 0; count < nodeList.size() + 1; count++)
	{
		int cycle = visitList.size();
		for (int i = 0; i < cycle; i++)
		{
			for (int j = 0; j < nodeList[visitList[i]].linkList.size(); j++)
			{
				if (find(visitList.begin(), visitList.end(), nodeList[visitList[i]].linkList[j].end) == visitList.end())
					visitList.push_back(nodeList[visitList[i]].linkList[j].end);

				long long int temp = nodeList[visitList[i]].postMoney;
				temp -= nodeList[visitList[i]].linkList[j].cost;
				temp += nodeList[nodeList[visitList[i]].linkList[j].end].income;

				if (nodeList[nodeList[visitList[i]].linkList[j].end].postMoney < temp)
					nodeList[nodeList[visitList[i]].linkList[j].end].postMoney = temp;
			}
		}
	}

	if (find(visitList.begin(), visitList.end(), endNode) == visitList.end())
	{
		return false;
	}

	for (int count = 0; count < nodeList.size() + 1; count++)
	{
		int cycle = visitList.size();
		for (int i = 0; i < cycle; i++)
		{
			for (int j = 0; j < nodeList[visitList[i]].linkList.size(); j++)
			{
				if (nodeList[nodeList[visitList[i]].linkList[j].end].goalAble)
				{
					long long int temp = nodeList[visitList[i]].postMoney;
					temp -= nodeList[visitList[i]].linkList[j].cost;
					temp += nodeList[nodeList[visitList[i]].linkList[j].end].income;


					if (nodeList[nodeList[visitList[i]].linkList[j].end].postMoney < temp)
						return true;
				}

			}
		}

		
	}

	return false;
}


int main()
{
	int startNode = 0;
	int endNode = 0;
	auto nodes = input(startNode, endNode);
	auto visitNodes = test(nodes, startNode, endNode);

	for (int i = 0; i < visitNodes.size(); i++)
		nodes[visitNodes[i]].goalAble = goalAbleCheck(nodes, visitNodes[i], endNode);



	if (!nodes[startNode].goalAble)
	{
		cout << "gg" << endl;
		return 0;
	}

	if (bellman(nodes, startNode, endNode))
		cout << "Gee" << endl;
	else
		cout << nodes[endNode].postMoney << endl;

	return 0;
}
#endif
