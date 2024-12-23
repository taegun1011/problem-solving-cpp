#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
    vector<PII> arr(N);
    for(auto& p : arr)
        cin >> p.first >> p.second;

    sort(arr.begin(), arr.end());

    int cur = 0, cnt = 0;
    for (int i = 0; i < N;i++){
        if(arr[i].second <= cur)
            continue;
        cur = max(cur, arr[i].first);
        int len = arr[i].second - cur;

        int x = (len + M - 1) / M;
        cur = cur + x * M;
        cnt += x;
    }

    cout << cnt << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}