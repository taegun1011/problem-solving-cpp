#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
vector<int> arr;

bool chk(int m) {
	int cnt = 1, mn = arr[0], mx = arr[0];
	for (int j = 0; j < N; j++) {
		if (arr[j] - mn > m || mx - arr[j] > m) {
			cnt++;
			if (cnt > M)
				return false;
			mn = mx = arr[j];
		}
		mn = min(mn, arr[j]);
		mx = max(mx, arr[j]);
	}

	//M개 이하 구간으로 나눌 수 있으면 M개 구간으로도 나눌 수 있다
	return true;
}

void solve() {
	cin >> N >> M;
	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;
	int s = 0, e = 9999, m;

	//NNNNYYYY
	while (s < e) {
		m = s + (e - s) / 2;
		if (chk(m))
			e = m;
		else
			s = m + 1;
	}
	cout << s << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}