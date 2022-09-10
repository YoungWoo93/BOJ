#include <problem.h>

#ifdef _2565_

/// 170
/// problem
/// https://www.acmicpc.net/problem/2565
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, int>> input()
{
	int count;
	cin >> count;

	vector<pair<int, int>> ret;
	for (int i = 0; i < count; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;

		ret.push_back(temp);
	}

	return ret;
}

vector<int> preprocessing(vector<pair<int, int>> &inputs)
{
	vector<int> ret;
	int retSize = 0;
	sort(inputs.begin(), inputs.end());

	for (int i = 0; i < inputs.size(); i++)
		retSize = retSize > inputs[i].second ? retSize : inputs[i].second;
	
	ret.assign(retSize + 1, -1);
	for (int i = 0; i < inputs.size(); i++)
		ret[inputs[i].second] = i;

	return ret;
}

int LIS(vector<int>& arr)
{
	if (arr.empty())
		return 0;
	
	vector<int> ret(arr.size(), 0);
	vector<int> memo;

	for (int i = 0; i < arr.size(); i++)
	{
		auto lowerIter = lower_bound(memo.begin(), memo.end(), arr[i]);

		if (lowerIter == memo.end())
		{
			memo.push_back(arr[i]);
			ret[i] = memo.end() - memo.begin() - 1;
		}
		else
		{ 
			*lowerIter = arr[i];
			ret[i] = lowerIter - memo.begin();
		}

	}

	return (*max_element(ret.begin(), ret.end()));
}

int main()
{
	auto inputs = input();
	auto preprocess = preprocessing(inputs);
	cout << inputs.size() - LIS(preprocess) << endl;

	return 0;
}
#endif
