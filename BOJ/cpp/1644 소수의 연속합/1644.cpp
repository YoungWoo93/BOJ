#include <problem.h>

#ifdef _1644_

/// 
/// problem
/// https://www.acmicpc.net/problem/1644
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-1644-%EC%86%8C%EC%88%98%EC%9D%98-%EC%97%B0%EC%86%8D%ED%95%A9?category=530798
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPrimeNums(int size = 4005000)
{
	vector<int> ret;

	if (size < 2)
		return ret;

	auto remove = [](vector<bool>& arr, int start, int scale) {
		for (int i = start * 2; i < arr.size(); i += scale)
			arr[i] = false;
	};
	vector<bool> eratos(size + 1, true);
	eratos[0] = eratos[1] = false;


	for (int i = 2; i < size + 1; i++)
	{
		if (eratos[i])
			remove(eratos, i, i);
	}

	for (int i = 0; i < eratos.size(); i++)
	{
		if (eratos[i])
			ret.push_back(i);
	}

	return ret;
}




int main()
{
	auto lst = getPrimeNums();
	int req;

	cin >> req;
	int front = 0;
	int rear = 0;
	int tempSum = 2;
	int ret = 0;

	while (lst[rear] <= req)
	{
		if (tempSum == req)
		{
			ret++;

			front++;
			tempSum += lst[front];
		}
		else if (tempSum < req)
		{
			front++;
			tempSum += lst[front];
		}
		else if (tempSum > req)
		{
			tempSum -= lst[rear];
			rear++;
		}

	}

	cout << ret << endl;

	return 0;
}

#endif
