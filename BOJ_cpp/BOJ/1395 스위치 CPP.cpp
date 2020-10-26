#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _1395_
// https://www.acmicpc.net/problem/1395

#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
	int on;
	int off;
	bool isReverse;

	node* left;
	node* right;
}node;

node* getSegmentTree(int start, int end);
void setReverse(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, node* root);
int getOnCount(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, node* root);

int main()
{
	int switchCount;
	int taskCount;

	cin >> switchCount;
	node* root = getSegmentTree(1, switchCount);

	cin >> taskCount;
	for (int i = 0; i < taskCount; i++)
	{
		int tasktype;
		int start, end;

		cin >> tasktype;
		cin >> start;
		cin >> end;

		if (tasktype == 0)
		{
			setReverse(1, switchCount, start, end, root);
		}
		else
		{
			cout << getOnCount(1, switchCount, start, end, root) << "\n";
		}
	}
	
	return 0;
}


node* getSegmentTree(int start, int end)
{
	node* ret = new node();

	if (start == end)
	{
		ret->left = NULL;
		ret->right = NULL;
		ret->on = 0;
		ret->off = 1;
		ret->isReverse = false;

		return ret;
	}

	ret->left = getSegmentTree(start, (start+end) / 2);
	ret->right = getSegmentTree((start + end) / 2 + 1, end);
	ret->on = ret->left->on + ret->right->on;
	ret->off = ret->left->off + ret->right->off;
	ret->isReverse = false;

	return ret;
}

void setReverse(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, node* root)
{
	if (root->isReverse == true)
	{
		int temp = root->off;
		root->off = root->on;
		root->on = temp;

		if (treeLeftBoundary != treeRightBoundary)
		{
			if (root->left != NULL)
				root->left->isReverse = root->left->isReverse ? false : true;
			if (root->right != NULL)
				root->right->isReverse = root->right->isReverse ? false : true;
		}

		root->isReverse = false;
	}



	if (rangeLeft > treeRightBoundary || rangeRight < treeLeftBoundary)
		return;

	if (rangeLeft <= treeLeftBoundary && rangeRight >= treeRightBoundary)
	{
		int temp = root->off;
		root->off = root->on;
		root->on = temp;

		if (treeLeftBoundary != treeRightBoundary)
		{
			if (root->left != NULL)
				root->left->isReverse = root->left->isReverse ? false : true;
			if (root->right != NULL)
				root->right->isReverse = root->right->isReverse ? false : true;
		}

		return;
	}

	if (rangeLeft <= (treeLeftBoundary + treeRightBoundary) / 2)
		setReverse(treeLeftBoundary, (treeLeftBoundary + treeRightBoundary) / 2, rangeLeft, rangeRight, root->left);
	if (rangeRight > (treeLeftBoundary + treeRightBoundary) / 2)
		setReverse((treeLeftBoundary + treeRightBoundary) / 2 + 1, treeRightBoundary, rangeLeft, rangeRight, root->right);

	root->off = 0;
	root->on = 0;

	if (root->left != NULL)
	{
		if (root->left->isReverse)
		{
			root->off += root->left->on;
			root->on += root->left->off;
		}
		else
		{
			root->off += root->left->off;
			root->on += root->left->on;
		}
	}
	if (root->right != NULL)
	{
		if (root->right->isReverse)
		{
			root->off += root->right->on;
			root->on += root->right->off;
		}
		else
		{
			root->off += root->right->off;
			root->on += root->right->on;
		}
	}
}


int getOnCount(int treeLeftBoundary, int treeRightBoundary, int rangeLeft, int rangeRight, node* root)
{
	if (root->isReverse == true)
	{
		int temp = root->off;
		root->off = root->on;
		root->on = temp;

		if (treeLeftBoundary != treeRightBoundary)
		{
			if (root->left != NULL)
				root->left->isReverse = root->left->isReverse ? false : true;
			if (root->right != NULL)
				root->right->isReverse = root->right->isReverse ? false : true;
		}

		root->isReverse = false;
	}

	if (rangeLeft > treeRightBoundary || rangeRight < treeLeftBoundary)
		return 0;

	if (rangeLeft <= treeLeftBoundary && rangeRight >= treeRightBoundary)
	{
		if (root->isReverse)
			return root->off;
		
		return root->on;
	}
	
	return getOnCount(treeLeftBoundary, (treeLeftBoundary + treeRightBoundary) / 2, rangeLeft, rangeRight, root->left) + getOnCount((treeLeftBoundary + treeRightBoundary) / 2 + 1, treeRightBoundary, rangeLeft, rangeRight, root->right);
}


#endif