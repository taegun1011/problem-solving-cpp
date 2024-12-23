#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, cnt;

int visited[100001];
vector<PII> ans;
vector<vector<int>> graph;

int dfs(int cur, int prv){
    visited[cur] = cnt++;

    int ret = 100001;
    for(int nxt : graph[cur]){
        if(nxt == prv)
            continue;
    
        if(visited[nxt] < 0){
            int res = dfs(nxt, cur);
            if(res > visited[cur])
                ans.push_back(minmax({cur, nxt}));
            ret = min(ret, res);
        }
        else
            ret = min(ret, visited[nxt]);
    }

    return ret;
}

void solve() {
    memset(visited, -1, sizeof(visited));
    cin >> N >> M;
    graph = vector<vector<int>>(N + 1, vector<int>());
    int u, v;
    while(M--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N;i++)
        if(visited[i] < 0)
            dfs(i, 0);

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto p : ans)
        cout << p.first << ' ' << p.second << '\n';
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}