#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _1395_
// https://www.acmicpc.net/problem/1395

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct node{
	int on;
	bool isReverse;
}node;

void reversUpdate(int treeLeftBoundary, int treeRightBoundary, int root, vector<int>& tree, vector<bool>& reverse);
int setReverse(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, int root, vector<int>& tree, vector<bool>& reverse);
int getOnCount(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, int root, vector<int>& tree, vector<bool>& reverse);

int main()
{
	int switchCount;
	int taskCount;

	scanf("%d", &switchCount);
	int treeSize = ceil(log2(switchCount)) + 1;

	vector<int> tree(pow(2, treeSize), 0);
	vector<bool> reverse(pow(2, treeSize), false);

	scanf("%d", &taskCount);
	for (int i = 0; i < taskCount; i++)
	{
		int tasktype;
		int start, end;

		scanf("%d%d%d", &tasktype, &start, &end);

		if (tasktype == 0)
		{
			setReverse(1, switchCount, start, end, 1, tree, reverse);
		}
		else
		{
			printf("%d\n", getOnCount(1, switchCount, start, end, 1, tree, reverse));
		}
	}
	
	return 0;
}


void reversUpdate(int treeLeftBoundary, int treeRightBoundary, int root, vector<int>& tree, vector<bool>& reverse)
{
	if (reverse[root] == true)
	{
		tree[root] = (treeRightBoundary - treeLeftBoundary + 1) - tree[root];

		if (treeLeftBoundary != treeRightBoundary)
		{
			reverse[root * 2] = !reverse[root * 2];
			reverse[root * 2 + 1] = !reverse[root * 2 + 1];
		}

		reverse[root] = false;
	}
}

int setReverse(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, int root, vector<int>& tree, vector<bool>& reverse)
{
	reversUpdate(treeLeftBoundary, treeRightBoundary, root, tree, reverse);

	if (rangeLeft > treeRightBoundary || rangeRight < treeLeftBoundary)
		return tree[root];

	if (rangeLeft <= treeLeftBoundary && rangeRight >= treeRightBoundary)
	{
		tree[root] = (treeRightBoundary - treeLeftBoundary + 1) - tree[root];

		if (treeLeftBoundary != treeRightBoundary)
		{
			reverse[root * 2] = !reverse[root * 2];
			reverse[root * 2 + 1] = !reverse[root * 2 + 1];
		}

		return tree[root];
	}

	return tree[root] = setReverse(treeLeftBoundary, (treeLeftBoundary + treeRightBoundary) / 2, rangeLeft, rangeRight, root * 2, tree, reverse) + setReverse((treeLeftBoundary + treeRightBoundary) / 2 + 1, treeRightBoundary, rangeLeft, rangeRight, root * 2 + 1, tree, reverse);
}


int getOnCount(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, int root, vector<int>& tree, vector<bool>& reverse)
{
	reversUpdate(treeLeftBoundary, treeRightBoundary, root, tree, reverse);

	if (rangeLeft > treeRightBoundary || rangeRight < treeLeftBoundary)
		return 0;

	if (rangeLeft <= treeLeftBoundary && rangeRight >= treeRightBoundary)
		return tree[root];
	
	return getOnCount(treeLeftBoundary, (treeLeftBoundary + treeRightBoundary) / 2, rangeLeft, rangeRight, root * 2, tree, reverse) + getOnCount((treeLeftBoundary + treeRightBoundary) / 2 + 1, treeRightBoundary, rangeLeft, rangeRight, root * 2 + 1, tree, reverse);
}


#endif