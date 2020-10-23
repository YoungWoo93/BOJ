#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _1725_
// https://www.acmicpc.net/problem/1725

#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
	unsigned long long int value;
	unsigned long long int index;

	node* left;
	node* right;
}node;

bool input(vector<int>* arr);
node* getSegmentTree(int start, int end, vector<int>* arr);
node* getMinIndex(int leftBoundery, int rightBoundery, int start, int end, node* root);
unsigned long long int getMaxArea(int leftBoundery, int rightBoundery, int start, int end, node* root);

int main()
{
	vector<int> arr;

	input(&arr);
	
	node* root = getSegmentTree(0, arr.size() - 1, &arr);

	cout << getMaxArea(1, arr.size(), 1, arr.size(), root);


}

bool input(vector<int>* arr)
{
	int count;
	cin >> count;

	if (count == 0)
		return false;
	arr->clear();

	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;

		arr->push_back(temp);
	}
	arr->push_back(0);
	return true;
}

node* getSegmentTree(int start, int end, vector<int>* arr)
{
	if (start == end)
	{
		node* ret = new node();
		ret->value = arr->at(start);
		ret->index = start;
		ret->left = NULL;
		ret->right = NULL;

		return ret;
	}

	node* ret = new node();
	node* left = getSegmentTree(start, (start + end) / 2, arr);
	node* right = getSegmentTree((start + end) / 2 + 1, end, arr);

	ret->value = (left->value < right->value ? left->value : right->value);
	ret->index = (left->value < right->value ? left->index : right->index);

	ret->left = left;
	ret->right = right;

	return ret;
}

node* getMinIndex(int leftBoundery, int rightBoundery, int start, int end, node* root)
{
	int mid = (start + end) / 2;
	node* r;
	node* ret;

	ret = (node*)NULL;

	if (start > rightBoundery || end < leftBoundery)
		return ret;
	if (start >= leftBoundery && end <= rightBoundery)
		return root;



	if (leftBoundery <= mid)
		ret = getMinIndex(leftBoundery, rightBoundery, start, mid, root->left);


	if (rightBoundery > mid)
	{
		r = getMinIndex(leftBoundery, rightBoundery, mid + 1, end, root->right);

		if (ret == NULL)
			ret = r;
		else
		{
			ret = (ret->value < r->value ? ret : r);
		}

	}

	return ret;
}

unsigned long long int getMaxArea(int leftBoundery, int rightBoundery, int start, int end, node* root)
{
	node* tempNode = getMinIndex(leftBoundery, rightBoundery, start, end, root);
	if (tempNode == NULL)
		return 0;

	unsigned long long int tempArea = tempNode->value * (rightBoundery - leftBoundery + 1);
	//	cout << "[" << leftBoundery - 1 << "~" << rightBoundery - 1 << "] 구간 최소값 [" << tempNode->value << "] 이용 " << tempArea << endl;

	unsigned long long int leftArea = getMaxArea(leftBoundery, tempNode->index, start, end, root);
	unsigned long long int rightArea = getMaxArea(tempNode->index + 2, rightBoundery, start, end, root);

	if (tempArea < leftArea)
		tempArea = leftArea;
	if (tempArea < rightArea)
		tempArea = rightArea;

	return tempArea;
}

#endif