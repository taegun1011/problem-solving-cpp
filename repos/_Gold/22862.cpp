#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	for (int& x : arr)
		cin >> x;

	int l = 0, r = 0, ans = 0, cnt = 0;
	while (r < N) {
		cnt += arr[r++] % 2;
		while (cnt > K)
			cnt -= arr[l++] % 2;
		ans = max(ans, r - l - cnt);
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