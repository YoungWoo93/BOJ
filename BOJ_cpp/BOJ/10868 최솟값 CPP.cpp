#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _10868_
// https://www.acmicpc.net/problem/10868

#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
	int min;

	node* left;
	node* right;
}node;

void input(vector<int>* arr, vector<pair<int, int>>* questions);
node* getSegmentTree(int start, int end, vector<int>* arr);
int getMinMax(int left, int right, int start, int end, node* root);

int main()
{
	vector<int> arr;
	vector<pair<int, int>> question;
	input(&arr, &question);





	node* root = getSegmentTree(0, arr.size() - 1, &arr);

	for (int i = 0; i < question.size(); i++)
	{
		cout << getMinMax(question[i].first, question[i].second, 0, arr.size() - 1, root) << "\n";
	}
}

void input(vector<int>* arr, vector<pair<int, int>>* questions)
{
	int M, N, input1, input2;
	cin >> M;
	cin >> N;

	for (int i = 0; i < M; i++)
	{
		cin >> input1;
		arr->push_back(input1);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> input1;
		cin >> input2;

		questions->push_back(make_pair(input1 - 1, input2 - 1));
	}
}

node* getSegmentTree(int start, int end, vector<int>* arr)
{
	if (start == end)
	{
		node* ret = new node();
		ret->min = arr->at(start);
		ret->left = NULL;
		ret->right = NULL;

		return ret;
	}

	node* ret = new node();
	node* left = getSegmentTree(start, (start + end) / 2, arr);
	node* right = getSegmentTree((start + end) / 2 + 1, end, arr);

	ret->min = (left->min < right->min ? left->min : right->min);
	ret->left = left;
	ret->right = right;

	return ret;
}

int getMinMax(int left, int right, int start, int end, node* root)
{
	int mid = (start + end) / 2;
	int r, ret;

	ret = -1;

	if (start > right || end < left)
		return ret;
	if (start >= left && end <= right)
		return root->min;



	if (left <= mid)
		ret = getMinMax(left, right, start, mid, root->left);


	if (right > mid)
	{
		r = getMinMax(left, right, mid + 1, end, root->right);

		if (ret == -1)
			ret = r;
		else
			ret = (ret < r ? ret : r);
	}

	return ret;
}




#endif