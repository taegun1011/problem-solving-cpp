#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
    vector<int>arr(N);
    for(int& x : arr) cin >> x;

    int a, b, c;
    while(M--){
        cin >> a >> b >> c;
        if(a == 1) arr[b - 1] = c;
        else cout << abs(arr[b - 1] - arr[c - 1]) << '\n';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}