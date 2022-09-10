#include <problem.h>

#ifdef _16120_

/// 
/// problem
/// https://www.acmicpc.net/problem/16120
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


int main()
{
	string inputs = "";
	cin >> inputs;

	stack<char> st;
	st.push(inputs[0]);
	for (int i = 1; i < inputs.length(); i++)
	{
		if (st.top() == 'A')
		{
			if (inputs[i] == 'A')
			{
				cout << "NP" << endl;
				return 0;
			}

			for (int i = 0; i < 3; i++)
			{
				if (st.empty())
				{
					cout << "NP" << endl;
					return 0;
				}

				st.pop();
			}
		}

		st.push(inputs[i]);
	}

	if(st.top() == 'A' || st.size() > 1)
		cout << "NP" << endl;
	else
		cout << "PPAP" << endl;

	return 0;
}


#endif
