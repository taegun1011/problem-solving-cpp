#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dp[1001];

int main() {

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++) {

		// dp[i-2]에서 =로 채우기, dp[i-1]에서 |로 채우기
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= 10007;
	}
	
	int n;
	cin >> n;
	cout << dp[n] << endl;

	return 0;
}