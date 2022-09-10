#include <problem.h>

#ifdef _1744_

/// 
/// problem
/// https://www.acmicpc.net/problem/1744
/// 
/// solution
/// 
/// 

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;


int main()
{
	int count;
	cin >> count;
	priority_queue<int> maxpq;
	priority_queue<int, vector<int>, greater<int>> minpq;

	int temp;
	long long int answer = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> temp;
		if (temp > 1)
			maxpq.push(temp);
		else if (temp == 1)
			answer += 1;
		else
			minpq.push(temp);
	}

	

	while (maxpq.size() >= 2)
	{
		int temp1 = maxpq.top();
		maxpq.pop();
		int temp2 = maxpq.top();
		maxpq.pop();

		answer += temp1 * temp2;
	}

	if (!maxpq.empty())
		answer += maxpq.top();

	while (minpq.size() >= 2)
	{
		int temp1 = minpq.top();
		minpq.pop();
		int temp2 = minpq.top();
		minpq.pop();

		answer += temp1 * temp2;
	}

	if (!minpq.empty())
		answer += minpq.top();

	
	cout << answer << endl;

	return 0;
}
#endif
