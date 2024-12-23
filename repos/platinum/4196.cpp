#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<vector<int>> graph, graph_rev;
bool visited[100001];
int order[100001], in_deg[100001], cnt = 0;

void dfs(int cur, int type){
    visited[cur] = true;

    const auto& g = !type ? graph : graph_rev;
    for(int nxt : graph[cur])
        if(!visited[nxt])
            dfs(nxt, type);

    if(!type)
        order[cnt++] = cur;
}

void solve() {
    memset(visited, 0, sizeof(visited));
    memset(order, 0, sizeof(order));
    memset(in_deg, 0, sizeof(in_deg));
    cnt = 0;

    cin >> N >> M;
    graph = vector<vector<int>> (N, vector<int>());
    graph_rev = vector<vector<int>> (N, vector<int>());

    int u, v;
    while(M--){
        cin >> u >> v;
        graph[--u].push_back(--v);
        graph_rev[v].push_back(u);
        in_deg[v]++;
    }

    queue<int> Q;
    for (int i = 0; i < N;i++){
        if(!visited[i])
            dfs(i, 0);
        if(!in_deg[i])
            Q.push(i);
    }

    memset(visited, 0, sizeof(visited));

    int ans = 0;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        ans++;
        dfs(cur, 1);
    }
    for (int i = N - 1; i >= 0;i--)
        if(!visited[order[i]]){
            ans++;
            dfs(order[i], 1);
        }

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}