#include <problem.h>

#ifdef _11403_

/// 
/// problem
/// https://www.acmicpc.net/problem/11403
/// 
/// solution
/// 
/// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void input(vector<vector<int>>& map)
{
	int size;
	cin >> size;

	map.assign(size, vector<int>(size, 0));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cin >> map[i][j];
	}
}

void BFS(vector<vector<int>>& map, vector<vector<bool>>& moveAbleTable, int node)
{
	// 1. DFS 돎
	// 2. 각 노드에서 이동 가능 체크 된 얘들의 값을 보고 자신의 이동가능 리스트에 그냥 더함
	// 3. 최종적으로 uniqe 해줌

	vector<bool> visits(map.size(), false);
	queue<int> q;
	int currentNode = node;
	q.push(currentNode);


	while (!q.empty())
	{
		currentNode = q.front();
		q.pop();

		for (int link = 0; link < map.size(); link++)
		{
			if (map[currentNode][link] == 0 || visits[link])
				continue;

			visits[link] = true;

			if (moveAbleTable[currentNode].back())
			{
				for (int i = 0; i < map.size(); i++)
				{
					if (moveAbleTable[currentNode][i])
						moveAbleTable[node][i] = true;
				}
			}
			else
			{
				q.push(link);
				moveAbleTable[node][link] = true;
			}
		}
	}
}

void process(vector<vector<int>>& map, vector<vector<bool>>& moveAbleTable)
{
	for (int node = 0; node < map.size(); node++)
	{
		BFS(map, moveAbleTable, node);
		moveAbleTable[node].back() = true;
	}
}

int main()
{
	vector<vector<int>> map;
	input(map);

	vector<vector<bool>> moveAbleTable(map.size(), vector<bool>(map.size() + 1, false));
	process(map, moveAbleTable);
	
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			if (moveAbleTable[i][j])
				cout << 1 << " ";
			else
				cout << 0 << " ";
 		}
		cout << endl;
	}
}
#endif
