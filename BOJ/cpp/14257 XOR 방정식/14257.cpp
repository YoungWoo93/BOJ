#include <problem.h>

#ifdef _14257_

/// 
/// problem
/// https://www.acmicpc.net/problem/14257
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
	long long int S;
	long long int X;

	cin >> S >> X;


	long long int result = 1;
	bool upAble = false;
	bool up = false;
	int offset = 0;
	if (S == X)
		offset = -2;

	while (S || X)
	{
		int bitS = 0;
		int bitX = 0;

		bitS = S % 2;
		bitX = X % 2;

		if (bitS == 1 && bitX == 1)
		{
			result *= 2;

			if (up)
			{
				cout << 0 << endl;
				return 0;
			}

			upAble = false;
			up = false;
		}
		else if (bitS == 0 && bitX == 0)
		{
			if (up)
			{
				cout << 0 << endl;
				return 0;
			}

			upAble = true;
			up = false;
		}
		else if (bitS == 1 && bitX == 0)
		{
			if (upAble)
				up = true;

			if (!up)
			{
				cout << 0 << endl;
				return 0;
			}

			upAble = true;
			up = false;
		}
		else if (bitS == 0 && bitX == 1)
		{
			result *= 2;

			if (upAble)
				up = true;

			if (!up)
			{
				cout << 0 << endl;
				return 0;
			}

			upAble = true;
			up = true;
		}

		S /= 2;
		X /= 2;
	}

	if (up)
	{
		cout << 0 << endl;
		return 0;
	}

	cout << result + offset << endl;


	return 0;
}
#endif
