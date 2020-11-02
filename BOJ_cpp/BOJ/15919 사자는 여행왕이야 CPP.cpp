#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _15919_
// https://www.acmicpc.net/problem/15919

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<pair<int, int>>& arr, int count);

int main()
{
	int days;
	int candidateCount;
	vector<pair<int, int>> candidate;
	vector<int> valueList;
	cin >> days;
	cin >> candidateCount;

	candidate.push_back(make_pair(0, 0));
	input(candidate, candidateCount);
	candidate.push_back(make_pair(days + 1, days + 1));

	valueList.resize(candidateCount + 1);

	for (int i = candidateCount; i >= 0; i--)
	{
		int temp = days - candidate[i].second;
		valueList[i] = temp;
		for (int j = i+1; j < candidateCount + 2; j++)
		{
			int distence = candidate[j].first - candidate[i].second - 1;

			if (distence >= 0)
			{
				if (distence >= temp)
					break;
				
				temp = min(temp, max(distence, valueList[j]));
			}
		}
		valueList[i] = temp;
	}

	cout << valueList[0];

	return 0;
}

void input(vector<pair<int, int>>& arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		int s, e;
		cin >> s;
		cin >> e;

		arr.push_back(make_pair(s, e));
	}

	sort(arr.begin(), arr.end());
}


#endif