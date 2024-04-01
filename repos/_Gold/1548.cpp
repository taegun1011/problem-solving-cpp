#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N;
	cin >> N;
	vector<int> arr(N);

	for (int& x : arr)
		cin >> x;
	
	int ans = 1; //초기화 안했는데 왜 됨 ㅡㅡ
	if (N < 3) {
		ans = N;
	}
	else {
		sort(arr.begin(), arr.end());

		for (int i = N - 1; i >= 2; i--) {
			int j = 0;
			for (; arr[j] + arr[j + 1] <= arr[i]; j++);
			ans = max(ans, i - j + 1);
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