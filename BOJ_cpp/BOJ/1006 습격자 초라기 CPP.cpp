#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _1006_
// https://www.acmicpc.net/problem/1006

#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
	bool isMarge;
	int enemyCount;
}node;

void input(int& partCount, int& memberCount, vector<node>* arr);
int getRequireTeamCount(int start, int end, int team, vector<node>* arr);

int main()
{
	int caseCount;
	vector<int> printlist;
	cin >> caseCount;

	for (int i = 0; i < caseCount; i++)
	{
		vector<node> part[2];
		int partCount, memberCount;
		input(partCount, memberCount, part);

		printlist.push_back(getRequireTeamCount(0, partCount - 1, memberCount, part));
		cout << printlist[i] << endl;
	}
	cout << endl << endl << endl;
	for (int i = 0; i < printlist.size(); i++)
	{
		cout << printlist[i] << endl;
	}


	return 0;
}

void input(int& partCount, int& memberCount, vector<node>* arr)
{
	cin >> partCount;
	cin >> memberCount;

	arr[0].resize(partCount);
	arr[1].resize(partCount);

	for (int i = 0; i < partCount; i++)
	{
		int temp;

		cin >> temp;
		
		arr[0][i].enemyCount = temp;
	}

	for (int i = 0; i < partCount; i++)
	{
		int temp;

		cin >> temp;

		arr[1][i].enemyCount = temp;
	}
}

int getRequireTeamCount(int start, int end, int team, vector<node>* arr)
{
	if (start == end)
	{
		if (arr[0].size() == 1)
		{
			if (arr[0][0].enemyCount + arr[1][0].enemyCount <= team)
				return 1;
		}
		if (((!arr[0][0].isMarge && !arr[0][arr[0].size() - 1].isMarge) && (arr[0][0].enemyCount + arr[0][arr[0].size() - 1].enemyCount <= team)) && ((!arr[1][0].isMarge && !arr[1][arr[0].size() - 1].isMarge) && (arr[1][0].enemyCount + arr[1][arr[0].size() - 1].enemyCount <= team)))
			return 0;
		if ((!arr[0][0].isMarge && !arr[0][arr[0].size() - 1].isMarge) && (arr[0][0].enemyCount + arr[0][arr[0].size() - 1].enemyCount <= team))
			return 1;
		if ((!arr[1][0].isMarge && !arr[1][arr[0].size() - 1].isMarge) && (arr[1][0].enemyCount + arr[1][arr[0].size() - 1].enemyCount <= team))
			return 1;
		
		return 2;
	}
	
	int temp0 = arr[0].size() * 2;
	int temp1 = temp0;
	int temp2 = temp0;
	int temp3 = temp0;
	int temp4 = temp0;



	if ((!arr[0][end].isMarge && !arr[1][end].isMarge) && (arr[0][end].enemyCount + arr[1][end].enemyCount <= team))
		temp0 = getRequireTeamCount(start, end - 1, team, arr) + 1;
	else
		temp0 = getRequireTeamCount(start, end - 1, team, arr) + 2;

	if ((!arr[0][end - 1].isMarge && !arr[1][end - 1].isMarge) && (arr[0][end - 1].enemyCount + arr[1][end - 1].enemyCount <= team))
	{
		arr[0][end - 1].isMarge = true;
		arr[1][end - 1].isMarge = true;

		temp1 = getRequireTeamCount(start, end - 1, team, arr) + 1;

		arr[0][end - 1].isMarge = false;
		arr[1][end - 1].isMarge = false;
	}


	if (!arr[0][end - 1].isMarge && !arr[0][end].isMarge)
	{
		if (arr[0][end - 1].enemyCount + arr[0][end].enemyCount <= team)
		{
			arr[0][end - 1].isMarge = true;
			arr[0][end].isMarge = true;

			temp2 = getRequireTeamCount(start, end - 1, team, arr) + 1;

			arr[0][end - 1].isMarge = false;
			arr[0][end].isMarge = false;
		}
	}

	if (!arr[1][end - 1].isMarge && !arr[1][end].isMarge)
	{
		if (arr[1][end - 1].enemyCount + arr[1][end].enemyCount <= team)
		{
			arr[1][end - 1].isMarge = true;
			arr[1][end].isMarge = true;

			temp3 = getRequireTeamCount(start, end - 1, team, arr) + 1;

			arr[1][end - 1].isMarge = false;
			arr[1][end].isMarge = false;
		}
	}

	if ((!arr[0][end - 1].isMarge && !arr[0][end].isMarge) && (!arr[1][end - 1].isMarge && !arr[1][end].isMarge))
	{
		if ((arr[0][end - 1].enemyCount + arr[0][end].enemyCount <= team) && (arr[1][end - 1].enemyCount + arr[1][end].enemyCount <= team))
		{
			arr[0][end - 1].isMarge = true;
			arr[0][end].isMarge = true;
			arr[1][end - 1].isMarge = true;
			arr[1][end].isMarge = true;

			temp4 = getRequireTeamCount(start, end - 1, team, arr);

			arr[1][end - 1].isMarge = false;
			arr[1][end].isMarge = false;
			arr[0][end - 1].isMarge = false;
			arr[0][end].isMarge = false;
		}
	}

	int ret = temp0;

	if (ret > temp1)
		ret = temp1;
	if (ret > temp2)
		ret = temp2;
	if (ret > temp3)
		ret = temp3;
	if (ret > temp4)
		ret = temp4;


	return ret;
}

#endif