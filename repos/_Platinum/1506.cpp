#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, cnt;

vector<int> cost, order;
vector<bool> visited;
vector<string> graph;

void dfs1(int cur){
    visited[cur] = true;

    for (int nxt = 0; nxt < N; nxt++) 
        if(graph[cur][nxt] - '0' && !visited[nxt])
            dfs1(nxt);

    order[cnt++] = cur;
}

int dfs2(int cur){
    visited[cur] = true;

    int ret = cost[cur];
    for (int nxt = 0; nxt < N;nxt++)
        if(graph[nxt][cur] - '0' && !visited[nxt])
            ret = min(ret, dfs2(nxt));

    return ret;
}

void solve() {
    cin >> N;
    cost = vector<int>(N);
    order = vector<int>(N);
    visited = vector<bool>(N);
    graph = vector<string>(N);
    for(int& x : cost)
        cin >> x;
    for(auto& row : graph)
        cin >> row;

    for (int i = 0; i < N;i++)
        if(!visited[i])
            dfs1(i);
    visited = vector<bool>(N);

    int ans = 0;
    for (int i = N - 1; i >= 0;i--)
        if(!visited[order[i]])
            ans += dfs2(order[i]);

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}