#include <problem.h>

#ifdef _24508_

/// 
/// problem
/// https://www.acmicpc.net/problem/24508
/// 
/// solution
/// 
/// 

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;


int main()
{
	long long int bucketCount, limit, count;

	cin >> bucketCount >> limit >> count;

	vector<long long int> buckets(bucketCount, 0);

	for (int i = 0; i < bucketCount; i++)
		cin >> buckets[i];

	sort(buckets.begin(), buckets.end(), greater<int>());

	for (int i = 0; i < buckets.size(); i++)
	{
		if (i == buckets.size() - 1)
			break;

		long long int req = limit - buckets[i];
		if (req <= 0)
			buckets.back() += -req;
		else
		{
			auto spare = min(req, buckets.back());
			buckets[i--] += spare;
			buckets.back() -= spare;

			if (buckets.back() == 0)
				buckets.pop_back();

			count -= spare;
		}

	}

	while (buckets.back() == 0)
		buckets.pop_back();

	if (count < 0 || buckets.back() < limit)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}
#endif
