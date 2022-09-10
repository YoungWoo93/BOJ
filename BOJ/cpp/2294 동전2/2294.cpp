#include <problem.h>

#ifdef _2294_

/// 
/// problem
/// https://www.acmicpc.net/problem/2294
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int coinCount, target;
	cin >> coinCount >> target;

	vector<unsigned int> coins;
	for (int i = 0; i < coinCount; i++)
	{
		int temp;
		cin >> temp;

		coins.push_back(temp);
	}

	vector<unsigned int> dpTable(target + 1, -1);

	for (auto c : coins)
	{
		dpTable[c] = 1;
		for (int i = 0; i < target; i++)
		{
			if (dpTable[i] == -1)
				continue;

			if (i + c <= target)
			{
				if (dpTable[i + c] > dpTable[i] + 1)
					dpTable[i + c] = dpTable[i] + 1;
			}
		}
	}

	cout << (int)dpTable[target] << endl;

	return 0;
}
#endif
