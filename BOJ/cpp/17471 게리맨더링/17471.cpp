#include <problem.h>

#ifdef _17471_

/// 
/// problem
/// https://www.acmicpc.net/problem/17471
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct node {
	int population;
	vector<int> link;

	int force;
};

vector<node> input()
{
	int count = 0;
	cin >> count;

	vector<node> ret(count);

	for (int i = 0; i < count; i++)
	{
		cin >> ret[i].population;
		ret[i].force = 0;
	}

	for (int i = 0; i < count; i++)
	{
		int links = 0;
		cin >> links;

		for (int j = 0; j < links; j++)
		{
			int temp = 0;
			cin >> temp;

			ret[i].link.push_back(temp - 1);
		}
	}

	return ret;
}

int check(vector<node> state)
{
	int start = -1;
	for (int i = 0; i < state.size(); i++)
	{
		if (state[i].force == 0)
		{
			start = i;
			break;
		}
	}

	if (start != -1)
	{
		queue<int> q;

		state[start].force = 2;
		q.push(start);
		while (!q.empty())
		{
			for (int i = 0; i < state[q.front()].link.size(); i++)
			{
				if (state[state[q.front()].link[i]].force == 0)
				{
					state[state[q.front()].link[i]].force = 2;
					q.push(state[q.front()].link[i]);
				}
			}
			q.pop();
		}
	}

	for (int i = 0; i < state.size(); i++)
	{
		if (state[i].force == 1)
		{
			start = i;
			break;
		}
	}

	if (start != -1)
	{
		queue<int> q;

		state[start].force = 3;
		q.push(start);
		while (!q.empty())
		{
			for (int i = 0; i < state[q.front()].link.size(); i++)
			{
				if (state[state[q.front()].link[i]].force == 1)
				{
					state[state[q.front()].link[i]].force = 3;
					q.push(state[q.front()].link[i]);
				}
			}
			q.pop();
		}
	}

	int aForce = 0;
	int bForce = 0;

	for (int i = 0; i < state.size(); i++)
	{
		if (state[i].force == 0 || state[i].force == 1)
			return -1;

		if (state[i].force == 2)
			aForce += state[i].population;
		else
			bForce += state[i].population;
	}

	return abs(aForce - bForce);
}



bool next_combination(vector<int>& v, int n) {
	const int k = v.size();
	int i = k - 1;
	int max_n = n;
	while (i >= 0 && v[i] >= max_n) { // First stage: search `i` where we could increase the suffix of `v`.
		i--;
		max_n--;
	}

	if (i < 0)
		return false;

	for (v[i++]++; i < k; i++) // Second stage: increase the suffix of `v`.
		v[i] = v[i - 1] + 1;

	return true;
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ans;

	vector<int> v(k);
	for (int i = 0; i < k; i++)
		v[i] = i + 1;

	do {
		ans.push_back(v);
	} while (next_combination(v, n));

	return ans;
}

int precess(vector<node> state, vector<int> combination)
{
	for (int i = 0; i < combination.size(); i++)
	{
		state[combination[i] - 1].force = 1;
	}

	return check(state);
}

int main()
{
	auto inputs = input();
	int answer = -1;

	for (int i = 0; i < (inputs.size() / 2) + 1; i++)
	{
		auto comb = combine(inputs.size(), i);

		for (int j = 0; j < comb.size(); j++)
		{
			auto ret = precess(inputs, comb[j]);

			if (answer == -1)
				answer = ret;
			else if (ret != -1)
				answer = min(answer, ret);
		}
	}

	cout << answer << endl;

	return 0;
}


#endif
