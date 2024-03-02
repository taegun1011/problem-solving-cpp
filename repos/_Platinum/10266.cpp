#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N;
	cin >> N;
	vector<int> clk1(N), clk2(N);
	for (int& x : clk1)
		cin >> x;
	for (int& x : clk2)
		cin >> x;

	sort(clk1.begin(), clk1.end());
	clk1.resize(N * 2);
	for (int i = 0; i < N; i++)
		clk1[N + i] = clk1[i] + 360000;

	sort(clk2.begin(), clk2.end());

	vector<int> f = failure(clk2);
	vector<int> ans = kmp(clk1, clk2, f);
	cout << (ans.size() > 1 ? "possible" : "impossible") << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}