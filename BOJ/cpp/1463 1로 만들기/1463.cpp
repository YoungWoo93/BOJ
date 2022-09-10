#include <problem.h>

#ifdef _1463_

/// 
/// problem
/// https://www.acmicpc.net/problem/1463
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1463
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
	int num;
	cin >> num;

	vector<int> lst(num*2, -1);
	lst[1] = 0;
	queue<int> q;
	
	q.push(1);

	while (lst[num] == -1)
	{
		auto temp = q.front();

		if (temp + 1 <= num && lst[temp + 1] == -1)
		{
			q.push(temp + 1);
			lst[temp + 1] = lst[temp] + 1;
		}
		if (temp * 2 <= num && lst[temp * 2] == -1)
		{
			q.push(temp * 2);
			lst[temp * 2] = lst[temp] + 1;
		}
		if (temp * 3 <= num && lst[temp * 3] == -1)
		{
			q.push(temp * 3);
			lst[temp *3] = lst[temp] + 1;
		}

		q.pop();
	}

	cout << lst[num];

	return 0;
}

#endif
