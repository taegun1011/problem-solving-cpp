#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define MAX 40000
#define LOG 16

int N, M;
int up[MAX][LOG];
int dist[MAX][LOG];
int depth[MAX];
vector<vector<PII>> graph;

void dfs(int cur, int prv, int d){
    depth[cur] = depth[prv] + 1;
    up[cur][0] = prv;
    dist[cur][0] = d;

    for(PII nxt : graph[cur]){
        if(nxt.first == prv)
            continue;
        dfs(nxt.first, cur, nxt.second);
    }
}

int calc(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    int diff = depth[a] - depth[b];
    int ret = 0;
    for (int i = LOG - 1; i >= 0;i--){
        if(diff & (1 << i)){
            ret += dist[a][i];
            a = up[a][i];
        }
    }

    if(a == b)
        return ret;

    for (int i = LOG - 1; i >= 0;i--){
        if(up[a][i] != up[b][i]){
            ret += dist[a][i];
            a = up[a][i];
            ret += dist[b][i];
            b = up[b][i];
        }
    }

    return ret + dist[a][0] + dist[b][0];
}

void solve() {
    cin >> N;
    graph = vector<vector<PII>>(N, vector<PII>());

    int u, v, w;
    for (int i = 0; i < N - 1;i++){
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }

    dfs(0, 0, 0);
    for (int j = 1; j < LOG;j++){
        for (int i = 0; i < N;i++){
            up[i][j] = up[up[i][j - 1]][j - 1];
            dist[i][j] = dist[i][j - 1] + dist[up[i][j - 1]][j - 1];
        }
    }

    cin >> M;
    while(M--){
        cin >> u >> v;
        cout << calc(u - 1, v - 1) << '\n';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}