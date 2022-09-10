#include <problem.h>

#ifdef _1111_

/// 
/// problem
/// https://www.acmicpc.net/problem/1111
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<int> input()
{
	int count = 0;
	cin >> count;

	vector<int> ret(count);
	for (int i = 0; i < count; i++)
		cin >> ret[i];

	return ret;
}

int main()
{
	auto inputs = input();
	string answer;

	if (inputs.size() < 3)
	{
		if (inputs.size() < 2)
			answer = "A";
		else if (inputs[0] == inputs[1])
			answer = to_string(inputs[0]);
		else
			answer = "A";

	}
	else
	{
		vector<int> d;
		vector<int> dd;

		for (int i = 0; i < inputs.size() - 1; i++)
			d.push_back(inputs[i + 1] - inputs[i]);
		for (int i = 0; i < d.size() - 1; i++)
			dd.push_back(d[i + 1] - d[i]);

		int a;
		int b;
		if (inputs[0] == inputs[1])
		{
			a = 2;
			b = -inputs[0];
		}
		else
		{
			a = dd[0] / (inputs[1] - inputs[0]) + 1;
			b = inputs[1] - (a * inputs[0]);
		}
		
		for (int i = 0; i < inputs.size() - 1; i++)
		{
			if (inputs[i] * a + b == inputs[i + 1])
				answer = to_string(inputs[i + 1] * a + b);
			else
			{
				answer = "B";
				break;
			}
		}
	}

	cout << answer << endl;

	return 0;
}
#endif
