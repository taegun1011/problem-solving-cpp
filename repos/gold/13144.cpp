#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N;
	cin >> N;

	vector<int> count(100001);
	vector<int> arr(N);
	for (int& x : arr)
		cin >> x;

	int s = 0, e = 0;
	long long ans = 0;
	while (e < N) {
		while (s < e && count[arr[e]])
			count[arr[s++]]--;
		ans += e - s + 1;
		count[arr[e++]]++;
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