#include <problem.h>

#ifdef _2623_

/// 
/// problem
/// https://www.acmicpc.net/problem/2623
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	map<int, bool> preced;
	map<int, bool> trailed;
};

vector<node> input()
{
	int singers, pds;
	cin >> singers >> pds;

	vector<node> ret(singers);
	
	for (int i = 0; i < pds; i++)
	{
		int count, pre, trail;
		cin >> count;

		cin >> pre;
		for (int j = 1; j < count; j++)
		{
			cin >> trail;
			ret[pre - 1].trailed[trail - 1] = true;
			ret[trail - 1].preced[pre - 1] = true;
			pre = trail;
		}
	}

	return ret;
}

int main()
{
	auto inputs = input();
	queue<int> q;
	queue<int> answer;
	for (int i = 0; i < inputs.size(); i++)
	{
		if (inputs[i].preced.empty())
			q.push(i);
	}

	while (answer.size() < inputs.size())
	{
		if (q.empty())
		{
			cout << 0 << endl;
			return 0;
		}

		answer.push(q.front() + 1);

		for (auto item : inputs[q.front()].trailed) 
		{
			inputs[item.first].preced.erase(q.front());
			
			if (inputs[item.first].preced.empty())
				q.push(item.first);
		}
		q.pop();

		
	}
	
	while (!answer.empty())
	{
		cout << answer.front() << endl;
		answer.pop();
	}

	return 0;
}
#endif
