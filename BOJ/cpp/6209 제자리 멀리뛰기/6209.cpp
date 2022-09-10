#include <problem.h>

#ifdef _6209_

/// 
/// problem
/// https://www.acmicpc.net/problem/6209
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

vector<int> distances;

vector<int> input(int& d, int& m)
{
	int n;
	cin >> d >> n >> m;
	vector<int> ret;

	ret.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int D;
		cin >> D;

		ret.push_back(D);
	}
	ret.push_back(d);

	sort(ret.begin(), ret.end());
	for (int i = 1; i < n; i++)
	{
		distances.push_back(ret[i] - ret[i - 1]);
	}
	return ret;
}

bool search(vector<int>& stones, int erases, int jumpDistance)
{
	int eraseCount = 0;

	int temp = 0;
	for (int i = 1; i < stones.size(); i++)
	{
		if (stones[i] - stones[temp] < jumpDistance)
			eraseCount++;
		else
			temp = i;

		if (eraseCount > erases)
			break;
	}

	return eraseCount <= erases;
}

int main()
{
	int distance;
	int erases;
	auto stones = input(distance, erases);

	int s = 0;
	int e = 6;

	int answer = 0;


	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (search(stones, erases, mid))
		{
			s = mid + 1;
			answer = mid;
		}
		else
		{
			e = mid - 1;
		}
	}

	

	cout << answer << endl;


	return 0;
}
#endif

