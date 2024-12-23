#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

void solve() {
    string A, B;
    cin >> A >> B;

    int idx = 0, b = B.length(), ans = 0;
    while(idx < b){
        for (int i = b - 1; i >= idx;i--){
            if(A.find(B.substr(idx, i - idx + 1)) != string::npos){
                idx = i + 1;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}