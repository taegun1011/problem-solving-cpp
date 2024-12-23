#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)



void solve() {
	int M, N;
	cin >> M >> N;

	vector<int> arr(N), l(N), r(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		l[i] = r[i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] > arr[i])
				l[i] = max(l[i], arr[j]);

		for (int j = i + 1; j < N; j++)
			if (arr[j] > arr[i])
				r[i] = max(r[i], arr[j]);
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += min(l[i], r[i]) - arr[i];

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