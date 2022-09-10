#include <problem.h>

#ifdef _2042_

/// 
/// problem
/// https://www.acmicpc.net/problem/2042
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-2042%EB%B2%88-%EA%B5%AC%EA%B0%84-%ED%95%A9-%EA%B5%AC%ED%95%98%EA%B8%B0
/// 


#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

struct cmd {
	int type;
	int value1;
	long long int value2;
};

int getTreeSize(int n)
{
	return pow(2, ceil(log2(n)));
}

long long int makeSegmentTree(vector<long long int>& arr, int cur)
{
	if (cur * 2 < arr.size())
		arr[cur] = makeSegmentTree(arr, cur * 2) + makeSegmentTree(arr, cur * 2 + 1);

	return arr[cur];
}

vector<long long int> input(queue<cmd>& cmdList)
{
	int numberSize, changeCount, sumCount;
	cin >> numberSize >> changeCount >> sumCount;
	
	int treeSize = getTreeSize(numberSize);
	vector<long long int> ret(treeSize * 2, 0);

	for (int i = 0; i < numberSize; i++)
		cin >> ret[treeSize + i];
	
	makeSegmentTree(ret, 1);

	for (int i = 0; i < changeCount + sumCount; i++)
	{
		cmd temp;

		cin >> temp.type >> temp.value1 >> temp.value2;
		cmdList.push(temp);
	}

	return ret;
}

long long int sumFunction(vector<long long int>& tree, int start, int end, int cur, int sumRangeStart, int sumRangeEnd)
{
	if (sumRangeEnd < start || end < sumRangeStart)
		return 0;

	if (sumRangeStart <= start && end <= sumRangeEnd)
		return tree[cur];

	int mid = (start + end) / 2;

	return sumFunction(tree, start, mid, cur * 2, sumRangeStart, sumRangeEnd) + sumFunction(tree, mid + 1, end, cur * 2 + 1, sumRangeStart, sumRangeEnd);
}

void changeFunction(vector<long long int>&tree, int start, int end, int cur, int changeIndex, long long int offset)
{
	if (changeIndex < start || end < changeIndex)
		return;

	tree[cur] += offset;

	if (changeIndex == cur)
		return;

	int mid = (start + end) / 2;
	changeFunction(tree, start, mid, cur * 2, changeIndex, offset);
	changeFunction(tree, mid + 1, end, cur * 2 + 1, changeIndex, offset);
}

int main()
{
	queue<cmd> cmdList;
	auto tree = input(cmdList);

	int startIndex = tree.size() / 2;
	int endIndex = tree.size() - 1;

	while (!cmdList.empty())
	{
		auto cmd = cmdList.front();

		if (cmd.type == 1)
		{
			int changeIndex = startIndex + cmd.value1 - 1;
			int offset = cmd.value2 - tree[changeIndex];

			changeFunction(tree, startIndex, endIndex, 1, changeIndex, offset);
		}
		else if (cmd.type == 2)
		{
			int sumStart = startIndex + cmd.value1 - 1;
			int sumEnd = startIndex + cmd.value2 - 1;

			cout << sumFunction(tree, startIndex, endIndex, 1, sumStart, sumEnd) << endl;
		}
		cmdList.pop();
	}

	return 0;
}
#endif
