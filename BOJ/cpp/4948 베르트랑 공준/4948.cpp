#include <problem.h>

#ifdef _4948_

/// 
/// problem
/// https://www.acmicpc.net/problem/4948
/// 
/// solution
/// https://dev-game-standalone.tistory.com/entry/BOJ-4948-%EB%B2%A0%EB%A5%B4%ED%8A%B8%EB%9E%91-%EA%B3%B5%EC%A4%80
/// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPrimeNums(int size = 123456 * 2)
{
	vector<int> ret;

	if (size < 2)
		return ret;

	auto remove = [](vector<bool>& arr, int start, int scale) {
		for (int i = start * 2; i < arr.size(); i += scale)
			arr[i] = false;
	};
	vector<bool> eratos(size+1, true);
	eratos[0] = eratos[1] = false;


	for (int i = 2; i < size + 1; i++)
	{
		if(eratos[i])
			remove(eratos, i, i); 
	}

	for (int i=0; i<eratos.size(); i++)
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
	
	while (req != 0)
	{
		int ret = 0;
		for (int i = 0; i < lst.size(); i++)
		{
			if (req < lst[i] && lst[i] <= req * 2)
				ret++;

			if (req * 2 < lst[i])
				break;
			
		}
		cout << ret << endl;

		cin >> req;
	}


	return 0;
}

#endif
