#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, K;
	cin >> N >> K;

	vector<int> value(N);
	for (int& i : value)
		cin >> i;
	sort(value.begin(), value.end());

	vector<int> dp(K + 1);

	for (int i = 0; i <= K; i += value[0])
		dp[i] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = K; j >= 0; j--) {
			int sum = 0;
			for (int k = j; k >= 0; k -= value[i])
				sum += dp[k];
			dp[j] = sum;
		}
	}

	cout << dp[K] << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}