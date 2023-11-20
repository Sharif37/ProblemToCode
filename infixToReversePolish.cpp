#include<bits/stdc++.h>
using namespace std ;


int precedence(char c);
int operation(int a, int b, char op);
int calculate(string postfix);
void infixToPostfix();


int precedence(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1 ;
	case '*':
	case '/':
		return 2 ;
	case '^':
		return 3 ;



	}
	return -1 ;
}

int operation(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return b - a;
	case '*': return a * b;
	case '/':
		if (a == 0) {
			cerr << "Error: Division by zero." << endl;
			exit(EXIT_FAILURE);
		}
		return b / a;
	case '^': return pow(b, a);
	}
	cerr << "Error: Invalid operator." << endl;
	exit(EXIT_FAILURE);
}


int calculate(string postfix)
{
	stack<int>st ;
	int length = postfix.length() ;
	for (int i = 0 ; i < length ; i++)
	{
		char c = postfix[i] ;

		if (c >= '0' && c <= '9') {
			st.push(c - '0') ;
		}
		else
		{
			int a = st.top()  ;
			st.pop() ;
			int b = st.top()  ;
			st.pop() ;
			int calculation = operation(a, b, c);
			st.push(calculation);

		}
	}
	return st.top() ;

}

void infixTOpostfix()
{
	string infix ;
	cin >> infix ;
	stack<char>st ;
	int length = infix.length() ;
	string postfix = "";
	for (int i = 0 ; i < length; i++)
	{
		char c = infix[i] ;

		if ( (c >= 'a' && c <= 'z') ||
		        (c >= 'A' && c <= 'Z') ||
		        (c >= '0' && c <= '9')) {
			postfix += c ;


		}
		else if (c == '(') {
			st.push(c) ;
		}
		else if (c == ')')
		{
			while (st.top() != '(')
			{
				postfix += st.top();
				st.pop();
			}
			st.pop();

		} else if (c == '[') {
			st.push(c) ;
		}
		else if (c == ']')
		{
			while (st.top() != '[')
			{
				postfix += st.top();
				st.pop();
			}
			st.pop();

		}

		else
		{
			while (!st.empty() && precedence(c) <= precedence(st.top()))
			{
				postfix += st.top();
				st.pop();
			}
			st.push(c);
		}

	}
	while (!st.empty())
	{
		postfix += st.top();
		st.pop();
	}

	cout << "postfix expression : " << postfix << endl ;
	cout << "value : " << calculate(postfix) << endl ;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin) ;
	freopen("o.txt", "w", stdout) ;
#endif

	infixTOpostfix();





}