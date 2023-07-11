#include <problem.h>

#ifdef _15657_

/// 
/// problem
/// https://www.acmicpc.net/problem/15657
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int input(vector<int>& numbers)
{
	int M, N;

	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;

		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());

	return N;
}

void process(vector<vector<int>>& answer, vector<int>& numbers, int index, int count, vector<int> currentAnswer)
{
	if (index >= numbers.size())
		return;

	if (count == 0)
	{
		answer.push_back(currentAnswer);
		return;
	}

	for (int i = index; i < numbers.size(); i++)
	{
		currentAnswer.push_back(numbers[i]);
		process(answer, numbers, i, count - 1, currentAnswer);
		currentAnswer.pop_back();
	}

	return;
}

int main()
{
	vector<int> numbers;
	vector<vector<int>> answers;
	int n = input(numbers);

	vector<int> temp;
	process(answers, numbers, 0, n, temp);

	for (auto answer : answers)
	{
		for (auto number : answer)
		{
			cout << number << " ";
		}
		cout << endl;
	}
}


#endif
