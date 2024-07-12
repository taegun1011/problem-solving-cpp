#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    int s, e, ans = 0;
    while(N--){
        cin >> s >> e;
        pq.push({s, 1});
        pq.push({e, -1});
    }

    int cnt = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        if(p.second == 1){
            cnt++;
            ans = max(ans, cnt);
        }
        else
            cnt--;
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