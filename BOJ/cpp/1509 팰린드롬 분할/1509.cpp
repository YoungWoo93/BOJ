#include <problem.h>

#ifdef _1509_

/// 
/// problem
/// https://www.acmicpc.net/problem/1509
/// 
/// solution
/// 
/// 



#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

void makePalindromeTable(vector<vector<int>>& palindromeTable, string& str)
{
	for (int i = palindromeTable.size() - 2; i > 0; i--)
	{
		for (int j = 0; j < palindromeTable[i].size(); j++)
		{
			if (str[i - 1] == str[palindromeTable[i][j] + 1])
				palindromeTable[i - 1].push_back(palindromeTable[i][j] + 1);
		}
	}
}

int getDPTable(vector<vector<int>>& palindromeTable, vector<int>& dpTable, int index, int current)
{
	if (index >= dpTable.size())
		return 0;

	if (dpTable[index] != -1)
		return dpTable[index];

	int ret = INT_MAX;
	for (int i = 0; i < palindromeTable[index].size(); i++)
	{
		ret = min(ret, getDPTable(palindromeTable, dpTable, palindromeTable[index][i] + 1, current + 1) + 1);
	}
	dpTable[index] = ret;

	return ret;
}

int main()
{
	string str;
	cin >> str;

	vector<vector<int>> palindromeTable(str.length(), vector<int>());
	vector<int> dpTable(str.length(), -1);
	for (int i = 0; i < str.length() - 1; i++)
	{
		palindromeTable[i].push_back(i);
		if (str[i] == str[i + 1])
			palindromeTable[i].push_back(i + 1);
	}
	palindromeTable[str.length() - 1].push_back(str.length() - 1);

	makePalindromeTable(palindromeTable, str);

	getDPTable(palindromeTable, dpTable, 0, 0);
	cout << dpTable[0] << endl;

	return 0;
}



#endif
