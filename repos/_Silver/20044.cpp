#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<int> arr(N << 1);
    for(int& x : arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for(int i=0;i<N;i++)
        ans = min(ans, arr[i] + arr[(N << 1) - i - 1]);
    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}