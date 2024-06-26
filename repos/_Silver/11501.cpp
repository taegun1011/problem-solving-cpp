#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<int> arr(N);
    vector<bool> hasBigger(N);
    for(int& x : arr)
        cin >> x;

    int mx = 0;
    for (int i = N - 1; i >= 0;i--){
        if(mx > arr[i])
            hasBigger[i] = true;
        mx = max(mx, arr[i]);
    }

    ll ans = 0, cnt = 0;
    for (int i = 0; i < N;i++){
        if(hasBigger[i]) {
            ans -= arr[i];
            cnt++;
        }           
        else{
            ans += cnt * arr[i];
            cnt = 0;
        }
    }

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}