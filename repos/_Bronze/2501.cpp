#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, K;
	cin >> N >> K;

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i)
			continue;
		if (!--K) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}