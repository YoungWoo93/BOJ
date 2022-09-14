#include <problem.h>

#ifdef _12850_

/// 
/// problem
/// https://www.acmicpc.net/problem/12850
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;
vector<vector<bool>> map = {
	{false, true, true, false, false, false, false},
	{true, false, true, true, true, false, false},
	{true, true, false, true, false, false, false},
	{false, true, false, false, true, true, false},
	{false, true, true, true, false, false, true},
	{false, false, false, true, false, false, true},
	{false, false, false, false, true, true, false}
};

vector<vector<vector<int>>> dpTable;

void process(int step)
{
	
}
int main()
{
	int n;
	cin >> n;

	int answer = 0;
	process(n);


	answer += dpTable[n - 1][0][0];
	answer = answer % 1000000007;
	answer += dpTable[n - 1][1][0];
	answer = answer % 1000000007;
	answer += dpTable[n - 1][0][1];
	answer = answer % 1000000007;
	answer += dpTable[n - 1][1][1];
	answer = answer % 1000000007;

	cout << answer << endl;
	
}
#endif
