#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
string a;
ll ans;

ll dfs(int cur, int prv){
    visited[cur] = true;
    ll ret = 0;
    for(int nxt : graph[cur]){
        if(nxt == prv)
            continue;
        if(a[nxt] - '0')
            ret++;
        else
            ret += dfs(nxt, cur);
    }
    return ret;
}

void solve() {
    cin >> N;
    graph = vector<vector<int>>(N, vector<int>());
    visited = vector<bool>(N);
    cin >> a;
    int u, v;
    for(int i=0;i<N-1;i++){
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    for(int i=0;i<N;i++){
        if(a[i] - '0') {
            for(int nxt : graph[i])
                ans += a[nxt] - '0';
        }
        else if (!visited[i]) {
            ll ret = dfs(i, -1);
            ans += ret * ret - ret;
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