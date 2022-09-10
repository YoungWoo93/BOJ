#include <problem.h>

#ifdef _1766_

/// 
/// problem
/// https://www.acmicpc.net/problem/1766
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>

using namespace std;

void input(vector<vector<int>>& problems)
{
	int count, lines;

	cin >> count >> lines;
	problems.assign(count + 1, vector<int>(1, 0));

	for (int i = 0; i < lines; i++)
	{
		int p, q;
		cin >> p >> q;

		problems[p].push_back(q);
		problems[q][0]++;
	}
}


void process(vector<int>& answer, vector<vector<int>>& problems)
{
	while (answer.size() != problems.size() - 1)
	{
		for (int i = 1; i < problems.size(); i++)
		{
			if (problems[i][0] == 0)
			{
				answer.push_back(i);

				for (int j = 1; j < problems[i].size(); j++)
					problems[problems[i][j]][0]--;

				problems[i][0] = -1;
				break;
			}
		}
	}
}
	
int main()
{
	vector<vector<int>> inputs;
	vector<int> answer;

	input(inputs);
	process(answer, inputs);
	
	cout << answer[0];
	for (int i = 1; i < answer.size(); i++)
		cout << " " << answer[i];
	cout << endl;
}


#endif
