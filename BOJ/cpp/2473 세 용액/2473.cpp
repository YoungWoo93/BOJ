#include <problem.h>

#ifdef _2473_

/// 
/// problem
/// https://www.acmicpc.net/problem/2473
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

bool itemfind(vector<int>& list, int rangeStart, int rangeEnd, long long int target, long long int avarage, int& value)
{
	if (rangeStart > rangeEnd)
		return false;

	int mid = (rangeStart + rangeEnd) / 2;
	bool ret;

	if (abs(target - list[mid]) > avarage)
	{
		if (target > list[mid])
		{
			if (!itemfind(list, mid + 1, rangeEnd, target, avarage, value))
				return false;
		}
		else
		{
			if (!itemfind(list, rangeStart, mid - 1, target, avarage, value))
				return false;
		}

		return true;
	}
	
	
	
	value = list[mid];


	if (target > list[mid])
		itemfind(list, mid + 1, rangeEnd, target, avarage, value);
	else
		itemfind(list, rangeStart, mid - 1, target, avarage, value);


	if (abs(target - value) > abs(target - list[mid]))
		value = list[mid];

	return true;
}

int main()
{
	int count;
	cin >> count;

	vector<int> list(count);
	for (int i = 0; i < count; i++)
		cin >> list[i];

	sort(list.begin(), list.end());

	long long int best = LLONG_MAX;
	int answer[3];


	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			long long int temp = list[i] + list[j];
			int ret = 0;

			if (itemfind(list, j + 1, count - 1, -temp, abs(best) - 1, ret))
			{
				best = temp + ret;
				answer[0] = list[i];
				answer[1] = list[j];
				answer[2] = ret;
			}

			if (best == 0)
				break;
		}

		if (best == 0)
			break;
	}

	for (int i = 0; i < 3; i++)
		cout << answer[i] << " ";

	return 0;
}
#endif
