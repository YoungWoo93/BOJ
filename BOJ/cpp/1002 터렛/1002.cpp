#include <problem.h>

#ifdef _1002_

/// 
/// problem
/// https://www.acmicpc.net/problem/1002
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1002%EB%B2%88-%ED%84%B0%EB%A0%9B
/// 

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		pair<int, int> first;
		pair<int, int> second;
		int dist1;
		int dist2;

		cin >> first.first >> first.second;
		cin >> dist1;
		cin >> second.first >> second.second;
		cin >> dist2;

		auto dist = sqrt(pow(first.first - second.first, 2) + pow(first.second - second.second, 2));

		if (dist == 0.0)
		{
			if (dist1 == dist2)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			int big = dist1 > dist2 ? dist1 : dist2;
			int small = dist1 > dist2 ? dist2 : dist1;

			if (big > dist + small)
				cout << 0 << endl;
			else if (dist > big + small)
				cout << 0 << endl;
			else if (dist + small == big)
				cout << 1 << endl;
			else if (dist == big + small)
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}

	}

	return 0;
}
#endif
