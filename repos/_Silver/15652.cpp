#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void recursion(int N, int M, vector<int> v) {
	if (M == 0) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	int start = (v.empty() ? 1 : *(v.end() - 1));

	for (int i = start; i <= N; i++) {
		v.push_back(i);
		recursion(N, M - 1, v);
		v.pop_back();
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	recursion(N, M, vector<int>());
}