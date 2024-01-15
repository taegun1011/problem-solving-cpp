#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

char op[5] = { '+','-','*','/','('};
int precedence[5] = { 1,1,2,2,3 };

stack<string> Operand;
stack<char> Operator;

void PMP(); //Pop, Merge, Push

bool isOperator(char);
int getPrec(char);

int main() {
	char ch;
	string temp;

	while ((ch = getchar()) != '\n') {

		//닫는 괄호
		if (ch == ')') {
			//처음 여는 괄호가 나올 때까지 PMP
			while (Operator.top() != '(') PMP();
			Operator.pop();
		}

		//연산자
		else if (isOperator(ch)) {
			//현재 top 연산자의 우선순위가 새 연산자의 우선순위보다 크거나 같은 경우
			while (!Operator.empty() && Operator.top() != '(' && (getPrec(Operator.top()) >= getPrec(ch))) PMP();
			Operator.push(ch);
		}

		//피연산자
		else {
			temp = ch;
			Operand.push(temp);
		}
	}

	//마지막 1번 더
	while (!Operator.empty())
		PMP();

	cout << Operand.top() << endl;
}

bool isOperator(char ch) {
	return (find(op, op + 5, ch) != (op + 5));
}

int getPrec(char ch) {
	return precedence[find(op, op + 5, ch) - op];
}

void PMP() {
	if (Operator.top() == '(') return;
	string op1 = Operand.top(); Operand.pop();
	string op2 = Operand.top(); Operand.pop();
	char oper = Operator.top(); Operator.pop();

	Operand.push(op2 + op1 + oper);
}