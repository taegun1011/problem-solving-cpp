#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

string str;

bool dnc(int l, int r){
    if(l == r)
        return true;

    int m = l + (r - l) / 2;
    if(dnc(l, m - 1) && dnc(m + 1, r)){
        for (; l < m && r > m; l++, r--)
            if(str[l] == str[r])
                return false;
        return true;
    }
    return false;
}

void solve() {
    cin >> str;

    cout << (dnc(0, str.length() - 1) ? "YES" : "NO") << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}