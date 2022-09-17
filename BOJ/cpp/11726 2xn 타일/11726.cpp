#include <problem.h>

#ifdef _11726_

/// 130
/// problem
/// https://www.acmicpc.net/problem/11726
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dpTable(1001, 0);
	dpTable[0] = 0;
	dpTable[1] = 1;
	dpTable[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dpTable[i] = dpTable[i - 1] + dpTable[i - 2];
		dpTable[i] %= 10007;
	}

}
#endif
