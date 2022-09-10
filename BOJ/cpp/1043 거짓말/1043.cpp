#include <problem.h>

#ifdef _1043_

/// 
/// problem
/// https://www.acmicpc.net/problem/1043
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
	bool truth;
	vector<int> link;

	node(){
		truth = false;
	}
};

void linking(vector<int>& info, vector<node>& manList)
{
	for (int i = 0; i < info.size(); i++)
	{
		for (int j = i + 1; j < info.size(); j++)
		{
			manList[info[i]].link.push_back(info[j]);
			manList[info[j]].link.push_back(info[i]);
		}
	}
}

void travel(int startIndex, vector<node>& manList)
{
	queue<int> q;
	manList[startIndex].truth = true;
	q.push(startIndex);

	while (!q.empty())
	{
		auto index = q.front();
		q.pop();
		
		for (int i = 0; i < manList[index].link.size(); i++)
		{
			if (manList[manList[index].link[i]].truth)
				continue;

			manList[manList[index].link[i]].truth = true;
			q.push(manList[index].link[i]);
		}
	}
}

vector<vector<int>> input()
{
	int mans, partys;
	cin >> mans >> partys;
	vector<node> manList(mans + 1, node());
	vector<vector<int>> ret(partys + 1, vector<int>());

	for (int i = 0; i < partys + 1; i++)
	{
		cin >> mans;
		for (int j = 0; j < mans; j++)
		{
			int temp;
			cin >> temp;

			ret[i].push_back(temp);
		}
		sort(ret[i].begin(), ret[i].end());
		linking(ret[i], manList);
	}

	for (int i = 1; i < manList.size(); i++)
	{
		sort(manList[i].link.begin(), manList[i].link.end());
		manList[i].link.erase(unique(manList[i].link.begin(), manList[i].link.end()), manList[i].link.end());
	}

	if(ret[0].empty())
		return ret;

	manList[ret[0][0]].truth = true;
	travel(ret[0][0], manList);

	ret[0].clear();
	for (int i = 1; i < manList.size(); i++)
	{
		if (manList[i].truth)
			ret[0].push_back(i);
	}

	return ret;
}

bool check(vector<int>& arr1, vector<int>& arr2)
{
	vector<int>::iterator iter1 = arr1.begin();
	vector<int>::iterator iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end())
	{
		if (*iter1 == *iter2)
			return true;

		if (*iter1 > *iter2)
			iter2++;
		else
			iter1++;
	}

	return false;
}

int main()
{
	auto inputs = input();
	vector<int> checkList = inputs[0];
	for (int i = 1; i < inputs.size(); i++)
	{
		if (check(inputs[0], inputs[i]))
			checkList.insert(checkList.end(), inputs[i].begin(), inputs[i].end());
		
	}

	sort(checkList.begin(), checkList.end());
	checkList.erase(unique(checkList.begin(), checkList.end()), checkList.end());

	int answer = 0;
	for (int i = 1; i < inputs.size(); i++)
	{
		if (check(checkList, inputs[i]))
			continue;

		answer++;
	}

	cout << answer << endl;


	return 0;
}
#endif
