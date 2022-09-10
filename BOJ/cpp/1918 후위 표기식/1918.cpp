#include <problem.h>

#ifdef _1918_

/// 
/// problem
/// https://www.acmicpc.net/problem/1918
/// 
/// solution
/// 
/// 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<string> operatorStack;
stack<string> numberStack;

void make();

void pushNumber(string s)
{
	numberStack.push(s);
}

void pushOperator(string s)
{
	if(operatorStack.empty())
		operatorStack.push(s);
	else if (s == ")")
	{
		while (operatorStack.top() != "(")
			make();

		operatorStack.pop();
	}
	else if (operatorStack.top() == "(")
		operatorStack.push(s);
	else if (s == "(")
		operatorStack.push(s);
	else if ((s == "*" || s == "/") && (operatorStack.top() == "+" || operatorStack.top() == "-"))
	{
		operatorStack.push(s);
	}
	else
	{
		make();
		pushOperator(s);
	}
}

void make()
{
	string num1;
	string num2;
	string oper;

	num2 = numberStack.top();
	numberStack.pop();

	num1 = numberStack.top();
	numberStack.pop();
	
	oper = operatorStack.top();
	operatorStack.pop();

	numberStack.push(num1 + num2 + oper);
}

int main()
{
	string inputs;

	cin >> inputs;

	for (auto it = inputs.begin(); it != inputs.end(); it++)
	{
		if (isalpha(*it))
			pushNumber(string(it, it + 1));
		else
			pushOperator(string(it, it + 1));
	}

	while (!operatorStack.empty())
		make();

	cout << numberStack.top() << endl;

	return 0;
}

#endif
