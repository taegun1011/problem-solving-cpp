#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

void solve() {
    ll x, y, w, s;
    cin >> x >> y >> w >> s;

    ll m = min(x, y), M = max(x, y);
    ll sq1 = s * m, sq2 = w * m * 2;
    ll rec1 = w * (M - m), rec2 = x % 2 == y % 2 ? s * (M - m) : s * (M - m - 1) + w;
    cout << min(sq1, sq2) + min(rec1, rec2) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}