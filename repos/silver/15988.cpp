#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int m = 1000000009;

int main() {
	int TC;
	cin >> TC;

	vector<long long> dp(1000001);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % m;

	int n;
	while (TC) {
		TC--;
		cin >> n;
		cout << dp[n] << endl;
	}
}