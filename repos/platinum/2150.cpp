#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int cnt = 1;
bool visited[10001];
int order[10001];
vector<vector<int>> graph, graph_rev, ans;

bool comp(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}

void dfs1(int cur){
    visited[cur] = true;

    for (int nxt : graph[cur])
        if(!visited[nxt])
            dfs1(nxt);

    order[cnt++] = cur;
}

void dfs2(int cur, int idx){
    visited[cur] = true;
    ans[idx].push_back(cur);

    for(int nxt : graph_rev[cur])
        if(!visited[nxt])
            dfs2(nxt, idx);
}

void solve() {
    cin >> N >> M;
    graph = vector<vector<int>>(N + 1, vector<int>());
    graph_rev = vector<vector<int>>(N + 1, vector<int>());

    int u, v;
    while(M--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph_rev[v].push_back(u);
    }

    for (int i = 1; i <= N;i++)
        if(!visited[i])
            dfs1(i);

    memset(visited, 0, sizeof(visited));
    for (int i = N; i >= 1;i--)
        if(!visited[order[i]]){
            ans.push_back(vector<int>());
            dfs2(order[i], ans.size() - 1);
        }

    for(auto& v : ans)
        sort(v.begin(), v.end());

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end(), comp);
    for(const auto& v : ans){
        for(int x : v)
            cout << x << ' ';
        cout << -1 << '\n';
    }

}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}