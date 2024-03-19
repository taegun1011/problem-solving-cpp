#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

ll dp[1 << 15][101];
vector<string> arr;
vector<int> dm(51);
vector<int> m;
int N, K;

int mod(const string& num, int K) {
	ll ret = 0;
	for (int i = 0; i < num.length(); i++)
		ret = (ret * 10 + (num[i] - '0')) % K;
	return ret;
}

ll re_dp(int field, int left) {
	if (field + 1 == (1 << N))
		return !left;
	if (dp[field][left] != -1)
		return dp[field][left];
	ll& ret = dp[field][left] = 0;

	for (int nxt = 0; nxt < N; nxt++) {
		if (field & (1 << nxt))
			continue;
		ret += re_dp(field | (1 << nxt), (left * dm[arr[nxt].length()] + m[nxt]) % K);
	}

	return ret;
}

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a%b);
}

ll fact(ll x) {
	if (x == 1)
		return x;
	return x * fact(x - 1);
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;

	arr = vector<string> (N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> K;
	dm[0] = 1;
	for (int i = 1; i <= 50; i++)
		dm[i] = dm[i - 1] * 10 % K;

	//m : 각 수를 K로 나눈 나머지
	//dm : 10^i를 K로 나눈 나머지
	m = vector<int>(N);
	for (int i = 0; i < N; i++)
		m[i] = mod(arr[i], K);

	ll p = re_dp(0, 0), q = fact(N);
	if (p) {
		ll GCD = gcd(p, q);
		cout << p / GCD << '/' << q / GCD << endl;
	}
	else
		cout << "0/1" << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}