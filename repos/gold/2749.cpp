#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;

void fibonacci(ll n);

int main() {
	ll n;
	cin >> n;

	n %= 1'500'000;
	fibonacci(n);

	cout << dp[n] << endl;
}

void fibonacci(ll n) {
	dp.push_back(0);
	dp.push_back(1);

	for (int i = 2; i <= n; i++) {
		dp.push_back((dp[i - 1] + dp[i - 2]) % 1'000'000);
	}
}