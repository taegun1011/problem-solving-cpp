#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int D, P;
	cin >> D >> P;

	vector<int> L(P), C(P);
	for (int i = 0; i < P; i++)
		cin >> L[i] >> C[i];

	vector<int> dp(D + 1);
	dp[0] = 1e9;

	for (int i = 0; i < P; i++) {
		for (int j = D; j > 0; j--)
			if (j >= L[i])
				dp[j] = max(dp[j], min(dp[j - L[i]], C[i]));
	}

	cout << dp[D] << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}