#include <problem.h>

#ifdef _2877_

/// 
/// problem
/// https://www.acmicpc.net/problem/2877
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> arr(32, 0);
vector<int> sum(32, 0);

int process(int& number, int& index)
{
	int ret = 4;

	if (number <= sum[index - 1] + arr[index] / 2)
	{
		ret = 4;
		number -= arr[index] / 2;
		index--;
	}
	else
	{
		ret = 7;
		number -= arr[index];
		index--;
	}

	return ret;
}

int main()
{
	arr[0] = 1;
	sum[0] = 0;
	for (int i = 1; i < 31; i++)
	{
		arr[i] = arr[i - 1] * 2;
		sum[i] = sum[i - 1] + arr[i];
	}


	int k = 0;
	int index = 0;
	cin >> k;

	for (; k > sum[index]; index++);
	while (k)
		cout << process(k, index);
	cout << endl;

}
#endif
