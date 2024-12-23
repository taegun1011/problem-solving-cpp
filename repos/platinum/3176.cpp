#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
int mn[100001][17], mx[100001][17], up[100001][17], dep[100001];
vector<PII> graph[100001];

void dfs(PII cur, int prv, int d){
    int v = cur.first, w = cur.second;

    up[v][0] = prv;
    mn[v][0] = mx[v][0] = w;
    dep[v] = d;
    for(PII nxt : graph[v]) {
        if(nxt.first == prv)
            continue;
        dfs(nxt, v, d + 1);
    }
}

void lca(int a, int b){
    if(dep[a] < dep[b])
        swap(a, b);

    int ans_min = INT_MAX, ans_max = 0;
    int diff = dep[a] - dep[b];
    for (int i = 16; i >= 0;i--)
        if(diff & (1 << i)){
            ans_min = min(ans_min, mn[a][i]);
            ans_max = max(ans_max, mx[a][i]);
            a = up[a][i];
        }
    
    if(a != b) {
        for (int i = 16; i >= 0;i--){
            if(up[a][i] != up[b][i]){
                ans_min = min(ans_min, min(mn[a][i], mn[b][i]));
                ans_max = max(ans_max, max(mx[a][i], mx[b][i]));
                a = up[a][i];
                b = up[b][i];
            }
        }
        if(a != 1){
            ans_min = min(ans_min, min(mn[a][0], mn[b][0]));
            ans_max = max(ans_max, max(mx[a][0], mx[b][0]));
        }
    }


    cout << ans_min << ' ' << ans_max << '\n';
}

void solve()
{
    cin >> N;
    int u, v, w;
    for (int i = 0; i < N - 1;i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs({1, 0}, 1, 1);

    up[1][0] = 1;
    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= N; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
            mn[i][j] = min(mn[i][j - 1], mn[up[i][j - 1]][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[up[i][j - 1]][j - 1]);
        }
    }

    cin >> M;
    while(M--){
        cin >> u >> v;
        lca(u, v);
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}