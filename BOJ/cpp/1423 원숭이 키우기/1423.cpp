#include <problem.h>

#ifdef _1423_

/// 
/// problem
/// https://www.acmicpc.net/problem/1423
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;


void input(int & maxLevel, vector<long long int> &levels, vector<long long int> &powers, int &date)
{
	cin >> maxLevel;
	
	levels.assign(maxLevel, 0);
	for (int i = 0; i < levels.size(); i++)
		cin >> levels[i];
	
	powers.assign(maxLevel, 0);
	for (int i = 0; i < powers.size(); i++)
		cin >> powers[i];

	cin >> date;
}

vector<long long int> getDpTable(vector<long long int> levels, vector<long long int> powers, int date)
{
	vector<long long int> ret(date, 0);
	
	for (int startLevel = 0; startLevel < levels.size(); startLevel++)
	{
		for (int remainsCost = date; remainsCost >= 0 ; remainsCost--)
		{
			for (int endLevel = startLevel; endLevel < levels.size(); endLevel++)
			{
				int cost = endLevel - startLevel;
				for (int index = ret.size() - 1; index >= 0; index--)
				{

					if (cost + index < date)
					{
						ret[index + cost] = max(ret[index + cost], ret[index] + (powers[endLevel] - powers[startLevel]));
					}
					else
						remainsCost = 0;
				}

				if (remainsCost <= 0)
					break;
			}

			if (remainsCost <= 0)
				break;
		}
	}

	return ret;
}


int main()
{
	int maxLevel;
	vector<long long int> levels;
	vector<long long int> powers;
	int date;

	input(maxLevel, levels, powers, date);
	vector<long long int> dpTable = getDpTable(levels, powers, date);

	long long int answer = 0;
	for (int i = 0; i < maxLevel; i++)
		answer += levels[i] * powers[i];
	
	cout << answer + dpTable.back() << endl;

}

#endif

