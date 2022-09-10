#include <problem.h>


#ifdef _11049_

/// 
/// problem
/// https://www.acmicpc.net/problem/11049
/// 
/// solution
/// 
/// 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

void input(vector<pair<unsigned long long int, unsigned long long int>>& arr)
{
	int count;
	cin >> count;

	arr.assign(count, { 0, 0 });

	for (int i = 0; i < count; i++)
		cin >> arr[i].first >> arr[i].second;
}

void print(vector<vector<unsigned long long int>>& dps)
{
	for (int i = 0; i < dps.size(); i++)
	{
		for (int j = 0; j < dps.size(); j++)
		{
			if (dps[i][j] >= UINT16_MAX)
				cout << "--\t";
			else
				cout << dps[i][j] << "\t";
		}
		cout << endl;
	}
}

unsigned long long int process(vector<pair<unsigned long long int, unsigned long long int>>& arr)
{
	vector<vector<unsigned long long int>> dpTable(arr.size(), vector<unsigned long long int>(arr.size(), UINT_MAX));

	for (int i = 0; i < arr.size(); i++)
		dpTable[i][i] = 0;


	print(dpTable);
	//i시작 j종료의 최적해
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			for (int k = 1; k <= i - j; k++)
				dpTable[i][j] = min(dpTable[i][j], dpTable[i - k][j] + dpTable[i][j + (i - j) - k + 1] + (arr[j].first * arr[i - k].second * arr[i].second));
		}
	}

	return dpTable[arr.size() - 1][0];
}

int main()
{
	vector<pair<unsigned long long int, unsigned long long int>> arr;
	input(arr);

	cout << process(arr) << endl;

	return 0;
}

#endif
