#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, cnt;

int order[200001];
bool visited[200001];
vector<vector<int>> graph, graph_rev;

void dfs1(int cur){
    visited[cur] = true;
    for(int nxt : graph[cur])
        if(!visited[nxt])
            dfs1(nxt);
    order[cnt++] = cur;
}

void dfs2(int cur){
    visited[cur] = true;
    for(int nxt : graph_rev[cur])
        if(!visited[nxt])
            dfs2(nxt);
}

void solve() {
    cin >> N >> M;
    graph = vector<vector<int>>(N, vector<int>());
    graph_rev = vector<vector<int>>(N, vector<int>());

    int u, v;
    while(M--){
        cin >> u >> v;
        graph[--u].push_back(--v);
        graph_rev[v].push_back(u);
    }

    for (int i = 0; i < N;i++)
        if(!visited[i])
            dfs1(i);

    memset(visited, 0, sizeof(visited));
    int ans = 0;
    for (int i = N - 1; i >= 0;i--)
        if(!visited[order[i]]){
            dfs2(order[i]);
            ans++;
        }

    cout << (ans == 1 ? "Yes" : "No") << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}