#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

vector<vector<int>> graph;
vector<vector<int>> dist;

void bfs(int sr, int sc){
    vector<vector<bool>> visited(N, vector<bool>(N));
    visited[sr][sc] = true;

    queue<pair<PII, int>> Q;
    Q.push({{sr, sc}, 0});

    while(!Q.empty()){
        auto p = Q.front();
        Q.pop();

        int cr = p.first.first, cc = p.first.second, cd = p.second;
        for (int i = 0; i < 4;i++){
            int nr = cr + dir[i][0], nc = cc + dir[i][1], nd = cd + 1;
            if(nr < 0 || nr >= N || nc < 0 || nc >= N || graph[nr][nc] == 1 || visited[nr][nc])
                continue;
            visited[nr][nc] = true;
            if(graph[nr][nc] > 1)
                dist[graph[sr][sc] - 2][graph[nr][nc] - 2] = nd;
            Q.push({{nr, nc}, nd});
        }
    }
}

int prim() {
    vector<bool> visited(M + 1);

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 0});

    int cnt = 0, ret = 0;
    while(!pq.empty() && cnt <= M){
        auto nxt = pq.top();
        pq.pop();

        int u = nxt.second, w = nxt.first;

        if(visited[u])
            continue;
        
        visited[u] = true;
        cnt++;
        ret += w;
        for (int v = 0; v <= M; v++)
            if(dist[u][v] != INF)
                pq.push({dist[u][v], v});
        
    }

    return cnt == M + 1 ? ret : -1;
}

void solve() {
    cin >> N >> M;
    graph = vector<vector<int>>(N, vector<int>(N));
    dist = vector<vector<int>>(M + 1, vector<int>(M + 1, INF));
    int idx = 2;
    for (int i = 0; i < N;i++){
        string str;
        cin >> str;
        for (int j = 0; j < N;j++)
            graph[i][j] = (str[j] == '0' || str[j] == '1') ? str[j] - '0' : idx++;
        
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (graph[i][j] >= 2)
                bfs(i, j);

    cout << prim() << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}