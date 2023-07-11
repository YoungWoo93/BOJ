#include <problem.h>

#ifdef _11725_

/// 15
/// problem
/// https://www.acmicpc.net/problem/11725
/// 
/// solution
/// 
/// 
//#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
	node() : parent(0) {};
	int parent;
	vector<int> links;
};

//void BFS(vector<node>& arr)
void BFS(node* arr)
{
	queue<int> indexQ;
	arr[1].parent = -1;
	indexQ.push(1);

	while (!indexQ.empty())
	{
		int index = indexQ.front();
		indexQ.pop();

		for (auto link : arr[index].links)
		{
			if(arr[link].parent != 0)
				continue;

			arr[link].parent = index;
			indexQ.push(link);
		}

	}
}

node arr[100001];

int main()
{
	int nodeCount;
	//cin >> nodeCount;
	scanf("%d", &nodeCount);

	//vector<node> arr(nodeCount + 1);

	for (int i = 0; i < nodeCount - 1; i++)
	{
		int node1, node2;
		//cin >> node1 >> node2;
		scanf("%d %d", &node1, &node2);

		arr[node1].links.push_back(node2);
		arr[node2].links.push_back(node1);
	}


	BFS(arr);

	//for (int i = 2; i < arr.size(); i++)
	//	cout << arr[i].parent << endl;
	for (int i = 2; i <= nodeCount; i++)
		printf("%d\n", arr[i].parent);


}
#endif
