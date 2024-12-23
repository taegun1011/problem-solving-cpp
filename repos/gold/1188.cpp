#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
	int mul = a * b;
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return mul / a;
}

void solve(int S, int P) {
	//checked[i] : i와 i+1번째 조각 사이가 잘려있는 지 여부

	int cut = 0, sz = lcm(S, P), i;
	
	vector<bool> checked(sz);
	int Sinterval = sz / S;
	for (i = Sinterval; i < sz; i += Sinterval)
		checked[i] = 1;

	int Pinterval = sz / P;
	for (i = sz - Pinterval; i > 0; i -= Pinterval) {
		if (!checked[i])
			cut++;
	}

	cout << cut << endl;
}

int main() {
	int S, P;
	cin >> S >> P;

	solve(S, P);
}