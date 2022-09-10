#include <problem.h>

#ifdef _9935_

/// 
/// problem
/// https://www.acmicpc.net/problem/9935
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> input()
{
	vector<string> ret(2);

	cin >> ret[0];
	cin >> ret[1];

	return ret;
}

void boom(string& mainString, string boomString)
{
	if (mainString.length() < boomString.length())
		return;

	for (int i = 0; i < boomString.length(); i++)
	{
		if (*(mainString.rbegin() + i) != *(boomString.rbegin() + i))
			return;
	}

	for (int i = 0; i < boomString.length(); i++)
		mainString.pop_back();

	return;
}

int main()
{
	auto inputs = input();
	string mainString;

	for (int i = 0; i < inputs[0].length(); i++)
	{
		mainString.push_back(inputs[0].at(i));

		if (mainString.back() == inputs[1].back())
			boom(mainString, inputs[1]);
	}

	if (mainString.empty())
		cout << "FRULA" << endl;
	else
		cout << mainString << endl;

	return 0;
}
#endif
