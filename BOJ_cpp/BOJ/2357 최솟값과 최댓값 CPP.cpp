#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _2357_
//https://www.acmicpc.net/problem/2357

#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
	int min;
	int max;

	node* left;
	node* right;
}node;

void input(vector<int>* arr, vector<pair<int, int>>* questions);
pair<int, int> getSegmentTree(int start, int end, int index, pair<int, int>* tree, vector<int>* arr);
pair<int, int> getMinMax(int left, int right, int start, int end, int index, pair<int, int>* tree);

int main()
{
	vector<int> arr;
	pair<int, int>* tree;
	vector<pair<int, int>> question;
	input(&arr, &question);


	tree = new pair<int, int>[arr.size() * 5];



	getSegmentTree(0, arr.size() - 1, 1, tree, &arr);
	cout << endl << endl;
	for (int i = 0; i < question.size(); i++)
	{
		if (i != 0)
			cout << '\n';
		pair<int, int> print = getMinMax(question[i].first, question[i].second, 0, arr.size() - 1, 1, tree);
		cout << print.first << " " << print.second;
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

pair<int, int> getSegmentTree(int start, int end, int index, pair<int, int>* tree, vector<int>* arr)
{
	if (start == end)
	{
		tree[index].first = arr->at(start);
		tree[index].second = arr->at(start);

		return tree[index];
	}


	pair<int, int> left = getSegmentTree(start, (start + end) / 2, index * 2, tree, arr);
	pair<int, int> right = getSegmentTree((start + end) / 2 + 1, end, index * 2 + 1, tree, arr);

	tree[index].first = (left.first < right.first ? left.first : right.first);
	tree[index].second = (left.second > right.second ? left.second : right.second);


	return tree[index];
}

pair<int, int> getMinMax(int left, int right, int start, int end, int index, pair<int, int>* tree)
{
	int mid = (start + end) / 2;
	pair<int, int> rightPair, ret;

	ret.first = -1;
	ret.second = -1;

	if (start > right || end < left)
		return ret;
	if (start >= left && end <= right)
		return tree[index];


	if (left <= mid)
		ret = getMinMax(left, right, start, mid, index * 2, tree);

	if (right > mid)
	{
		rightPair = getMinMax(left, right, mid + 1, end, index * 2 + 1, tree);

		if (ret.first == -1)
			ret = rightPair;
		else
		{
			ret.first = (ret.first < rightPair.first ? ret.first : rightPair.first);
			ret.second = (ret.second > rightPair.second ? ret.second : rightPair.second);
		}
	}

	return ret;
}

#endif