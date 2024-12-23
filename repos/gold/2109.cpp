#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
bool visited[10001];

void solve() {
    cin >> N;

    //가장 비싼 강의부터 마지막 날에 간다
    priority_queue<PII> pq;
    int d, p;
    while(N--){
        cin >> p >> d;
        pq.push({p, d});
    }

    int ans = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        for(int i=p.second;i>=1;i--)
            if(!visited[i]){
                ans+=p.first;
                visited[i] = true;
                break;
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