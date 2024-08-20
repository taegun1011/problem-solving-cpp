#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<int> par;

int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    par[max(x, y)] = min(x, y);
}

void solve() {
    cin >> N;
    par = vector<int>(N + 1);

    priority_queue<PII> pq;
    int d, c;
    for (int i = 1; i <= N;i++){
        par[i] = i;

        cin >> d >> c;
        pq.push({c, d});
    }



    int ans = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int x = find(p.second);
        if(x){
            ans += p.first;
            int y = find(x - 1);
            merge(x, y);
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