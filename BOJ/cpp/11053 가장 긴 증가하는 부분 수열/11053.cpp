#include <problem.h>

#ifdef _11053_

/// 
/// problem
/// https://www.acmicpc.net/problem/11053
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input()
{
	int count;
	cin >> count;

	vector<int> ret(count, 0);

	for (int i = 0; i < count; i++)
		cin >> ret[i];

	return ret;
}

int getMax(vector<int>& arr, int end)
{
	int max = 0;

	for (int i = 0; i < end; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

int process(vector<int>& arr)
{
	vector<int> result(1000, 0);

	int ret = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		result[arr[i]] = getMax(result, arr[i]) + 1;
		ret = max(result[arr[i]], ret);
	}

	return ret;
}


int main()
{
	auto list = input();

	cout << process(list) << endl;

	return 0;
}
#endif
