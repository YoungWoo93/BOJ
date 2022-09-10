#include <problem.h>

#ifdef _1786_

/// 150
/// problem
/// https://www.acmicpc.net/problem/1786
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> input()
{
	string temp;
	vector<string> ret;

	getline(cin, temp);
	ret.push_back(temp);
	getline(cin, temp);
	ret.push_back(temp);

	return ret;
}

vector<int> preprocessing(string pattern)
{
	vector<int> ret(pattern.length(), 0);
	int cur = 0;
	
	for (int i = 1; i < pattern.length(); i++)
	{
		if (pattern.c_str()[cur] != pattern.c_str()[i])
		{
			if (cur != 0)
			{
				cur = ret[cur - 1];
				i--;
				continue;
			}
		}
		else
			cur++;

		ret[i] = cur;
	}

	//
	//	포인트는 cur가 같이 따라가다가 틀린 문자가 나왔을때, ret 배열의 cur 값 -1 번 인덱스는 틀린문자 직전에서 다시 시작할 수 있는 최대거리 라는점이다
	//
	return ret;
}

vector<int> matching(string str, string pattern, vector<int>& preprocessTable)
{
	vector<int> ret;
	int count = 0;
	int offset = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str.c_str()[i] == pattern.c_str()[offset])
		{
			offset++;
			if (offset == pattern.length())
			{
				count++;
				ret.push_back(i - offset + 1);
				offset = *(preprocessTable.end()-1);
			}
		}
		else if (offset != 0)
		{
			i--;
			offset = preprocessTable[offset - 1];
		}

	}

	ret.insert(ret.begin(), count);
	return ret;
}

int main()
{
	auto strs = input();
	auto pre = preprocessing(strs[1]);
	auto result = matching(strs[0], strs[1], pre);

	cout << result[0] << endl;

	if (result.size() > 1)
		cout << result[1] + 1;
	for (int i = 2; i < result.size(); i++)
	{
		cout << " " << result[i] + 1;
	}

	return 0;
}
#endif
