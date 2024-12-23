#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;
vector<vector<int>> graph;
int dp[100001][2];

int re_dp(int cur, int prv, int used) {
    if(dp[cur][used] != -1)
        return dp[cur][used];

    int& ret = dp[cur][used] = used;

    for(int nxt : graph[cur]){
        if(nxt == prv)
            continue;
        if(used)
            ret += min(re_dp(nxt, cur, 1), re_dp(nxt, cur, 0));
        else
            ret += re_dp(nxt, cur, 1);
    }

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    graph = vector<vector<int>>(N, vector<int>());

    int u, v;
    for (int i = 0; i < N - 1;i++){
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    cout << min(re_dp(0, 0, 0), re_dp(0, 0, 1)) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}