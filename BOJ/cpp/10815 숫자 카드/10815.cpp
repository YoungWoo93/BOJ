#include <problem.h>

#ifdef _10815_

/// 7
/// problem
/// https://www.acmicpc.net/problem/10815
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>, vector<int>> input()
{
	int count;
	pair< vector<int> , vector<int> > ret;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;

		ret.first.push_back(temp);
	}

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;

		ret.second.push_back(temp);
	}

	return ret;
}

int main()
{
	auto arr = input();
	sort(arr.first.begin(), arr.first.end());

	if (binary_search(arr.first.begin(), arr.first.end(), arr.second[0]))
		cout << 1;
	else
		cout << 0;
	for (int i=1; i<arr.second.size(); i++)
	{
		if (binary_search(arr.first.begin(), arr.first.end(), arr.second[i]))
			cout << " " << 1;
		else
			cout << " " << 0;
	}
	cout << endl;

	return 0;
}
#endif
