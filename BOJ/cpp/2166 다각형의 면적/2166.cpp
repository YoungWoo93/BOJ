#include <problem.h>

#ifdef _2166_

/// 
/// problem
/// https://www.acmicpc.net/problem/2166
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	int count = 0;
	cin >> count;

	vector<pair<double, double>> pointList(count + 1);

	for (int i = 0; i < count; i++)
		cin >> pointList[i].first >> pointList[i].second;

	pointList.back() = pointList.front();

	double temp = 0;
	for (int i = 1; i < pointList.size(); i++)
	{
		temp += pointList[i - 1].second * pointList[i].first;
		temp -= pointList[i - 1].first * pointList[i].second;
	}

	printf("%.1lf\n", abs(temp) / 2);

}


#endif
