#include <problem.h>

#ifdef _5021_

/// 
/// problem
/// https://www.acmicpc.net/problem/5021
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void input(map<string, double> &list, map<string, vector<string>> &dic, vector<string> &volunteers)
{
	int manCount, voluntCount;
	cin >> manCount >> voluntCount;

	string temp;
	cin >> temp;

	list[temp] = 1.0;
	dic[temp] = {temp, temp};

	for (int i = 0; i < manCount; i++)
	{
		string tempFather, tempMother;
		cin >> temp >> tempFather >> tempMother;

		if (list.find(temp) == list.end())
			list[temp] = -1.0;
		if (list.find(tempFather) == list.end())
			list[tempFather] = -1.0;
		if (list.find(tempMother) == list.end())
			list[tempMother] = -1.0;

		dic[temp] = { tempFather, tempMother };
	}

	for (int i = 0; i < voluntCount; i++)
	{
		cin >> temp;
		volunteers.push_back(temp);
	}
}

int main()
{
	map<string, double> manList;
	map<string, vector<string>> dic;
	vector<string> volunteers;

	input(manList, dic, volunteers);

	int count = 1;
	for (auto iter = manList.begin(); iter != manList.end(); iter++)
	{
		if (dic.find(iter->first) == dic.end())
		{
			iter->second = 0.0;
			count++;
		}
	}

	while (count != manList.size())
	{
		for (auto iter = dic.begin(); iter != dic.end(); iter++)
		{
			if (manList[iter->second[0]] >= 0.0 && manList[iter->second[1]] >= 0.0)
			{
				if (manList[iter->first] < 0)
				{
					manList[iter->first] = (manList[iter->second[0]] + manList[iter->second[1]]) / 2;
					count++;
				}
			}
		}
	}

	double max = -1.0;
	string answer = "";

	for (int i = 0; i < volunteers.size(); i++)
	{
		if (max < manList[volunteers[i]])
		{
			max = manList[volunteers[i]];
			answer = volunteers[i];
		}
	}

	cout << answer << endl;


	return 0;
}
#endif
