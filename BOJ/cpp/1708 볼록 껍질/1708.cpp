#include <problem.h>

#ifdef _1708_

/// 
/// problem
/// https://www.acmicpc.net/problem/1708
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

bool cmp(pair<double, pair<int, int>> point1, pair<double, pair<int, int>> point2)
{
	if (point1.first == point2.first)
	{
		if(point1.second.second == point2.second.second)
			return point1.second.first < point2.second.first;

		return point1.second.second < point2.second.second;
	}
	else
		return point1.first < point2.first;
}

double getAngle(pair<int, int> point1, pair<int, int> point2)
{
	return atan2(point2.second - point1.second, point2.first - point1.first);
}

double getAngle(pair<int, int> point1, pair<int, int> point2, pair<int, int> point3)
{
	double angle1 = atan2(point2.second - point1.second, point2.first - point1.first);
	double angle2 = atan2(point2.second - point3.second, point2.first - point3.first);

	return fmod(angle1 - angle2 + 2 * M_PI, 2 * M_PI);
}

double getDistance(pair<int, int> point1, pair<int, int> point2)
{
	return sqrt(pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2));
}

vector<pair<int, int>> input()
{
	int count = 0;
	cin >> count;

	vector<pair<int, int>> points(count, pair<int, int>());

	for (int i = 0; i < count; i++)
	{
		cin >> points[i].first >> points[i].second;
	}
	return points;
}

vector<pair<double, pair<int, int>>> getAngles(vector<pair<int, int>>& points)
{
	pair<int, int> startPoint = points[0];

	for (int i = 0; i < points.size(); i++)
	{

		if (points[i].second < startPoint.second || (points[i].second == startPoint.second && points[i].first < startPoint.first))
		{
			startPoint = points[i];
		}
	}

	vector<pair<double, pair<int, int>>> angles;
	angles.push_back(pair<double, pair<int, int>>(0.0, startPoint));
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i] == startPoint)
			continue;

		double angle = getAngle(startPoint, points[i]);

		angles.push_back(pair<double, pair<int, int>>(angle, points[i]));
	}

	sort(angles.begin(), angles.end(), cmp);

	return angles;
}

long long int CCW(pair<int, int > point1, pair<int, int > point2, pair<int, int > point3)
{
	vector<long long int> vector1 = { point2.first - point1.first, point2.second - point1.second };
	vector<long long int> vector2 = { point3.first - point2.first, point3.second - point2.second };
	auto f = vector1[0] * vector2[1];
	auto s = vector1[1] * vector2[0];
	return vector1[0] * vector2[1] - vector1[1] * vector2[0];

}

int process(vector<pair<double, pair<int, int>>>& points)
{
	if (points.size() == 3)
		return 3;

	stack<pair<int, int>> pointStack;
	pointStack.push(points[0].second);
	pointStack.push(points[1].second);

	for (int i = 2; i < points.size(); i++)
	{
		auto now = pointStack.top();
		pointStack.pop();
		auto prev = pointStack.top();
		pointStack.push(now);

		int ccw = CCW(prev, now, points[i].second);
		if (ccw == 0)
		{
			if (getDistance(prev, now) < getDistance(prev, points[i].second))
			{
				pointStack.pop();
				pointStack.push(points[i].second);
			}
		}
		else if (ccw > 0)
		{
			pointStack.push(points[i].second);
		}
		else
		{
			pointStack.pop();
			i--;
		}
	}

	return pointStack.size();
}


int main()
{
	auto points = input();

	auto angles = getAngles(points);

	cout << process(angles) << endl;

	return 0;
}

#endif
