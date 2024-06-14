#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

#define LOG 17

int N, M;
int depth[100001];
int up[100001][LOG];
vector<vector<int>> graph;

void dfs(int cur, int prv, int lv){
    depth[cur] = lv;
    up[cur][0] = prv;
    for(int nxt : graph[cur])
        if(nxt != prv)
            dfs(nxt, cur, lv + 1);
}

int lca(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = LOG - 1; i >= 0;i--)
        if(diff & (1 << i))
            a = up[a][i];

    if(a == b)
        return a;

    for (int i = LOG - 1; i >= 0;i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void solve() {
    cin >> N;
    graph = vector<vector<int>>(N + 1, vector<int>());
    int a, b;
    for (int i = 0; i < N - 1;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1, 0);

    for (int j = 1; j < LOG;j++)
        for (int i = 1; i <= N;i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    cin >> M;
    while(M--){
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}