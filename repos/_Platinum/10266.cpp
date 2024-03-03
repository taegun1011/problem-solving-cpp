#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void kmp(vector<int>& H, vector<int>& N) {
	int h = H.size(), n = N.size();
	int i = 0, j = 0;
	
	int diff = H[0] - N[0];
	while (i <= h - n) {
		if (j < n && H[i + j] - N[j] == diff) {
			if (++j == n) {
				cout << "possible" << endl;
				return;
			}
		}
		else {
			i++;
			j = 0;
			diff = H[i] - N[0];
		}
	}

	cout << "impossible" << endl;
}

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

	kmp(clk1, clk2);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}