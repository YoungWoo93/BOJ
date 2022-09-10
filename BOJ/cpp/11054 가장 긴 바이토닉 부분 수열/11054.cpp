#include <problem.h>

#ifdef _11054_

/// 
/// problem
/// https://www.acmicpc.net/problem/11054
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-11054-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EB%B0%94%EC%9D%B4%ED%86%A0%EB%8B%89-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4
/// 

#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>

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

int getlongestBitonic(vector<int>& arr)
{
	vector<int> left(1000, 0);
	vector<int> right(1000, 0);
	vector<int> result(arr.size(), 0);


	for (int i = 0; i < arr.size(); i++)
	{
		left[arr[i]] = getMax(left, arr[i]) + 1;
		result[i] += left[arr[i]];
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		right[arr[i]] = getMax(right, arr[i]) + 1;
		result[i] += right[arr[i]];
	}

	return *max_element(result.begin(), result.end()) - 1;
}


int main()
{
	auto list = input();

	cout << getlongestBitonic(list);

	return 0;
}
#endif
