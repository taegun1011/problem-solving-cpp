#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

vector<int> arr;

void subset(int cur, int e, ll sum, vector<ll>& res) {
	if (cur == e) {
		res.push_back(sum);
		return;
	}
	subset(cur + 1, e, sum + arr[cur], res);
	subset(cur + 1, e, sum, res);
}

void solve() {
	int N, C;
	cin >> N >> C;

	arr.resize(N);
	for (int& x : arr)
		cin >> x;

	vector<ll> left, right;
	subset(0, N / 2, 0, left);
	subset(N / 2, N, 0, right);
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int ans = 0;
	for (ll l : left) {
		//vector<ll>::iterator res = upper_bound(right.begin(), right.end(), C - l);
		//ans += res == right.end() ? right.size() : res - right.begin();
		ans += upper_bound(right.begin(), right.end(), C - l) - right.begin();
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