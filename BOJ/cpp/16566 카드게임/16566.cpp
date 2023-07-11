#include <problem.h>

#ifdef _16566_

/// 
/// problem
/// https://www.acmicpc.net/problem/16566
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int getTreeSize(int n)
{
	return pow(2, ceil(log2(n)));
}


unsigned int makeSegmentTree(vector<unsigned int>& arr, int cur)
{
	if (cur * 2 < arr.size())
		arr[cur] = min(makeSegmentTree(arr, cur * 2), makeSegmentTree(arr, cur * 2 + 1));

	return arr[cur];
}

unsigned int findFunction(vector<unsigned int>& tree, int start, int end, int cur, int rangeStart, int rangeEnd)
{
	if (rangeEnd < start || end < rangeStart)
		return -1;

	if (rangeStart <= start && end <= rangeEnd)
		return tree[cur];

	int mid = (start + end) / 2;

	return min(findFunction(tree, start, mid, cur * 2, rangeStart, rangeEnd), findFunction(tree, mid + 1, end, cur * 2 + 1, rangeStart, rangeEnd));
}

void removeFunction(vector<unsigned int>& tree, int index)
{
	unsigned int temp = tree[index];
	int parent = index / 2;
	tree[index] = -1;

	if (parent == 0)
		return;
	if (tree[parent] != temp)
		return;
	

	int ret = min(tree[parent * 2], tree[parent * 2 + 1]);
	if (ret == -1)
		removeFunction(tree, index / 2);
	else
		tree[parent] = ret;
}


void input(vector<unsigned int>& segmentTree, int& cards)
{
	int N, M;

	cin >> N >> M >> cards;
	segmentTree.assign(getTreeSize(N) * 2, -1);

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		segmentTree[segmentTree.size() / 2 + temp - 1] = temp;
	}

	auto ret = makeSegmentTree(segmentTree, 1);


}



int main()
{
	vector<unsigned int> segmentTree;
	int cards;

	input(segmentTree, cards);

	int startIndex = segmentTree.size() / 2;
	int endIndex = segmentTree.size() - 1;

	for (int i = 0; i < cards; i++)
	{
		int temp;
		cin >> temp;

		temp = findFunction(segmentTree, startIndex, endIndex, 1, startIndex + temp, endIndex);
		if (temp == -1)
		{
			for (int i = startIndex; i <= endIndex; i++)
			{
				if (segmentTree[i] != -1)
				{
					temp = segmentTree[i];
					break;
				}
			}
		}
		cout << temp << endl;

		removeFunction(segmentTree, startIndex + temp - 1);
	}

	return 0;
}
#endif
