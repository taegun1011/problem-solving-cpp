#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define LOG 17

int N, M;

int arr[100001], up[100001][LOG], len[100001][LOG];
vector<PII> graph[100001];

void dfs(int cur, int prv, int l){
    up[cur][0] = prv;
    len[cur][0] = l;

    for(auto p : graph[cur])
        if(p.first != prv)
            dfs(p.first, cur, p.second);
}

int calc(int a, int b){
    for (int i = LOG - 1; i >= 0;i--){
        if(b >= len[a][i]){
            b -= len[a][i];
            a = up[a][i];
        }
    }

    return a;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N;i++)
        cin >> arr[i];
    int u, v, w;
    for (int i = 0; i < N - 1;i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs(1, 1, 0);

    for (int j = 1; j < LOG;j++){
        for (int i = 1; i <= N;i++){
            up[i][j] = up[up[i][j - 1]][j - 1];
            len[i][j] = len[i][j - 1] + len[up[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= N; i++)
        cout << calc(i, arr[i]) << '\n';
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}