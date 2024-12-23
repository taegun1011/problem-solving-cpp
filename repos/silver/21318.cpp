#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N;
	cin >> N;
	vector<int> arr(N+1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	vector<int> psum(N + 1);
	for (int i = 1; i <= N; i++) {
		psum[i] = psum[i - 1];
		if (arr[i - 1] > arr[i])
			psum[i]++;
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int x, y;
		cin >> x >> y;
		cout << psum[y] - psum[x] << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}