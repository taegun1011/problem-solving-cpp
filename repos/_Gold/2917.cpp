#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M;
vector<vector<int>> dist;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void bfs(queue<PII>& Q){
    while(!Q.empty()){
        PII p = Q.front();
        Q.pop();

        int cr = p.first, cc = p.second;
        for (int i = 0; i < 4;i++){
            int nr = dir[i][0] + cr, nc = dir[i][1] + cc;
            if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            if(dist[nr][nc] > dist[cr][cc] + 1){
                dist[nr][nc] = dist[cr][cc] + 1;
                Q.push({nr, nc});
            }
        }
    }
}

int dijkstra(int sr, int sc, vector<string>& graph){
    vector<vector<bool>> visited(N, vector<bool>(M));

    int ret;

    priority_queue<pair<int, PII>> pq;
    pq.push({ret = dist[sr][sc], {sr, sc}});
    
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int cd = p.first, cr = p.second.first, cc = p.second.second;

        if(visited[cr][cc])
            continue;

        ret = min(ret, cd);
        if(graph[cr][cc] == 'J')
            break;

        for (int i = 0; i < 4;i++){
            int nr = dir[i][0] + cr, nc = dir[i][1] + cc;
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc])
                continue;
            pq.push({dist[nr][nc], {nr, nc}});
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M;
    vector<string> graph(N);
    dist = vector<vector<int>>(N, vector<int>(M, INF));
    
    for(auto& row : graph)
        cin >> row;

    queue<PII> Q;
    int sr = 0, sc = 0, er = 0, ec = 0;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++) {
            if(graph[i][j] == '+'){
                Q.push({i, j});
                dist[i][j] = 0;
            }
            else if(graph[i][j] == 'V'){
                sr = i;
                sc = j;
            }
            else if(graph[i][j] == 'J'){
                er = i;
                ec = j;
            }
        }
    }

    bfs(Q);
    cout << dijkstra(sr, sc, graph) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}