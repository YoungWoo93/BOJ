#include <problem.h>

#ifdef _11391_

/// 45
/// problem
/// https://www.acmicpc.net/problem/11391
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> pow2;
void preprocess()
{
	for (int i = 0; i < 17; i++)
		pow2.push_back(1 << i);
}

int get1BitCount(int inputNumber)
{
	int ret = 0;

	for (auto it = pow2.rbegin(); it != pow2.rend(); it++)
	{
		if (inputNumber >= *it)
		{
			inputNumber -= *it;
			ret++;
		}
	}

	return ret;
}

void input(vector<vector<int>>& numbers, vector<vector<int>>& result)
{
	int numberSize, boxSize;
	cin >> numberSize >> boxSize;

	result.assign(1 << boxSize, vector<int>());
	numbers.assign(17, vector<int>());
	
	preprocess();
	for (int i = 0; i < (1 << numberSize); i++)
	{
		int temp = get1BitCount(i);
		numbers[temp].push_back(i);
	}
}

void process(vector<vector<int>>& numbers, vector<vector<int>>& result)
{
	bool dir = true;
	int index = 0;
	for (auto& numberVector : numbers)
	{
		while (!numberVector.empty())
		{
			result[index].push_back(numberVector.back());
			if (dir)
			{
				index++;
				if (index >= result.size())
				{
					dir = !dir;
					index--;
				}
					
			}
			else
			{
				index--;
				if (index < 0)
				{
					dir = !dir;
					index++;
				}
					
			}
			numberVector.pop_back();
		}
	}
}

int main()
{
	vector<vector<int>> numbers;
	vector<vector<int>> result;

	input(numbers, result);

	process(numbers, result);

	for (int i = 0; i < result.size(); i++)
		sort(result[i].begin(), result[i].end());
	
	sort(result.begin(), result.end(), [](vector<int> a, vector<int> b) {return a.front() < b.front(); });

	for (int i = 0; i < result.size(); i++)
	{
		for (auto item : result[i])
			cout << item << " ";
		cout << endl;
	}

}
#endif

