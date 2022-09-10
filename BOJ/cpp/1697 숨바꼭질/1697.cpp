#include <problem.h>

#ifdef _1697_

/// 
/// problem
/// https://www.acmicpc.net/problem/1697
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1697%EB%B2%88-%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%88
/// 

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> input(int& start, int& end)
//{
//	cin >> start;
//	cin >> end;
//
//	vector<int> ret(end * 2, -1);
//
//	return ret;
//}
//
//int main()
//{
//	int start;
//	int end;
//	auto board = input(start, end);
//
//	if (end <= start)
//	{
//		cout << start - end << endl;
//		return 0;
//	}
//
//	queue<int> q;
//	q.push(start);
//	board[start] = 0;
//
//	while (board[end] == -1)
//	{
//		if (q.front() + 1 < board.size())
//		{
//			if (board[q.front() + 1] == -1 || board[q.front() + 1] > board[q.front()])
//			{
//				board[q.front() + 1] = board[q.front()] + 1;
//				q.push(q.front() + 1);
//			}
//		}
//		if (q.front() - 1 >= 0)
//		{
//			if (board[q.front() - 1] == -1 || board[q.front() - 1] > board[q.front()])
//			{
//				board[q.front() - 1] = board[q.front()] + 1;
//				q.push(q.front() - 1);
//			}
//		}
//		if (q.front() * 2 < board.size())
//		{
//			if (board[q.front() * 2] == -1 || board[q.front() * 2] > board[q.front()])
//			{
//				board[q.front() * 2] = board[q.front()] + 1;
//				q.push(q.front() * 2);
//			}
//		}
//
//		q.pop();
//	}
//
//	cout << board[end] << endl;
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> input(int& start, int& end)
{
	cin >> start;
	cin >> end;

	vector<int> ret(end * 2, -1);

	return ret;
}

int main()
{
	int start;
	int end;
	auto board = input(start, end);

	if (end <= start)
	{
		cout << start - end << endl;
		return 0;
	}

	queue<int> q;
	q.push(end);
	board[end] = 0;

	while (board[start] == -1)
	{
		if (q.front() + 1 < board.size())
		{
			if (board[q.front() + 1] == -1 || board[q.front() + 1] > board[q.front()])
			{
				board[q.front() + 1] = board[q.front()] + 1;
				q.push(q.front() + 1);
			}
		}
		if (q.front() - 1 >= 0)
		{
			if (board[q.front() - 1] == -1 || board[q.front() - 1] > board[q.front()])
			{
				board[q.front() - 1] = board[q.front()] + 1;
				q.push(q.front() - 1);
			}
		}
		if (q.front() % 2 == 0 && q.front() / 2 >= 0)
		{
			if (board[q.front() / 2] == -1 || board[q.front() / 2] > board[q.front()])
			{
				board[q.front() / 2] = board[q.front()] + 1;
				q.push(q.front() / 2);
			}
		}

		q.pop();
	}

	cout << board[start] << endl;

	return 0;
}
#endif
