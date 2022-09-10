#include <problem.h>

#ifdef _9252_

/// 7
/// problem
/// https://www.acmicpc.net/problem/9252
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int main()
{
	string str1;
	string str2;

	cin >> str1 >> str2;

	vector<vector<int>> map(str1.length(), vector<int>(str2.length(), 0));

	int max = 0;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == str2[0])
			max = 1;
		map[i][0] = max;
	}

	//max = 0;
	//for (int i = 0; i < str2.length(); i++)
	//{
	//	if (str2[i] == str1[0])
	//		max = 1;
	//	map[0][i] = max;
	//}

	bool find = false;
	int value = 0;
	for (int i = 1; i < map.size(); i++)
	{
		value = map[i][0];
		for (int j = 1; j < map[0].size(); j++)
		{
			if (str1[i] == str2[j] && !find)
			{
				find = true;
				value++;
			}

			map[i][j] = value;
		}
		find = false;
	}


	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "??";
}
#endif
