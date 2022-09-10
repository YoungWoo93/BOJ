#include <problem.h>

#ifdef _18513_

/// 
/// problem
/// https://www.acmicpc.net/problem/18513
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define centor 150000000



bool isAble(vector<bool>& map, int spot)
{
	return map[centor + spot];
}

void setMap(vector<bool>& map, int spot, bool value)
{
	map[centor + spot] = value;
}

void input(vector<bool>& map, queue<int>& spotQ, int& spotCount)
{
	int wellCount;

	cin >> wellCount >> spotCount;

	for (int i = 0; i < wellCount; i++)
	{
		int temp;
		cin >> temp;

		setMap(map, temp, false);
		spotQ.push(temp);
	}
}

int main()
{
	vector<bool> map(centor * 2, true);
	queue<int>* spots = new queue<int>();
	queue<int>* tempQ = new queue<int>();
	int spotCount;

	unsigned long long int answer = 0;

	input(map, *spots, spotCount);

	int cost = 1;
	while (spotCount > 0)
	{
		if (spots->empty())
		{
			auto temp = spots;
			spots = tempQ;
			tempQ = temp;

			cost++;
		}

		if (isAble(map, spots->front() + 1))
		{
			setMap(map, spots->front() + 1, false);
			tempQ->push(spots->front() + 1);
			answer += cost;
			spotCount--;
		}
		
		if (isAble(map, spots->front() - 1))
		{
			setMap(map, spots->front() - 1, false);
			tempQ->push(spots->front() - 1);
			answer += cost;
			spotCount--;
		}

		spots->pop();
		
	}

	if (spotCount < 0)
		answer -= cost;

	cout << answer << endl;

	return 0;
}


#endif
