#include <problem.h>

#ifdef _24884_

/// 
/// problem
/// https://www.acmicpc.net/problem/24884
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

vector<int> input(int& N, int& W, int& T, int& K)
{
	cin >> N >> W >> T >> K;
	W++;

	vector<int> ret(N + 2, 0);

	for (int i = 1; i < N + 1; i++)
		cin >> ret[i];

	return ret;
}

vector<int> powerDown(vector<int>* fires, int feedIndex, int K)
{
	vector<int> ret((*fires).size(), 0);
	int fireCount = 0;

	for (int i = 1; i < fires->size() - 1; i++)
	{
		if ((*fires)[i] <= 0)
		{
			ret[i] = 0;
			continue;
		}


		ret[i] = (*fires)[i];

		if (i != feedIndex)
		{
			int count = 3;

			if ((*fires)[i - 1] > 0)
				count--;
			if ((*fires)[i + 1] > 0)
				count--;

			ret[i] = (*fires)[i] - count;
		}

		if (ret[i] > 0)
			fireCount++;
	}

	if (fireCount < K)
		return vector<int>();

	return ret;
}

int simulate(vector<int> fires, int position, int time, int K, int feedIndex)
{
	vector<int> currentFires = powerDown(&fires, feedIndex, K);

	if (currentFires.empty())
		return 0;

	time--;
	if (time <= 0)
		return 1;

	int ret = 0;

	if (position > 1)
		ret += simulate(currentFires, position - 1, time, K, position - 1);
	if (position < fires.size() - 2)
		ret += simulate(currentFires, position + 1, time, K, position + 1);
	ret += simulate(currentFires, position, time, K, position);

	return ret;
}

int main()
{
	int N;
	int W;
	int T;
	int K;

	auto fires = input(N, W, T, K);
	cout << simulate(fires, W, T, K, 0) << endl;

	return 0;
}
#endif

