#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


string str;
int N;
vector<char> ans;
vector<bool> visited;

void recursion(int cur) {

	for (int i = cur; i < N; i++) {
	char min = CHAR_MAX;
	int idx = -1;
		for (int j = cur; j < N; j++) {
			if (visited[j])
				continue;

			if (min > str[j]) {
				min = str[j];
				idx = j;
			}
		}
	if (min == CHAR_MAX)
		return;

	visited[idx] = 1;
	ans[idx] = min;
	for (char ch : ans)
		if (ch)
			cout << ch;
	cout << '\n';
	recursion(idx + 1);
	}
}

void solve() {
	FASTIO;

	cin >> str;

	N = str.length();
	ans.resize(N);
	visited.resize(N);

	//재귀로 짜야겠다
	recursion(0);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}