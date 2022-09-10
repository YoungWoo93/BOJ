#include <problem.h>

#ifdef _20149_

/// 
/// problem
/// https://www.acmicpc.net/problem/20149
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<double, double>> input()
{
	vector<pair<double, double>>  ret(4);

	for (int i = 0; i < 4; i++)
	{
		cin >> ret[i].first >> ret[i].second;
	}

	for (int i = 0; i < 4; i+=2)
	{
		if (ret[i] > ret[i + 1])
		{
			auto temp = ret[i];
			ret[i] = ret[i + 1];
			ret[i + 1] = temp;
		}
	}

	if (ret[0] > ret[2])
	{
		auto temp = ret[0];
		ret[0] = ret[2];
		ret[2] = temp;

		temp = ret[1];
		ret[1] = ret[3];
		ret[3] = temp;
	}
	return ret;
}

double CCW(pair<int, int > point1, pair<int, int > point2, pair<int, int > point3)
{
	vector<long long int> vector1 = { point2.first - point1.first, point2.second - point1.second };
	vector<long long int> vector2 = { point3.first - point2.first, point3.second - point2.second };

	return vector1[0] * vector2[1] - vector1[1] * vector2[0];

}

vector<double> crosscheck(pair<double, double > point1, pair<double, double > point2, pair<double, double > point3, pair<double, double > point4)
{
	vector<double> ret;
	ret.push_back(1);

	double d = (point1.first - point2.first) * (point3.second - point4.second) - (point1.second - point2.second) * (point3.first - point4.first);

	ret.push_back(((point1.first * point2.second - point1.second * point2.first) * (point3.first - point4.first) - (point1.first - point2.first) * (point3.first * point4.second - point3.second * point4.first)) / d);
	ret.push_back(((point1.first * point2.second - point1.second * point2.first) * (point3.second - point4.second) - (point1.second - point2.second) * (point3.first * point4.second - point3.second * point4.first)) / d);


	return ret;
}

vector<double> process(vector<pair<double, double>> points)
{
	auto ccwA = CCW(points[0], points[1], points[2]) * CCW(points[0], points[1], points[3]);
	auto ccwB = CCW(points[2], points[3], points[0]) * CCW(points[2], points[3], points[1]);

	vector<double> ret;

	if (ccwA > 0 || ccwB > 0)
		ret.push_back(0);
	else if (ccwA == 0 && ccwB == 0)
	{
		if(points[1] == points[2])
		{
			ret.push_back(1);
			ret.push_back(points[1].first);
			ret.push_back(points[1].second);
		}
		else if (points[1] == points[3])
		{
			ret.push_back(1);
			if (CCW(points[0], points[1], points[2]) != 0)
			{
				ret.push_back(points[1].first);
				ret.push_back(points[1].second);
			}
		}
		else if (points[0] == points[2])
		{
			ret.push_back(1);
			if (CCW(points[0], points[1], points[3]) != 0)
			{
				ret.push_back(points[0].first);
				ret.push_back(points[0].second);
			}
		}
		else if (points[2] <= points[1])
			ret.push_back(1);
		else
			ret.push_back(0);
	}
	else
	{
		ret = crosscheck(points[0], points[1], points[2], points[3]);
	}

	return ret;
}


int main()
{
	auto points = input();
	auto result = process(points);

	return 0;
}

#endif
