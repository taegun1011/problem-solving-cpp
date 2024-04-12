#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<bool> is_prime(100001, true);

void solve() {
	for (int i = 2; i * i <= 100000; i++) {
		if (!is_prime[i])
			continue;
		for (int j = i * i;  j <= 100000; j += i)
			is_prime[j] = false;
	}

	vector<int> prime;
	for (int i = 2; i <= 100000; i++)
		if (is_prime[i])
			prime.push_back(i);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cout << prime[i] << (i - N + 1 ? ' ' : '\n');
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}