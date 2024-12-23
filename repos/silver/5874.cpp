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
    N = str.length();

    vector<int> a, b;
    for (int i = 0; i + 1 < N;i++) {
        if(str[i] == str[i + 1]){
            if(str[i] == '(')
                a.push_back(i);
            else
                b.push_back(i);
        }
    }

    int ans = 0;
    for(int x : b)
        ans += upper_bound(a.begin(), a.end(), x) - a.begin();

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}