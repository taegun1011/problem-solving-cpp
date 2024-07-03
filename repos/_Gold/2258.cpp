#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    int a, b;
    while(N--){
        cin >> a >> b;
        pq.push({b, -a});
    }

    int sum = 0, cur = -1, tmp = 0, tmp_cnt = 0, ans = INT_MAX;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        if(p.first == cur){
            tmp -= p.second;
            tmp_cnt++;
            if(sum + tmp >= M)
                ans = min(ans, cur * tmp_cnt);
        } else{
            cur = p.first;
            sum += tmp - p.second;
            tmp = 0;
            tmp_cnt = 1;
            if(sum >= M){
                ans = min(ans, cur);
                break;
            }
        }
    }

    cout << (sum + tmp < M ? -1 : ans) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}