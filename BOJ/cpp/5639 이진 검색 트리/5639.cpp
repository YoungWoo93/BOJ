#include <problem.h>

#ifdef _5639_

/// 
/// problem
/// https://www.acmicpc.net/problem/5639
/// 
/// solution
/// 
/// 


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct node
{
	int value;
	node* left = nullptr;
	node* right = nullptr;
};

bool makeTree(stack<node*> &st, node* newNode)
{
	if (st.empty())
		return false;

	node* cur = st.top();

	if (cur->value > newNode->value)
	{
		if (cur->left == nullptr)
		{
			cur->left = newNode;
			st.push(newNode);
			return true;
		}
		else
			return false;
	}
	else
	{
		st.pop();
		if (!makeTree(st, newNode))
		{
			st.push(cur);

			if (cur->right == nullptr)
			{
				cur->right = newNode;
				st.push(newNode);
				return true;
			}
			else
				return false;
		}

		return true;
	}
}

node* inputs()
{
	node* ret = new node();
	node* cur;
	stack<node*> st;

	if (scanf("%d", &ret->value) == EOF)
		return nullptr;

	st.push(ret);

	while (true)
	{
		node* cur = new node();
		if (scanf("%d", &cur->value) == EOF)
			break;
		if (cur->value == -1)
			break;

		if (!makeTree(st, cur))
		{
			st.top()->left = cur;
			st.push(cur);
		}
	}

	return ret;
}

void dfs(node* root)
{
	if (root->left != nullptr)
		dfs(root->left);
	if (root->right != nullptr)
		dfs(root->right);

	printf("%d\n", root->value);
}


int main()
{
	auto root = inputs();
	dfs(root);
}

#endif
