#include <problem.h>

#ifdef _11375_

/// 130
/// problem
/// https://www.acmicpc.net/problem/11375
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<pair<int, vector<int>>>& employeeTable, vector<int>& taskTable)
{
	int employees, tasks;
	cin >> employees >> tasks;

	employeeTable.assign(employees, { 0, vector<int>() });
	taskTable.assign(tasks, -1);

	for (int i = 0; i < employees; i++)
	{
		cin >> employeeTable[i].first;
		for (int j = 0; j < employeeTable[i].first; j++)
		{
			int task;
			cin >> task;

			employeeTable[i].second.push_back(task - 1);
		}
	}
}

bool change(vector<pair<int, vector<int>>>& employeeTable, vector<int>& taskTable, int taskNo, vector<bool> &visit)
{
	int employeeNo = taskTable[taskNo];
	if (taskTable[taskNo] == -1)
	{
		taskTable[taskNo] = employeeNo;
		return true;
	}

	if (visit[employeeNo])
		return false;

	visit[employeeNo] = true;
	
	for (int i = 0; i < employeeTable[employeeNo].second.size(); i++)
	{
		int _taskNo = employeeTable[employeeNo].second[i];

		if (taskTable[_taskNo] == -1 || change(employeeTable, taskTable, _taskNo, visit))
		{
			taskTable[_taskNo] = employeeNo;
			return true;
		}
	}

	return false;
}

int process(vector<pair<int, vector<int>>>& employeeTable, vector<int>& taskTable)
{
	int ret = 0;
	vector<bool> visit(employeeTable.size(), false);

	for (int i = 0; i < employeeTable.size(); i++)
	{
		if (employeeTable[i].second.empty())
			continue;

		for (int taskNo : employeeTable[i].second)
		{
			if (change(employeeTable, taskTable, taskNo, visit))
			{
				ret++;
				taskTable[taskNo] = i;
				break;
			}
		}
		visit.assign(employeeTable.size(), false);
	}

	return ret;
}

int main()
{
	vector<pair<int, vector<int>>> employeeTable;
	vector<int> taskTable;

	input(employeeTable, taskTable);

	cout << process(employeeTable, taskTable) << endl;

	return 0;
}
#endif
