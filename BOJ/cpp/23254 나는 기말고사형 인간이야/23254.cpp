#include <problem.h>

#ifdef _23254_

/// 
/// problem
/// https://www.acmicpc.net/problem/23254
/// 
/// solution
/// 
/// 

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;


void input(vector<int>& defaultScore, vector<int>& increase, int &days)
{
	int lectureCount;
	cin >> days >> lectureCount;

	defaultScore.assign(lectureCount, 0);
	increase.assign(lectureCount, 0);

	for (int i = 0; i < lectureCount; i++)
		cin >> defaultScore[i];

	for (int i = 0; i < lectureCount; i++)
		cin >> increase[i];

}

int getScore(vector<int>& scores)
{
	int ret = 0;
	for (int i = 0; i < scores.size(); i++)
		ret += scores[i];

	return ret;
}

int main()
{
	vector<int> score;
	vector<int> increase;
	int days;

	input(score, increase, days);

	int count = 24 * days;
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < score.size(); i++)
		pq.push(pair<int, int>(min(increase[i], 100 - score[i]), i));
	

	for (int i = 0; i < count; i++)
	{
		pair<int, int> temp = pq.top();
		pq.pop();

		score[temp.second] += temp.first;
		pq.push(pair<int, int>(min(temp.first, 100 - score[temp.second]), temp.second));
	}

	cout << getScore(score) << endl;


	return 0;
}
#endif
