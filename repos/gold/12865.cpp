#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 101
int knapsack(int* w, int* v, int n, int k);

int main() {
	int n, k;
	cin >> n >> k;

	int value[MAX], weight[MAX];
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	cout << knapsack(weight, value, n, k) << endl;

	return 0;
}

int knapsack(int* w, int* v, int n, int k) {
	int** dp = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new int[k + 1];
	}

	int i, j;

	for (i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (j = 0; j <= k; j++)
		dp[0][j] = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (w[i] <= j) { //넣는다, 안 넣는다
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}
			else { //못 넣는다
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][k];
}

