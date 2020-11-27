#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _2014_
// https://www.acmicpc.net/problem/2014

#include <iostream>
#include <vector>

using namespace std;

void input(int& primeCount, int& targetNo, vector<int>& primeList);
vector<long long int> getDP(int targetNo, vector<int> primeList);

int global_count = 0;

int main()
{
	int primeCount;
	int targetNo;
	vector<int> primeList;

	input(primeCount, targetNo, primeList);

	vector<long long int> DP = getDP(targetNo, primeList);

	cout << DP[targetNo];

	return 0;
}



void input(int& primeCount, int& targetNo, vector<int>& primeList)
{
	cin >> primeCount;
	cin >> targetNo;

	for (int i = 0; i < primeCount; i++)
	{
		int temp;
		cin >> temp;

		primeList.push_back(temp);
	}
}

vector<long long int> getDP(int targetNo, vector<int> primeList)
{
	vector<long long int> ret;

	ret.push_back(primeList[0]);
	primeList.erase(primeList.begin());

	while (ret.size() < targetNo)
	{
		long long int min = ret.back() * ret.back();
		
		for (int i = ret.size()-1; i >= 0; i--)
		{
			if (ret[i] * ret[i] <= ret.back())
				break;

			for (int j = 0; j <= i; j++)
			{
				if (ret[i] * ret[j] > ret.back())
				{
					if (ret[i] * ret[j] <= min)
						min = ret[i] * ret[j];

					break;
				}
			}
		}

		if (!primeList.empty() && primeList[0] < min)
		{
			ret.push_back(primeList[0]);
			primeList.erase(primeList.begin());
		}
		else
			ret.push_back(min);
	}

	return ret;
}


#endif