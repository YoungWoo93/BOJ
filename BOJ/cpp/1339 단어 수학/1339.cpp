#include <problem.h>

#ifdef _1339_

/// 
/// problem
/// https://www.acmicpc.net/problem/1339
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1339-%EB%8B%A8%EC%96%B4-%EC%88%98%ED%95%99
/// 

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>


using namespace std;

vector<vector<int>>input()
{
	vector<vector<int>> ret(8, vector<int>('Z' - 'A' + 1, 0));
	int words;
	string temp;
	cin >> words;

	for (int i = 0; i < words; i++)
	{
		cin >> temp;
		for (int i = 0; i < temp.length(); i++)
		{
			ret[i][temp[temp.length() - i - 1] - 'A']++;
		}
	}

	return ret;
}


int main()
{
	auto wordList = input();
	vector<unsigned long long int> weightList('Z' - 'A' + 1, 0);

	for (int i = 0; i < wordList.size(); i++)
	{
		for (int j=0; j<wordList[i].size(); j++)
		{
			weightList[j] += pow(10, i) * wordList[i][j];
		}
	}

	priority_queue<unsigned long long int> pq;

	for (auto item : weightList)
		pq.push(item);

	int offset = 9;
	unsigned long long int result = 0;
	while (!pq.empty())
	{
		result += offset * pq.top();
		offset--;
		pq.pop();
	}

	cout << result << endl;

	return 0;
}
#endif
