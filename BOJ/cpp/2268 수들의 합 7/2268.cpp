#include <problem.h>

#ifdef _2268_

/// 
/// problem
/// https://www.acmicpc.net/problem/2268
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

struct cmd {
	int type;
	int value1;
	int value2;
};

vector<unsigned long long int> input(int &cmdCount)
{
	int numberSize = 0;
	scanf("%d %d", &numberSize, &cmdCount);
	
	int treeSize = pow(2, ceil(log2(numberSize)));
	vector<unsigned long long int> ret(treeSize * 2, 0);


	return ret;
}

unsigned long long int sumFunction(vector<unsigned long long int>& tree, int start, int end, int cur, int sumRangeStart, int sumRangeEnd)
{
	if (sumRangeEnd < start || end < sumRangeStart)
		return 0;

	if (sumRangeStart <= start && end <= sumRangeEnd)
		return tree[cur];

	int mid = (start + end) / 2;

	return sumFunction(tree, start, mid, cur * 2, sumRangeStart, sumRangeEnd) + sumFunction(tree, mid + 1, end, cur * 2 + 1, sumRangeStart, sumRangeEnd);
}

void modifyFunction(vector<unsigned long long int>&tree, int start, int end, int cur, int changeIndex, int offset)
{
	if (changeIndex < start || end < changeIndex)
		return;

	tree[cur] += offset;

	if (changeIndex == cur)
		return;

	int mid = (start + end) / 2;
	modifyFunction(tree, start, mid, cur * 2, changeIndex, offset);
	modifyFunction(tree, mid + 1, end, cur * 2 + 1, changeIndex, offset);
}

int main()
{
	int cmdCount;
	auto tree = input(cmdCount);

	int startIndex = tree.size() / 2;
	int endIndex = tree.size() - 1;


	for (int i = 0; i < cmdCount; i++)
	{
		int type, value1, value2;
		scanf("%d %d %d", &type, &value1, &value2);

		if (type == 0)
		{
			int sumStart = startIndex + value1 - 1;
			int sumEnd = startIndex + value2 - 1;
			if (sumStart > sumEnd)
				swap(sumStart, sumEnd);
		
			printf("%lld\n", sumFunction(tree, startIndex, endIndex, 1, sumStart, sumEnd));
		}
		else if (type == 1)
		{
			int changeIndex = startIndex + value1 - 1;
			int offset = value2 - tree[changeIndex];

			modifyFunction(tree, startIndex, endIndex, 1, changeIndex, offset);
		}
	}

	return 0;
}
#endif
