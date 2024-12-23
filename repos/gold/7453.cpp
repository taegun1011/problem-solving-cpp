#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ub(a, x) upper_bound((a).begin(), (a).end(), (x))
#define lb(a, x) lower_bound((a).begin(), (a).end(), (x))
#define ll long long

void solve() {
	int N;
	cin >> N;

	vector<vector<int>> arr(4, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];

	vector<int> l, r;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			l.push_back(arr[0][i] + arr[1][j]);
			r.push_back(arr[2][i] + arr[3][j]);
		}
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	ll ans = 0;
	for (int x : l)
		ans += ub(r, -x) - lb(r, -x);
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