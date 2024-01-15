#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void parse(string str, deque<int>& v) {
	str = str.substr(1, str.size() - 2);

	int idx = 0, num = 0, base = 1;
	for (char c : str) {
		if (c == ',') {
			v[idx++] = num;
			num = 0;
		}
		else {
			num *= 10;
			num += c - '0';
		}
	}

	if (num)
		v[idx] = num;
}

void print(deque<int>& D, int start, int end, int inc) {
	cout << '[';
	for (int i = start; i != end; i += inc) {
		cout << D[i];
		if (i != end - inc)
			cout << ',';
	}
	cout << ']' << '\n';
}

void solve() {
	//R이 홀수번 나왔으면 pop_back, 짝수번 나왔으면 pop_front
	string func;
	cin >> func;

	int N;
	cin >> N;
	deque<int> D(N);

	string arr;
	cin >> arr;

	parse(arr, D);

	int Rcnt = 0;
	for (char cmd : func) {
		if (cmd == 'R')
			Rcnt++;
		else if (D.empty()) {
			cout << "error\n";
			return;
		}
		else if (Rcnt % 2)
			D.pop_back();
		else
			D.pop_front();
	}

	if (Rcnt % 2)
		print(D, D.size() - 1, -1, -1);
	else
		print(D, 0, D.size(), 1);
}

int main() {
	FASTIO;

	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}