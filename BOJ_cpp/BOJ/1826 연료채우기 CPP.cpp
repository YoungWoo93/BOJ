#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _1826_
// https://www.acmicpc.net/problem/1826

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



struct reve
{
	bool operator() (const int& left, const int& right) const
	{
		return left > right;
	}
};

void input(vector<pair<int, int>>& stationList, int stationCount);

int main()
{
	vector<pair<int, int>> stationList;
	multiset<int, reve> fuelList;

	int stationCount;
	int distence, fuel;
	int ret = 0;

	cin >> stationCount;

	input(stationList, stationCount);

	cin >> distence;
	cin >> fuel;

	stationList.push_back(make_pair(distence, 0));

	for (int i = 0; i < stationCount + 1; i++)
	{
		while (stationList[i].first > fuel)
		{
			if (fuelList.empty())
			{
				cout << -1;
				return 0;
			}

			fuel = fuel + *fuelList.begin();
			fuelList.erase(fuelList.begin());
			ret++;
		}

		if (fuel >= distence)
		{
			cout << ret;
			return 0;
		}

		fuelList.insert(stationList[i].second);
	}

	return 0;
}


void input(vector<pair<int, int>>& stationList, int stationCount)
{
	for (int i = 0; i < stationCount; i++)
	{
		int pos, volume;

		cin >> pos;
		cin >> volume;

		stationList.push_back(make_pair(pos, volume));
	}

	sort(stationList.begin(), stationList.end());
}


#endif