#include <problem.h>

#ifdef _1011_

/// 19
/// problem
/// https://www.acmicpc.net/problem/1011
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<unsigned int, unsigned int>> input()
{
	int count;
	vector<pair<unsigned int, unsigned int>> ret;

	cin >> count;

	for (int i = 0; i < count; i++)
	{
		pair<unsigned int, unsigned int> temp;
		
		cin >> temp.first >> temp.second;
		ret.push_back(temp);
	}

	return ret;
}

int main()
{
	auto inputs = input();

	for (int i = 0; i < inputs.size(); i++)
	{
		unsigned int distance = inputs[i].second - inputs[i].first;
		unsigned int N = sqrt(distance);

		int d = distance - pow(N, 2);
		
		if (d == 0)
			cout << N * 2 - 1 << endl;
		else if (d <= N)
			cout << N * 2 << endl;
		else
			cout << N * 2 + 1 << endl;
	}

	return 0;
}
#endif
