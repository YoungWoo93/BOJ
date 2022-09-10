#include <problem.h>

#ifdef _2533_

/// 170
/// problem
/// https://www.acmicpc.net/problem/2533
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	bool visit;
	int index;
	vector<node*> edges;

	node() {
		visit = false;
	}
};

vector<node> input()
{
	int count;
	cin >> count;

	vector<node> ret(count, node());

	for (int i = 0; i < count - 1; i++)
	{
		int p, c;
		cin >> p >> c;
		ret[p - 1].index = p;
		ret[c - 1].index = c;

		ret[p - 1].edges.push_back(&ret[c - 1]);
		ret[c - 1].edges.push_back(&ret[p - 1]);
	}

	return ret;
}

bool travel(node* root, int& count)
{
	bool flag = false;

	root->visit = true;
	if (root->edges.size() == 1 && root->edges[0]->visit)
		return true;


	for (int i = 0; i < root->edges.size(); i++)
	{
		if (root->edges[i]->visit)
			continue;

		bool temp = travel(root->edges[i], count);
		if (!flag)
			flag = temp;
	}

	if (flag)
		count++;

	return !flag;
}

int process(vector<node>& nodeList)
{
	int answer = 0;

	travel(&nodeList[0], answer);
	

	return (answer > nodeList.size() - answer ? nodeList.size() - answer : answer );
}


int main()
{
	auto nodeList = input();
	int answer = process(nodeList);

	cout << answer << endl;

	return 0;
}
#endif
