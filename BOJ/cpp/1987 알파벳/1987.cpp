#include <problem.h>

#ifdef _1987_

/// 
/// problem
/// https://www.acmicpc.net/problem/1987
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>

using namespace std;




vector<vector<char>> input()
{
	int width, height;

	cin >> height >> width;
	vector<vector<char>> ret(height, vector<char>());

	string temp;

	for (int i = 0; i < height; i++)
	{
		cin >> temp;
		ret[i].assign(temp.begin(), temp.end());
	}

	return ret;
}

bool moveAbleCheck(vector<vector<char>>& map, int x, int y, vector<bool>& charCheck)
{
	if (x < 0)
		return false;

	if (x >= map[0].size())
		return false;

	if (y < 0)
		return false;

	if (y >= map.size())
		return false;

	if (charCheck[map[y][x] - 'A'] == true)
		return false;

	return true;
}
int callcount = 0;

int travel(vector<vector<char>>& map, int xpos, int ypos, vector<bool> charCheck)
{
	int ret = 0;
	vector<bool> copyCharCheck = charCheck;
	if (moveAbleCheck(map, xpos - 1, ypos, charCheck))
	{
		copyCharCheck[map[ypos][xpos - 1] - 'A'] = true;
		int temp = travel(map, xpos - 1, ypos, copyCharCheck);
		copyCharCheck[map[ypos][xpos - 1] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck(map, xpos + 1, ypos, charCheck))
	{
		copyCharCheck[map[ypos][xpos+ 1] - 'A'] = true;
		int temp = travel(map, xpos + 1, ypos, copyCharCheck);
		copyCharCheck[map[ypos][xpos + 1] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck(map, xpos, ypos - 1, charCheck))
	{
		copyCharCheck[map[ypos - 1][xpos] - 'A'] = true;
		int temp = travel(map, xpos, ypos - 1, copyCharCheck);
		copyCharCheck[map[ypos - 1][xpos] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck(map, xpos, ypos + 1, charCheck))
	{
		copyCharCheck[map[ypos + 1][xpos] - 'A'] = true;
		int temp = travel(map, xpos, ypos + 1, copyCharCheck);
		copyCharCheck[map[ypos + 1][xpos] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}

	return ret;
}

int travel2(vector<vector<char>>& map, int xpos, int ypos, vector<bool> charCheck, int count)
{
	int ret = 0;
	vector<bool> copyCharCheck = charCheck;
	if (moveAbleCheck(map, xpos - 1, ypos, charCheck))
	{
		for (int i = 0; i < count; i++)
			cout << " ";
		cout << map[ypos][xpos - 1] << endl;

		copyCharCheck[map[ypos][xpos - 1] - 'A'] = true;
		int temp = travel2(map, xpos - 1, ypos, copyCharCheck, count+1);
		copyCharCheck[map[ypos][xpos - 1] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck(map, xpos + 1, ypos, charCheck))
	{
		for (int i = 0; i < count; i++)
			cout << " ";
		cout << map[ypos][xpos + 1] << endl;

		copyCharCheck[map[ypos][xpos + 1] - 'A'] = true;
		int temp = travel2(map, xpos + 1, ypos, copyCharCheck, count + 1);
		copyCharCheck[map[ypos][xpos + 1] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck(map, xpos, ypos - 1, charCheck))
	{
		for (int i = 0; i < count; i++)
			cout << " ";
		cout << map[ypos - 1][xpos] << endl;

		copyCharCheck[map[ypos - 1][xpos] - 'A'] = true;
		int temp = travel2(map, xpos, ypos - 1, copyCharCheck, count + 1);
		copyCharCheck[map[ypos - 1][xpos] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck(map, xpos, ypos + 1, charCheck))
	{
		for (int i = 0; i < count; i++)
			cout << " ";
		cout << map[ypos + 1][xpos] << endl;

		copyCharCheck[map[ypos + 1][xpos] - 'A'] = true;
		int temp = travel2(map, xpos, ypos + 1, copyCharCheck, count + 1);
		copyCharCheck[map[ypos + 1][xpos] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}

	return ret;
}

vector<bool> globalCharCheck;
vector<vector<char>> gmap;

bool moveAbleCheck2(int x, int y)
{
	if (x < 0)
		return false;

	if (x >= gmap[0].size())
		return false;

	if (y < 0)
		return false;

	if (y >= gmap.size())
		return false;

	if (globalCharCheck[gmap[y][x] - 'A'] == true)
		return false;

	return true;
}

int travel3(int xpos, int ypos)
{

	callcount++;
	//if (callcount % 10000 == 0)
	//	cout << "call count : " << callcount << endl;


	int ret = 0;
	if (moveAbleCheck2(xpos - 1, ypos))
	{
		globalCharCheck[gmap[ypos][xpos - 1] - 'A'] = true;
		int temp = travel3(xpos - 1, ypos);
		globalCharCheck[gmap[ypos][xpos - 1] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck2(xpos + 1, ypos))
	{
		globalCharCheck[gmap[ypos][xpos + 1] - 'A'] = true;
		int temp = travel3(xpos + 1, ypos);
		globalCharCheck[gmap[ypos][xpos + 1] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck2(xpos, ypos - 1))
	{
		globalCharCheck[gmap[ypos - 1][xpos] - 'A'] = true;
		int temp = travel3(xpos, ypos - 1);
		globalCharCheck[gmap[ypos - 1][xpos] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}
	if (moveAbleCheck2(xpos, ypos + 1))
	{
		globalCharCheck[gmap[ypos + 1][xpos] - 'A'] = true;
		int temp = travel3(xpos, ypos + 1);
		globalCharCheck[gmap[ypos + 1][xpos] - 'A'] = false;
		temp++;

		ret = (ret > temp ? ret : temp);
	}

	return ret;
}


int main()
{
	auto map = input();
	vector<bool> charCheck('Z' - 'A' + 1, false); 
	charCheck[map[0][0] - 'A'] = true;
	
	for (int i = 0; i < map.size(); i++)
	{
		vector<char> temp = map[i];
		gmap.push_back(temp);
	}

	globalCharCheck.assign('Z' - 'A' + 1, false);
	globalCharCheck[map[0][0] - 'A'] = true;

	//cout << travel(map, 0, 0, charCheck) + 1<< endl;
	//cout << travel2(map, 0, 0, charCheck, 1) + 1 << endl;
	cout << travel3(0, 0) + 1 << endl;

	return 0;
}
#endif
