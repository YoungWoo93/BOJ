#include "control.h"
//
//	control.h 에서 확인하고자 하는 문제 번호를 선언해주어야 함
//

#ifdef _1006_
// https://www.acmicpc.net/problem/1006


#include <iostream>
#include <vector>
#include <algorithm>

#define inside	0
#define outside 1
#define inout	2

using namespace std;

typedef struct node{
	bool isMerge;
	int enemyCount;
}node;

void input(int& partCount, int& memberCount, vector<node>* arr, vector<int>* memo);

void setMemo(int index, vector<int>* memo, vector<node>* arr);
bool isMargeable(node a, node b);

int MemberCount;

int main()
{
	int caseCount;
	vector<int> printlist;
	cin >> caseCount;

	for (int i = 0; i < caseCount; i++)
	{
		vector<node> part[2];
		vector<int> memo[3];

		int partCount, memberCount;
		input(partCount, memberCount, part, memo);
		int temp;


		// 그냥 시작하기 (둘다 안잇기)
		if (true)
		{
			memo[inside][0] = 1;
			memo[outside][0] = 1;
			memo[inout][0] = 2;				

			setMemo(0, memo, part);
			temp = memo[inout][partCount - 1];
		}
		
		// 그냥 시작하기 (최초 인덱스의 내외곽 연결)
		if (isMargeable(part[inside][0], part[outside][0]))
		{
			memo[inside][0] = 1;
			memo[outside][0] = 1;
			memo[inout][0] = 1;

			int temp2 = part[inside][0].enemyCount;
			int temp3 = part[outside][0].enemyCount;
			part[inside][0].enemyCount = MemberCount + 1;
			part[outside][0].enemyCount = MemberCount + 1;
			setMemo(0, memo, part);
			part[inside][0].enemyCount = temp2;
			part[outside][0].enemyCount = temp3;

			temp = min(temp, memo[inout][partCount - 1]);
		}

		// 외곽 잇고 시작하기
		if (partCount > 1)
		{
			if (isMargeable(part[outside][0], part[outside][partCount-1]))
			{
				memo[inside][0] = 1;
				memo[outside][0] = 1;
				memo[inout][0] = 2;

				int temp2 = part[outside][0].enemyCount;
				part[outside][0].enemyCount = MemberCount + 1;
				setMemo(0, memo, part);
				part[outside][0].enemyCount = temp2;
				
				temp = min(temp, memo[inside][partCount - 1]);
			}

			// 내곽 잇고 시작하기
			if (isMargeable(part[inside][0], part[inside][partCount - 1]))
			{
				memo[inside][0] = 1;
				memo[outside][0] = 1;
				memo[inout][0] = 2;

				int temp2 = part[inside][0].enemyCount;
				part[inside][0].enemyCount = MemberCount + 1;
				setMemo(0, memo, part);
				part[inside][0].enemyCount = temp2;

				temp = min(temp, memo[outside][partCount - 1]);
			}

			// 내외곽 잇고 시작하기
			if (isMargeable(part[outside][0], part[outside][partCount - 1]) && isMargeable(part[inside][0], part[inside][partCount - 1]) && partCount >= 2)
			{
				memo[inside][0] = 1;
				memo[outside][0] = 1;
				memo[inout][0] = 2;

				int temp2 = part[inside][0].enemyCount;
				int temp3 = part[outside][0].enemyCount;
				part[inside][0].enemyCount = MemberCount + 1;
				part[outside][0].enemyCount = MemberCount + 1;
				setMemo(0, memo, part);
				part[inside][0].enemyCount = temp2;
				part[outside][0].enemyCount = temp3;

				temp = min(temp, memo[inout][partCount - 2]);
			}
		}

		printf("%d\n", temp);
	}

	return 0;
}

void setMemo(int index, vector<int>* memo, vector<node>* arr)
{
	if (index >= memo[0].size() - 1)
		return;

	int temp;
	if (true) // 다음 인덱스의 내부만 체크 상태를 만들기
	{
		temp = memo[inout][index] + 1; // 현재 안밖을 모두 체크했고, 다음인덱스의 내부 하나만 연결없이 체크

		if (isMargeable(arr[inside][index], arr[inside][index+1]))
			temp = min(temp, memo[outside][index] + 1); // 현재인덱스의 외부만 체크된 상태고, 현재인덱스의 내부와 다음 인덱스의 내부가 연결 가능할경우
		else
			temp = min(temp, memo[outside][index] + 2); // 현재인덱스의 외부만 체크된 상태고, 현재인덱스의 내부와 다음 인덱스의 내부가 연결 불가능할경우

		temp = min(temp, memo[inside][index] + 2); // 현재 내부만 체크된 상태고, 현재인덱스의 외부와 다음 인덱스의 내부를 각각 체크해 주는 경우
	}
	memo[inside][index + 1] = temp;

	if (true) // 다음 인덱스의 외부만 체크 상태를 만들기
	{
		temp = memo[inout][index] + 1; // 현재 안밖을 모두 체크했고, 다음인덱스의 외부 하나만 연결없이 체크 이하 위와 반대

		if (isMargeable(arr[outside][index], arr[outside][index + 1]))
			temp = min(temp, memo[inside][index] + 1);
		else
			temp = min(temp, memo[inside][index] + 2);

		temp = min(temp, memo[outside][index] + 2);
	}
	memo[outside][index + 1] = temp;

	if (true) // 다음 인덱스 내외부를 체크 상태로 만들기
	{
		temp = memo[inout][index] + 2; // 현재 안밖을 모두 체크했고, 다음인덱스의 내외부 모두 각각 체크해 주는 경우

		if (index >= 1)
		{
			if (isMargeable(arr[inside][index], arr[inside][index + 1]) && isMargeable(arr[outside][index], arr[outside][index + 1]))
				temp = min(temp, memo[inout][index - 1] + 2); // 바로 전 인덱스의 안밖이 모두 체크되있는 상황에서, 현재 인덱스와 다음 인덱스가 내부끼리 외부끼리 연결이 가능한 상태일때
		}
		else
		{
			if (isMargeable(arr[inside][index], arr[inside][index + 1]) && isMargeable(arr[outside][index], arr[outside][index + 1]))
				temp = min(temp, memo[inout][index]); // 현재 인덱스와 다음 인덱스가 내부끼리 외부끼리 동시에 연결이 가능한 상태일때
		}
		
		if (isMargeable(arr[inside][index + 1], arr[outside][index + 1]))
			temp = min(temp, memo[inout][index] + 1); // 현재 안밖을 모두 체크했고, 다음 인덱스의 내외부를 서로 연결해 연결체크

		if (isMargeable(arr[outside][index], arr[outside][index + 1]))
			temp = min(temp, memo[inside][index] + 2); // 현재 내부가 하나 체크되어있고 다음 인덱스의 외부와 현재 인덱스의 외부가 연결 가능한 상태일때, 그 둘을 연결하고 다음 인덱스의 내부를 연결없이 체크

		if (isMargeable(arr[inside][index], arr[inside][index + 1]))
			temp = min(temp, memo[outside][index] + 2); // 바로 위와 반대
		
	}
	memo[inout][index + 1] = temp;

	setMemo(index + 1, memo, arr);
}

void input(int& partCount, int& memberCount, vector<node>* arr, vector<int>* memo)
{
	cin >> partCount;
	cin >> memberCount;

	arr[0].resize(partCount);
	arr[1].resize(partCount);

	memo[inside].resize(partCount);
	memo[outside].resize(partCount);
	memo[inout].resize(partCount);

	for (int i = 0; i < partCount; i++)
	{
		int temp;

		cin >> temp;

		arr[0][i].enemyCount = temp;
	}

	for (int i = 0; i < partCount; i++)
	{
		int temp;

		cin >> temp;

		arr[1][i].enemyCount = temp;
	}

	MemberCount = memberCount;
}

bool isMargeable(node a, node b)
{
	return a.enemyCount + b.enemyCount <= MemberCount;
}





#endif