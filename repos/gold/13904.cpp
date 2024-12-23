#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<vector<int>> arr(1001, vector<int>());
    int d, w;
    for (int i = 0; i < N;i++){
        cin >> d >> w;
        arr[d].push_back(w);
    }

    int ans = 0;
    priority_queue<int> pq;
    for (int i = 1000; i >= 1;i--){
        for(int x : arr[i])
            pq.push(x);
        if(pq.empty())
            continue;
        ans += pq.top();
        pq.pop();
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