#include <problem.h>

#ifdef _6549_

/// 
/// problem
/// https://www.acmicpc.net/problem/6549
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>
using namespace std;

int getTreeSize(int n)
{
	return pow(2, ceil(log2(n)));
}

vector<int> input(int count)
{
	vector<int> ret(count, 0);

	for (int i = 0; i < count; i++)
	{
		cin >> ret[i];
	}


	return ret;
}


pair<unsigned long long int, int> makeSegmentTree(vector<pair<unsigned long long int, int>>& arr, int cur)
{
	if (cur * 2 < arr.size())
	{
		auto left = makeSegmentTree(arr, cur * 2);
		auto right = makeSegmentTree(arr, cur * 2 + 1);
		arr[cur] = left.first < right.first ? left : right;
	}

	return arr[cur];
}

vector<pair<unsigned long long int, int>> getSegmentTree(vector<int>& arr)
{
	int size = getTreeSize(arr.size());
	vector<pair<unsigned long long int, int>> ret(size * 2, pair<unsigned long long int, int>(LLONG_MAX, 0));


	for (int i = 0; i < arr.size(); i++)
	{
		ret[size + i].first = arr[i];
		ret[size + i].second = i;
	}

	makeSegmentTree(ret, 1);

	return ret;
}

pair<unsigned long long int, int> getMinIndex(vector<pair<unsigned long long int, int>>& histogram, int start, int end, int cur, int rangeStart, int rangeEnd)
{
	if (rangeEnd < start || end < rangeStart)
		return pair<unsigned long long int, int>(LLONG_MAX, 0);

	if (rangeStart <= start && end <= rangeEnd)
		return histogram[cur];

	int mid = (start + end) / 2;
	auto left = getMinIndex(histogram, start, mid, cur * 2, rangeStart, rangeEnd);
	auto right = getMinIndex(histogram, mid + 1, end, cur * 2 + 1, rangeStart, rangeEnd);
	return left.first < right.first ? left : right;
}

unsigned long long int getMaxSize(vector<pair<unsigned long long int, int>>& histogram, int start, int end, int cur, int rangeStart, int rangeEnd)
{
	if (rangeStart == rangeEnd)
		return histogram[rangeStart].first;

	unsigned long long int ret = 0;

	int minIndex = getMinIndex(histogram, start, end, cur, rangeStart, rangeEnd).second + start;


	vector<unsigned long long int> maxValue;
	if (minIndex != rangeStart)
		maxValue.push_back(getMaxSize(histogram, start, end, cur, rangeStart, minIndex - 1));

	if (minIndex != rangeEnd)
		maxValue.push_back(getMaxSize(histogram, start, end, cur, minIndex + 1, rangeEnd));

	maxValue.push_back((rangeEnd - rangeStart + 1) * histogram[minIndex].first);

	return *max_element(maxValue.begin(), maxValue.end());
}

int main()
{
	while (true)
	{
		int count;
		cin >> count;

		if (count == 0)
			break;

		auto histogram = input(count);
		auto segmentTree = getSegmentTree(histogram);
		int size = getTreeSize(count);

		cout << getMaxSize(segmentTree, size, segmentTree.size() - 1, 1, size, size + count - 1) << endl;

	}
	return 0;
}
#endif

