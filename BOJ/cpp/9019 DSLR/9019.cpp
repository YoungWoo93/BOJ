#include <problem.h>

#ifdef _9019_

/// 
/// problem
/// https://www.acmicpc.net/problem/9019
/// 
/// solution
/// 
/// 

#include <iostream>
#include <string>
#include <queue>

using namespace std;




int cmdD(const int input)
{
	int ret = input;
	ret *= 2;
	ret %= 10000;

	return ret;
}

int cmdS(const int input)
{
	int ret = input;
	ret += 9999;
	ret %= 10000;

	return ret;
}


int cmdL(const int input)
{
	int ret = input;
	ret %= 1000;
	ret *= 10;
	ret += input / 1000;

	return ret;
}


int cmdR(const int input)
{
	int ret = input;
	ret /= 10;
	ret += (input % 10) * 1000;

	return ret;
}



string process(const int start, const int end)
{
	bool visit[10000] = { false, };

	queue<pair<int, string>> q;

	q.push({ start, "" });
	visit[start] = true;

	while (!visit[end] && !q.empty())
	{
		auto current = q.front();
		int temp = 0;

		{
			temp = cmdD(current.first);
			if (!visit[temp]) {
				if (temp == end)
					return current.second + "D";

				q.push({ temp, current.second + "D" });
				visit[temp] = true;
			}
		}

		{
			temp = cmdS(current.first);
			if (!visit[temp]) {
				if (temp == end)
					return current.second + "S";
				q.push({ temp, current.second + "S" });
			}
			visit[temp] = true;
		}

		{
			temp = cmdL(current.first);
			if (!visit[temp]) {
				if (temp == end)
					return current.second + "L";
				q.push({ temp, current.second + "L" });
			}
			visit[temp] = true;
		}

		{
			temp = cmdR(current.first);
			if (!visit[temp]) {
				if (temp == end)
					return current.second + "R";
				q.push({ temp, current.second + "R" });
			}
			visit[temp] = true;
		}
		q.pop();
	}

}

int main()
{
	int cycle;
	cin >> cycle;

	for (int i = 0; i < cycle; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << process(start, end) << endl;
	}
}

#endif
