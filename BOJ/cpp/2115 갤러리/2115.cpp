#include <problem.h>

#ifdef _2115_

/// 
/// problem
/// https://www.acmicpc.net/problem/2115
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

vector<vector<bool>> input()
{
	int w, h;
	cin >> h >> w;
	
	vector<vector<bool>> ret(h, vector<bool>(w, true));

	for (int i = 0; i < h; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < w; j++)
		{
			if (temp.c_str()[j] == 'X')
				ret[i][j] = false;
		}
	}

	return ret;
}

vector<int> scan(vector<vector<bool>>& map)
{
	vector<int> ret;

	for (int i = 0; i < map.size() - 1; i++)
	{
		int count1 = 0;
		int count2 = 0;
		for (int j = 0; j < map[0].size(); j++)
		{
			if (map[i][j] && !map[i+1][j])
				count1++;
			else
			{
				if (count1 / 2 >= 1)
					ret.push_back(count1 / 2);
				count1 = 0;
			}

			if (!map[i][j] && map[i+1][j])
				count2++;
			else
			{
				if (count2 / 2 >= 1)
					ret.push_back(count2 / 2);
				count2 = 0;
			}
		}
		if (count1 / 2 >= 1)
			ret.push_back(count1 / 2);
		if (count2 / 2 >= 1)
			ret.push_back(count2 / 2);
	}

	for (int j = 0; j < map[0].size() - 1; j++)
	{
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < map.size(); i++)
		{
			if (map[i][j] && !map[i][j+1])
				count1++;
			else
			{
				if(count1 / 2 >= 1)
					ret.push_back(count1 / 2);
				count1 = 0;
			}

			if (!map[i][j] && map[i][j + 1])
				count2++;
			else
			{
				if (count2 / 2 >= 1)
					ret.push_back(count2 / 2);
				count2 = 0;
			}
		}
		if (count1 / 2 >= 1)
			ret.push_back(count1 / 2);
		if (count2 / 2 >= 1)
			ret.push_back(count2 / 2);
	}

	return ret;
}

int main()
{
	auto inputs = input();
	auto scans = scan(inputs);

	int answer = 0;
	for (int i = 0; i < scans.size(); i++)
		answer += scans[i];

	cout << answer << endl;
	return 0;

}


#endif
