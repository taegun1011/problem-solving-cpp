#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void recursive(int N, int M, vector<int> v) {
	if (v.size() == M) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (find(v.begin(), v.end(), i) == v.end()) {
			v.push_back(i);
			recursive(N, M, v);
			v.pop_back();
		}
	}
}

int main() {
	FASTIO;

	int N, M;
	cin >> N >> M;

	recursive(N, M, vector<int> ());
}