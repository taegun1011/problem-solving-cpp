#define _CRT_SECURE_NO_WARNIGS
#include <iostream>

using namespace std;
int dp[10001];

int getMax(int* liter, int n);
int main() {
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);

	int n, temp;
	cin >> n;
	int* cost = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		cost[i] = temp;
	}

	cout << getMax(cost, n) << endl;
}

int getMax(int* cost, int n) {
	dp[0] = 0;
	dp[1] = cost[1];
	if (n == 1)
		return dp[1];
	dp[2] = cost[1] + cost[2];
	if (n == 2)
		return dp[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + cost[i - 1], dp[i - 2]) + cost[i];
		dp[i] = max(dp[i], dp[i - 1]);
	}

	return max(dp[n - 1], dp[n]);
}