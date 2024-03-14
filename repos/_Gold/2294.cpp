#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 987654321

void solve() {
	int N, K;
	cin >> N >> K;

	vector<int> value(N);
	for (int& i : value)
		cin >> i;

	vector<int> dp(K + 1, INF);
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			if (value[i] <= j)
				dp[j] = min(dp[j], dp[j - value[i]] + 1);
		}
	}

	cout << (dp[K] == INF ? -1 : dp[K]) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}