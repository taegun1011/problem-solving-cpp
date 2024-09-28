#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    string str;
    cin >> str;


    string sub = str.substr(0, (str.size() + 2) / 3);
    string rev = sub;
    reverse(rev.begin(), rev.end());
    string tail(sub.begin() + 1, sub.end());
    string tailrev(rev.begin() + 1, rev.end());

    cout << ((str == sub + rev + sub || str == sub + tailrev + sub || str == sub + rev + tail || str == sub + tailrev + tail) ? 1 : 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}