//Name: Zachary Williams
//Class: 2019 <Fall> - COSC 2336.S70
//Project #: Assignment 4
//Revision: 1.0.0
//Date: 10/9/19
//Description: Write a program that takes as input an arithmetic expression. The program outputs whether the expression contains matching grouping symbols. For example, the arithmetic expression {25+(3-6)*8} and 7+8*2 contains matching grouping symbols.However, the expression 5+{(13+7)/8-2*9 does not contain matching grouping symbols.


#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkGrouping(string expr)
{
	stack<char> s;
	char x;

	// Traversing the Expression 
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
		{
			// Push the element in the stack 
			s.push(expr[i]);
			continue;
		}

		// IF current current character is not opening 
		// bracket, then it must be closing. So stack 
		// cannot be empty at this point. 
		if (s.empty())
			return false;

		switch (expr[i])
		{
		case ')':

			// Store the top element in a 
			x = s.top();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			// Store the top element in b 
			x = s.top();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			// Store the top element in c 
			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}

	// Check Empty Stack 
	return (s.empty());
}

int main()
{
	bool result = false;
	string input = "NULL";

	cout << "Enter an expression" << endl;
	cin >> input;
	result = checkGrouping(input);

	cout << endl << boolalpha << "Result: " << result << endl;
	system("pause");
	return 0;
}