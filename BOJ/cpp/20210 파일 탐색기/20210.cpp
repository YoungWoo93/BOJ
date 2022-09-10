#include <problem.h>

#ifdef _20210_

/// 
/// problem
/// https://www.acmicpc.net/problem/20210
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


vector<string> input()
{
	int count;
	cin >> count;

	vector<string> ret(count);
	for (int i = 0; i < count; i++)
		cin >> ret[i];

	return ret;
}

vector<string> wordToBlock(string str)
{
	vector<string> ret;

	bool flag = isdigit(str[0]);
	string temp = "";
	temp += str[0];

	for (int i = 1; i < str.length(); i++)
	{
		bool tempb = isdigit(str[i]);
		if (tempb != flag)
		{
			flag = isdigit(str[i]);
			ret.push_back(temp);
			temp = "";
		}
		else if (!flag)
		{
			ret.push_back(temp);
			temp = "";
		}

		temp += str[i];
	}

	ret.push_back(temp);

	return ret;
}

vector<vector<string>> inputToBlocks(vector<string> inputs)
{
	vector<vector<string>> ret(inputs.size());

	for (int i = 0; i < inputs.size(); i++)
		ret[i] = wordToBlock(inputs[i]);
	
	return ret;
}

int cmpStrs(string a, string b)
{
	if (toupper(a[0]) < toupper(b[0]))
		return 1;
	else if (toupper(a[0]) > toupper(b[0]))
		return -1;
	else
	{
		if (-a[0] < -b[0])
			return -1;
		else if (-a[0] > -b[0])
			return 1;
		else
			return 0;
	}
}

int cmpInts(string inta, string intb)
{
	int aPos = 0;
	int bPos = 0;

	for (aPos = 0; aPos < inta.length(); aPos++)
	{
		if (inta[aPos] != '0')
			break;
	}

	for (bPos = 0; bPos < intb.length(); bPos++)
	{
		if (intb[bPos] != '0')
			break;
	}

	if (inta.length() - aPos != intb.length() - bPos)
	{
		if (inta.length() - aPos < intb.length() - bPos)
			return 1;
		else
			return -1;
	}
	else
	{
		int len = inta.length() - aPos;

		for (int i = 0; i < len; i++)
		{
			if (inta[aPos + i] < intb[bPos + i])
				return 1;
			else if (inta[aPos + i] > intb[bPos + i])
				return -1;
		}
	}

	if (inta.length() < intb.length())
		return 1;
	else if (inta.length() > intb.length())
		return -1;
	else
		return 0;
}

int cmpBlocks(string a, string b)
{
	if (isdigit(a[0]) != isdigit(b[0]))
	{
		if (isdigit(a[0]))
			return 1;

		return -1;
	}

	if (isdigit(a[0]))
		return cmpInts(a, b);

	else
		return cmpStrs(a, b);
}

bool sortRule(vector<string> a, vector<string> b)
{

	//cout << "cmp a: " << a[0] << a[1] << a[2] << endl;
	//cout << "cmp b: " << b[0] << b[1] << b[2] << endl;
	int len;

	if (a.size() < b.size())
		len = a.size();
	else
		len = b.size();

	for (int i = 0; i < len; i++)
	{
		int ret = cmpBlocks(a[i], b[i]);

		if (ret == 1)
			return true;
		else if (ret == -1)
			return false;
	}

	return a.size() < b.size();
}

int main()
{
	vector<string> inputs = input();

	vector<vector<string>> blocks = inputToBlocks(inputs);

	sort(blocks.begin(), blocks.end(), sortRule);

	for (int i = 0; i < blocks.size(); i++)
	{
		string answer = "";
		for (int j = 0; j < blocks[i].size(); j++)
			answer += blocks[i][j];
		
		cout << answer << endl;
	}

	return 0;
}
#endif
