#include <problem.h>

#ifdef _1715_

/// 
/// problem
/// https://www.acmicpc.net/problem/1715
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1715%EB%B2%88-%EC%B9%B4%EB%93%9C-%EC%A0%95%EB%A0%AC%ED%95%98%EA%B8%B0
/// 

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

multiset<int> input()
{
	int cases;
	cin >> cases;

	multiset<int> ret;
	for (int i = 0; i < cases; i++)
	{
		int temp;

		cin >> temp;
		ret.insert(temp);
	}

	return ret;
}

int main()
{
	auto s = input();
	int ret = 0;
	while (s.size() > 1)
	{
		int temp = *s.begin();
		s.erase(s.find(*s.begin()));
		temp += *s.begin();
		s.erase(s.find(*s.begin()));

		ret += temp;
		s.insert(temp);
	}


	cout << ret;

	return 0;
}

#endif
