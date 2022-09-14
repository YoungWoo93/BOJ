#include <problem.h>

#ifdef _15650_

/// 
/// problem
/// https://www.acmicpc.net/problem/15650
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

void process(int maxIndex, int curIndex, int targetSize, vector<int>& curArr, vector<vector<int>>& ret)
{
	if (curArr.size() == targetSize)
	{
		ret.push_back(curArr);
		return;
	}
	if (curArr.size() + maxIndex - (curIndex - 1) < targetSize)
		return;
	
	for (int i = curIndex; i <= maxIndex; i++)
	{
		curArr.push_back(i);
		process(maxIndex, i + 1, targetSize, curArr, ret);
		curArr.pop_back();
	}

	return;

}

int main()
{
	int n, m;
	cin >> n >> m;


	vector<vector<int>> answer;
	vector<int> temp;

	process(n, 1, m, temp, answer);

	for (auto v : answer)
	{
		for (auto i : v)
			cout << i << " ";

		cout << endl;
	}
}


#endif
