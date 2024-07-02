#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
    vector<int> arr(N);
    for(int& x : arr)
        cin >> x;

    int ans = 1, j = 0;
    for (int i = 1; i < N;i++){
        if(arr[i] == arr[i - 1])
            j = i;
        ans = max(ans, i - j + 1);
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