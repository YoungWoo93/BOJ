#include <problem.h>

#ifdef _2014_

/// 
/// problem
/// https://www.acmicpc.net/problem/2014
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1753%EB%B2%88-%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C
/// 

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct primeNumber {
	int value;
	priority_queue<unsigned long long int, vector<unsigned long long int>, greater<unsigned long long int>> pq;
};

vector<primeNumber> input(int& endIndex)
{
	int primeNumberCount;

	cin >> primeNumberCount;
	cin >> endIndex;

	vector<primeNumber> ret;
	for (int i = 0; i < primeNumberCount; i++)
	{
		primeNumber temp;
		cin >> temp.value;

		ret.push_back(temp);
	}

	return ret;
}

int main()
{
	int endIndex;
	auto primeNumberList = input(endIndex);

	vector<unsigned long long int> result;
	result.push_back(1);

	while (result.size() != endIndex + 1)
	{
		unsigned long long int tempValue = pow(2, 64);
		int tempIndex;

		for (int i=0; i<primeNumberList.size(); i++)
		{
			primeNumberList[i].pq.push(result.back());
			if (primeNumberList[i].pq.top() * primeNumberList[i].value == result.back())
				primeNumberList[i].pq.pop();

			if (primeNumberList[i].pq.top() * primeNumberList[i].value < tempValue)
			{
				tempValue = primeNumberList[i].pq.top() * primeNumberList[i].value;
				tempIndex = i;
			}
		}

		result.push_back(primeNumberList[tempIndex].pq.top() * primeNumberList[tempIndex].value);
		primeNumberList[tempIndex].pq.pop();
	}

	cout << result.back();
	return 0;
}
#endif
