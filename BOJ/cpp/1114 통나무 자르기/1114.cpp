#include <problem.h>

#ifdef _1114_

/// 
/// problem
/// https://www.acmicpc.net/problem/1114
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


vector<int> input(int &count)
{
	int length;
	int points;
	
	cin >> length >> points >> count;

	vector<int> ret;

	ret.push_back(0);
	for (int i = 0; i < points; i++)
	{
		int temp;
		cin >> temp;

		ret.push_back(temp);
	}
	ret.push_back(length);
	sort(ret.begin(), ret.end());

	return ret;
}

bool cutting(vector<int>& cutPoints,int destance, int cutCount)
{
	int cuts = 0;
	int cur = 0;
	int max = 0;
	for (int i = 1; i < cutPoints.size(); i++)
	{
		if (cuts > cutCount)
			return false;

		if (cutPoints[i] - cutPoints[cur] > destance)
		{
			cuts++;
			cur = i - 1;
			i--;
		}
	}

	return true;
}


int main()
{
	int cutCount;
	auto cutPoints = input(cutCount);


	int start = cutPoints.back();
	for (int i = 1; i < cutPoints.size() - 1; i++)
	{
		if (cutPoints[i] - cutPoints[i - 1] < start)
			start = cutPoints[i] - cutPoints[i - 1];
	}
	int end = cutPoints.back();
	int destance = (start + end) / 2;
	


	int answer = 0;
	while (start < end)
	{
		if (cutting(cutPoints, destance, cutCount))
		{
			end = destance;
			destance = (start + end) / 2;
		}
		else
		{
			start = destance + 1;
			destance = (start + end) / 2;
		}

	}
	answer = end;

	



	int answerPoint = 0;
	int cur = cutPoints.size() - 1;
	int cnt = 0;
	for (int i = cutPoints.size() - 2; i >= 0; i--)
	{
		if (cutPoints[cur] - cutPoints[i] > answer)
		{
			cnt++;
			answerPoint = cutPoints[i + 1];
			cur = i + 1;
			i++;
		}
	}
	if (cnt < cutCount)
		answerPoint = cutPoints[1];

	cout << answer << " " << answerPoint << endl;


	return 0;
}
#endif
