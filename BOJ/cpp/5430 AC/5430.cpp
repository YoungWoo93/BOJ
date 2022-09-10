#include <problem.h>

#ifdef _5430_

/// 50
/// problem
/// https://www.acmicpc.net/problem/5430
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

deque<int> stringToDeque(string str)
{
	deque<int> ret;
	stringstream stream(str);
	string temp;

	while (getline(stream, temp, ','))
	{
		int number;

		stringstream(temp) >> number;
		ret.push_back(number);
	}

	return ret;
}

vector<pair<string, deque<int>>> input()
{
	vector<pair<string, deque<int>>> ret;
	int count;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		pair<string, deque<int>> temp;
		cin >> temp.first;

		int arrSize;
		cin >> arrSize;

		string list;
		cin >> list;

		list.erase(list.begin());
		list.erase(list.end()-1);
		temp.second = stringToDeque(list);

		ret.push_back(temp);
	}

	return ret;
}

void process(string cmd, deque<int> dq)
{
	bool reverse = false;

	for (auto item : cmd)
	{
		if (item == 'R')
			reverse = !reverse;
		else if (item == 'D')
		{
			if (dq.empty())
			{
				cout << "error" << endl;
				return;
			}

			if (reverse)
				dq.pop_back();
			else
				dq.pop_front();
		}
	}

	string ret = "[";
	while (!dq.empty())
	{
		if (reverse)
		{
			ret += to_string(dq.back());
			dq.pop_back();
		}
		else
		{
			ret += to_string(dq.front());
			dq.pop_front();
		}

		if (!dq.empty())
			ret += ",";
	}
	ret += "]";

	cout << ret << endl;
}

int main()
{
	auto inputs = input();

	for (auto item : inputs)
		process(item.first, item.second);

	return 0;
}
#endif
