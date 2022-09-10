#include <problem.h>

#ifdef _1016_

/// 
/// problem
/// https://www.acmicpc.net/problem/1016
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<unsigned long long int> getSquaredList(unsigned long long int max)
{
	vector<unsigned long long int> ret;

	for (unsigned long long int i = 2; pow(i, 2) <= max; i++)
	{
		ret.push_back(i * i);
	}

	return ret;
}

void process(unsigned long long int min, unsigned long long int max, vector<bool>& memo, vector<unsigned long long int>& squarList)
{
	for (int i = 0; i < squarList.size(); i++)
	{
		unsigned long long int offset = (squarList[i] - min % squarList[i]) % squarList[i];

		for (unsigned long long int j = offset; j < memo.size(); j += squarList[i])
		{
			memo[j] = false;
		}
	}
}

int main()
{
	unsigned long long int min, max;
	cin >> min >> max;

	vector<bool> memo(max - min + 1, true);
	auto squarList = getSquaredList(max);
	process(min, max, memo, squarList);

	int count = 0;
	for (int i = 0; i < memo.size(); i++)
	{
		if (memo[i])
			count++;
	}

	cout << count << endl;

	return 0;
}
#endif
