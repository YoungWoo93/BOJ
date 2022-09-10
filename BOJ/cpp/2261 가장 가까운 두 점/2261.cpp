#include <problem.h>

#ifdef _2261_

/// 
/// problem
/// https://www.acmicpc.net/problem/2261
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;

struct point2D {
	int x;
	int y;

	bool operator==(point2D target)
	{
		return x == target.x && y == target.y;
	}
};

bool sortRuleX(point2D first, point2D second)
{
	if (first.x == second.x)
		return first.y < second.y;

	return first.x < second.x;
};

bool sortRuleY(point2D first, point2D second)
{
	if (first.y == second.y)
		return first.x < second.x;

	return first.y < second.y;
};

int distance(point2D first, point2D second)
{
	return (first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y);
}

vector<point2D> input()
{
	int pointCount;
	vector<point2D> ret;
	cin >> pointCount;

	for (int i = 0; i < pointCount; i++)
	{
		point2D temp;
		cin >> temp.x >> temp.y;

		ret.push_back(temp);
	}

	return ret;
}

void inputPreprocess(vector<point2D>& points)
{
	sort(points.begin(), points.end(), sortRuleX);
	auto uniquePtr = unique(points.begin(), points.end());

	if (uniquePtr != points.end())
	{
		points.clear();
		return;
	}

	points.erase(uniquePtr, points.end());
}

int getMinDistance(vector<point2D>& points, int start, int end, int min)
{
	int mid = (start + end) / 2;
	int ret = min;

	if (mid + 1 > points.size() - 1)
		return ret;

	if (end > points.size() - 1)
		end = points.size() - 1;

	vector<point2D> temp;
	for (int i = mid; i >= start; i--)
	{
		if (pow(points[i].x - points[mid + 1].x, 2) >= ret)
			break;

		temp.push_back(points[i]);
	}
	for (int i = mid + 1; i <= end; i++)
	{
		if (pow(points[i].x - points[mid].x, 2) >= ret)
			break;

		temp.push_back(points[i]);
	}

	sort(temp.begin(), temp.end(), sortRuleY);

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if (pow(temp[i].y - temp[j].y, 2) >= ret)
				break;

			auto dist = distance(temp[i], temp[j]);
			if (ret > dist)
				ret = dist;
		}
	}

	return ret;
}

int makeSegmentTree(vector<int>& tree, vector<point2D>& points, int cur)
{
	if (cur * 2 < tree.size())
	{
		int start, end, min;
		int treeDepth = log2(tree.size() / 2);
		int curDepth = log2(cur);

		start = cur * pow(2, (treeDepth - curDepth)) - (tree.size() / 2);
		end = (cur + 1) * pow(2, (treeDepth - curDepth)) - 1 - (tree.size() / 2);


		auto left = makeSegmentTree(tree, points, cur * 2);
		min = left;

		auto right = makeSegmentTree(tree, points, cur * 2 + 1);
		min = min < right ? min : right;

		int mid = getMinDistance(points, start, end, min);
		min = min < mid ? min : mid;

		tree[cur] = min;
	}

	return tree[cur];
}

vector<int> getSegmentTree(vector<point2D>& points)
{
	if (points.empty())
		return { 0, 0 };

	int treeSize = pow(2, ceil(log2(points.size())));

	vector<int> ret(treeSize * 2, INT_MAX);
	makeSegmentTree(ret, points, 1);

	return ret;
}

int main()
{
	auto pointList = input();
	inputPreprocess(pointList);
	auto tree = getSegmentTree(pointList);

	cout << tree[1] << endl;

	return 0;
}

#endif
