#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int sum123(int n);

int main() {
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << sum123(n) << endl;
	}
}

int sum123(int n) {
	int dp[11][4] = { {0,0,0,0},{0,1,0,0},{0,1,1,0},{0,2,1,1},0 };
	int i, j;
	for (i = 4; i <= n; i++) {
		for (j = 1; j <= 3; j++) {
			dp[i][1] += dp[i - 1][j];
			dp[i][2] += dp[i - 2][j];
			dp[i][3] += dp[i - 3][j];
		}
	}

	return dp[n][1] + dp[n][2] + dp[n][3];
}