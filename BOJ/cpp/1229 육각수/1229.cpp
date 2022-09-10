#include <problem.h>

#ifdef _1229_

/// 
/// problem
/// https://www.acmicpc.net/problem/1229
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<int> input(int &N)
{
	vector<int> hexaNumbers;
	hexaNumbers.push_back(1);
	hexaNumbers.push_back(6);
	hexaNumbers.push_back(15);

	cin >> N;

	while (hexaNumbers[hexaNumbers.size() - 1] < N)
	{
		int last = hexaNumbers[hexaNumbers.size() - 1];
		int nuwHex = (6 * hexaNumbers.size());
		int covers = (2 * (hexaNumbers.size() - 1) + 1);
		hexaNumbers.push_back(last + nuwHex - covers);
	}

	return hexaNumbers;
}

set<int> mix(vector<int>& v1, vector<int>& v2, int target)
{
	set<int> s;

	for (int v1s : v1)
	{
		for (int v2s : v2)
		{
			if (v1s + v2s == target)
				return set<int>();
			else
				s.insert(v1s + v2s);
		}
	}

	return s;
}

int main()
{
	int N;
	int answer = 0;
	auto hexas = input(N);

	if (find(hexas.begin(), hexas.end(), N) != hexas.end())
	{
		cout << 1 << endl;
		return 0;
	}

	vector<vector<int>> map;
	map.push_back(hexas);

	for (int i = 1; i < 6; i++)
	{
		set<int> s = {};
		for (int j = 0; j < (i + 1) / 2; j++)
		{
			auto output = mix(map[j], map[i - j - 1], N);

			if (output.empty())
			{
				cout << i + 1 << endl;
				return 0;
			}

			s.merge(output);
		}

		vector<int> temp(s.begin(), s.end());
		map.push_back(temp);

		s.clear();
	}

	return 0;
}
#endif
