#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _10266_
// https://www.acmicpc.net/problem/10266

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<int> &arr1, vector<int> &arr2);
vector<int> getPi(vector<int> &arr);
bool kmp(vector<int> &clock1, vector<int> &clock2);

int main()
{
	vector<int> clock1;
	vector<int> clock2;


	input(clock1, clock2);

	if (kmp(clock2, clock1))
		cout << "possible";
	else
		cout << "impossible";

	return 0;
}


void input(vector<int> &arr1, vector<int> &arr2)
{
	int count, temp;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		arr1.push_back(temp % 360);
	}

	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		arr2.push_back(temp % 360);
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	int temp1, temp2;
	temp1 = arr1[0] - arr1[count - 1] + 360;
	temp2 = arr2[0] - arr2[count - 1] + 360;

	for (int i = count - 1; i > 0; i--)
	{
		arr1[i] = arr1[i] - arr1[i - 1];
		arr2[i] = arr2[i] - arr2[i - 1];
	}
	arr1[0] = temp1;
	arr2[0] = temp2;

	for (int i = 0; i < count; i++)
		arr1.push_back(arr1[i]);

}

vector<int> getPi(vector<int> &arr)
{
	vector<int> pi(arr.size(), 0);
	int j = 0;

	for (int i = 1; i< arr.size(); i++)
	{
		while (j > 0 && arr[i] != arr[j])
		{
			j = pi[j - 1];
		}

		if (arr[i] == arr[j])
			pi[i] = ++j;
	}
	return pi;
}




bool kmp(vector<int> &clock1, vector<int> &clock2)
{
	vector<int> ans;
	auto pi = getPi(clock1);
	int n = clock2.size();
	int m = clock1.size();
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		while (j>0 && clock2[i] != clock1[j])
			j = pi[j - 1];

		if (clock2[i] == clock1[j])
		{
			if (j == m - 1)
				return true;
			else
				j++;
		}
	}

	return false;
}

#endif

