#include <problem.h>

#ifdef _16964_

/// 
/// problem
/// https://www.acmicpc.net/problem/16964
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-16964-DFS-%EC%8A%A4%ED%8E%98%EC%85%9C-%EC%A0%80%EC%A7%80?category=530553
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int value;
	bool visit;
	vector<struct node*> childs;
};

struct sortRule {
	template <typename T>
	bool operator()(T first, T second)
	{
		return first.second > second.second;
	}
};

vector<node> input(queue<int>& answer)
{
	int nodeCount;
	cin >> nodeCount;

	vector<pair<int, int>> pathList;
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, sortRule> pq;
	vector<int> weight(nodeCount + 1, 0);
	vector<node> ret;

	for (int i = 0; i < nodeCount + 1; i++)
	{
		node tempNode;
		tempNode.value = i;
		tempNode.visit = false;

		ret.push_back(tempNode);
	}
	ret[0].childs.push_back(&ret[1]);

	for (int i = 0; i < nodeCount - 1; i++)
	{
		int parent, child;
		cin >> parent >> child;

		pathList.push_back(make_pair(parent, child));
		pathList.push_back(make_pair(child, parent));
	}

	for (int i = 0; i < nodeCount; i++)
	{
		int temp;
		cin >> temp;

		weight[temp] = i;
		answer.push(temp);
	}

	for (auto item : pathList)
	{
		pair<pair<int, int>, int> tempPair;
		tempPair.first = item;
		tempPair.second = weight[item.second];
		pq.push(tempPair);
	}
	while (!pq.empty())
	{
		ret[pq.top().first.first].childs.push_back(&ret[pq.top().first.second]);
		pq.pop();
	}

	return ret;
}


bool DFSCheck(node* _node, queue<int>& answer)
{
	_node->visit = true;

	while (!_node->childs.empty())
	{
		if (_node->childs[0]->visit)
			_node->childs.erase(_node->childs.begin());
		else
		{
			if (_node->childs[0]->value != answer.front())
				return false;

			answer.pop();
			if (!DFSCheck(_node->childs[0], answer))
				return false;
		}
	}

	return true;
}

int main()
{
	queue<int> answer;
	auto list = input(answer);

	if (DFSCheck(&list[0], answer))
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}


#endif
