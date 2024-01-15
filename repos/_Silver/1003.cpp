#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dp[41];

void fibonacci(int n);

int main() {
	int testcase;
	cin >> testcase;

	int n;
	while (testcase > 0) {
		testcase--;

		cin >> n;
		fibonacci(n);
		cout << dp[0] << ' ' << dp[1] << endl;
	}
}


void fibonacci(int n) {
	for (int i = 0; i < 41; i++)
		dp[i] = 0;

	dp[n] = 1;
	for (n; n >= 2; n--) {
		dp[n - 1] += dp[n];
		dp[n - 2] += dp[n];
	}
}