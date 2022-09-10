#include <problem.h>

#ifdef _6137_

/// 
/// problem
/// https://www.acmicpc.net/problem/6137
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;


vector<char> input()
{
	int count;
	cin >> count;

	vector<char> ret(count);

	for (int i = 0; i < count; i++)
		cin >> ret[i];

	return ret;
}

void printAnswer(string answer)
{
	if (answer.empty())
	{
		cout << "";
		return;
	}

	cout << answer.c_str()[0];
	for (int i = 1; i < answer.length(); i++)
	{
		cout << answer.c_str()[i];

		if (i % 80 == 79)
			cout << endl;
	}
}


int main()
{
	vector<char> stringS = input();
	string answer = "";
	int front = 0;
	int end = stringS.size() - 1;
	while (front < end)
	{
		if (stringS[front] < stringS[end])
		{
			answer += stringS[front];
			front++;
		}
		else if (stringS[front] > stringS[end])
		{
			answer += stringS[end];
			end--;
		}
		else
		{
			int frontCur = front;
			int endCur = end;
			int offset;
			for (offset = 1; frontCur + offset < endCur - offset; offset++)
			{
				if (stringS[frontCur + offset] != stringS[endCur - offset])
				{
					if (stringS[frontCur + offset] < stringS[endCur - offset])
					{
						answer += stringS[front];
						front++;
					}
					else
					{
						answer += stringS[end];
						end--;
					}
					break;
				}
			}

			if (frontCur + offset >= endCur - offset)
			{
				answer += stringS[front];
				front++;
			}
		}
	}
	if(front == end)
		answer += stringS[front];



	printAnswer(answer);

	return 0;
}
#endif

