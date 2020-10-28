#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _10942_
// https://www.acmicpc.net/problem/10942

#include <iostream>
#include <vector>

using namespace std;

int isPalindrome(int start, int end, vector<int>& arr, vector<vector<char>>& check);
void init(vector<int>& arr, vector<vector<char>>& check);

int main()
{
	int numberSize, questionSize;
	int start, end;

	vector<vector<char>> palindromeCheck;
	vector<int> arr;

	scanf("%d", &numberSize);

	for (int i = 0; i < numberSize; i++)
	{
		int temp;
		scanf("%d", &temp);
		
		arr.push_back(temp);
	}

	init(arr, palindromeCheck);

	scanf("%d", &questionSize);

	for (int i = 0; i < questionSize; i++)
	{
		scanf("%d%d", &start, &end);

//		for (int i = start - 1; i < end; i++)
//			printf("%d ", arr[i]);
//		printf("\n");

		if (isPalindrome(start-1, end-1, arr, palindromeCheck) == 1)
			printf("1\n");
		else
			printf("0\n");
	}



	return 0;
}

void init(vector<int>& arr, vector<vector<char>>& check)
{
	int arrSizes = arr.size();

	check.reserve(arrSizes);
	for (int i = 0; i < arrSizes; i++)
	{
		vector<char> temp(arrSizes, 0);
		check.push_back(temp);
	}
}

int isPalindrome(int start, int end, vector<int>& arr, vector<vector<char>>& check)
{
	if (start == end)
		return check[start][end] = 1;
	
	if (start + 1 == end && arr[start] == arr[end])
		return check[start][end] = 1;

	if (start > end)
		return -1;

	if (check[start][end] != 0)
		return check[start][end];

	if (isPalindrome(start + 1, end - 1, arr, check) == -1)
		return check[start][end] = -1;

	if (arr[start] == arr[end])
		return check[start][end] = 1;
	
	return check[start][end] = -1;
	
}

#endif