#include <problem.h>

#ifdef _1717_

/// 
/// problem
/// https://www.acmicpc.net/problem/1717
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

vector<int> nodes;

int findPrime(int index)
{
	if (nodes[index] == index)
		return index;

	nodes[index] = findPrime(nodes[index]);

	return nodes[index];
}

void join(int a, int b)
{
	if (findPrime(a) == findPrime(b))
		return;

	int prime = 0;
	int target = 0;
	if(nodes[a] > nodes[b])
		nodes[nodes[a]] = nodes[b];
	else
		nodes[nodes[b]] = nodes[a];
	

}

bool cmp(int a, int b)
{
	return findPrime(a) == findPrime(b);
}

int main()
{
	int count, orders;
	scanf("%d %d", &count, &orders);

	nodes.assign(count + 1, 0);
	for (int i = 0; i < nodes.size(); i++)
		nodes[i] = i;

	for (int i = 0; i < orders; i++)
	{
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd)
		{
			if (cmp(a, b))
				printf("yes\n");
			else
				printf("no\n");

		}
		else
			join(a, b);
	}

	return 0;
}
#endif
