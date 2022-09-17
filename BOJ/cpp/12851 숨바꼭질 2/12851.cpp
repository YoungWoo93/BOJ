#include <problem.h>

#ifdef _12851_

/// 
/// problem
/// https://www.acmicpc.net/problem/12851
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;


bool moveAble(int n, int step, vector<unsigned int>& visit)
{
	if (n < 0 || visit.size() <= n)
		return false;
	if (visit[n] < step)
		return false;

	return true;
}

void process(int n, int k, int& step, int& count)
{
	if (n == k)
	{
		step = 0;
		count = 1;
		return;
	}
	else
	{
		step = 0;
		count = 0;
	}

	queue<int> q1;
	queue<int> q2;
	queue<int>* q = &q1;
	queue<int>* temp = &q2;

	vector<unsigned int> visits(100001, -1);

	visits[n] = step;
	q->push(n);

	while (visits[k] == -1)
	{
		while (!q->empty())
		{
			auto current = q->front();
			q->pop();
			if (moveAble(current + 1, step, visits))
			{
				visits[current + 1] = step;
				if (current + 1 == k)
					count++;

				temp->push(current + 1);
			}
			if (moveAble(current - 1, step, visits))
			{
				visits[current - 1] = step;
				if (current - 1 == k)
					count++;

				temp->push(current - 1);
			}
			if (moveAble(current * 2, step, visits))
			{
				visits[current * 2] = step;
				if (current * 2 == k)
					count++;

				temp->push(current * 2);
			}
		}

		swap(q, temp);
		step++;
	}
	
	return;
}

int main()
{
	int n, k;
	cin >> n >> k;

	int step, count;
	process(n, k, step, count);

	cout << step << endl << count << endl;
}



#endif
