#include <problem.h>

#ifdef _13257_

/// 
/// problem
/// https://www.acmicpc.net/problem/13257
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <iomanip>

using namespace std;

vector<vector<int>> dpTable;

int combination(int n, int r)
{
	if (n < r)
		return 0;

	if (n == r)
		dpTable[n][r] = 1;
	if (r == 0)
		dpTable[n][r] = 1;// 0;

	if (dpTable[n][r] == -1)
		dpTable[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
	
	return dpTable[n][r];
}

// ��ü ����, ���� ��ŷ�� ����, ��� ������ ������
// �̹� ��� Ʈ���̶�, ���� ��ŷ�Ǵ� �༮�� 0~C ������ ��� ����� ���� ������

void getProbability(int N, int M, int C, vector<int>& arr)
{
	for (int i = 0; i <= C; i++)
	{
		//arr[C - i] += combination(N - M, C - i);
		int count = 0;


		int notMark = combination(N - M, C - i);
		int mark = combination(M, i);
		count = notMark * mark;

		arr[C - i] += count;
	}
}

int main()
{
	cout << setprecision(10);

	int N, C, D, M;
	cin >> N >> C >> D >> M;

	vector<vector<int>> arr(1, vector<int>(21, 0));
	arr[0][0] = 1;
	dpTable.assign(N + 1, vector<int>(N + 1, -1));

	for (int i = 0; i < D; i++)
	{
		arr.push_back(vector<int>(21, 0));
		for (int j = 0; j < N; j++)
		{
			if (arr[arr.size() - 2][j] == 0)
				continue;

			//
			// arr���� ��ŷ�� �������� j���� ������
			// ���Ӱ� �߰��� �� �ִ� ��� ����� ���� ������
			vector<int> temp(21, 0);
			getProbability(N, j, C, temp);

			for (int c = 0; c < 21; c++)
			{
				if (temp[c] != 0)
					arr.back()[j + c] += arr[arr.size() - 2][j] * temp[c];
			}
		}
	}

	int sum = 0;
	for (auto c : arr.back())
		sum += c;

	cout << (double)arr.back()[M] / (double)sum << endl;

}
#endif
