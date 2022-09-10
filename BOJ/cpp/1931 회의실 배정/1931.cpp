#include <problem.h>

#ifdef _1931_

/// 
/// problem
/// https://www.acmicpc.net/problem/1931
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1931%EB%B2%88-%ED%9A%8C%EC%9D%98%EC%8B%A4-%EB%B0%B0%EC%A0%95
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortFunc(pair<int, int> a, pair<int, int> b)
{
	if(a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

vector<pair<int, int>> input()
{
	int cases;
	cin >> cases;

	vector<pair<int, int>> ret;
	for (int i = 0; i < cases; i++)
	{
		pair<int, int> temp;

		cin >> temp.first >> temp.second;
		ret.push_back(temp);
	}	

	sort(ret.begin(), ret.end(), sortFunc);
	return ret;
}



int main()
{
	auto lst = input();

	int curTime = -1;
	int ret = 0;
	for (auto& item : lst)
	{
		if (item.first >= curTime)
		{
			curTime = item.second;
			ret++;
		}
	}

	cout << ret;

	return 0;
}

#endif
