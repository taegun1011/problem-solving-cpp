#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;

	vector<vector<int>> v(6, vector<int>(2, K - 1));

	for (int i = 0; i < N; i++) {
		int S, Y;
		cin >> S >> Y;
		v[Y - 1][S]++;
	}

	int ans = 0;
	for (auto Y : v)
		for (auto S : Y)
			ans += S / K;

	cout << ans << endl;
}