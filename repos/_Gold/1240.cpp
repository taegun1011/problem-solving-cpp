#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M;

vector<vector<PII>> graph;

int bfs(int s, int e){
    vector<int> dist(N, INF);
    dist[s] = 0;
    queue<int> Q;
    Q.push({s});

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        if(cur == e)
            break;
        
        for(auto p : graph[cur]){
            if(dist[p.first] > dist[cur] + p.second){
                dist[p.first] = dist[cur] + p.second;
                Q.push({p.first});
            }
        }
    }

    return dist[e];
}

void solve() {
    cin >> N >> M;
    graph = vector<vector<PII>>(N, vector<PII>());
    int u, v, w;
    for (int i = 0; i < N - 1;i++){
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }

    while(M--){
        cin >> u >> v;
        cout << bfs(u - 1, v - 1) << '\n';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}