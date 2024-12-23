#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M;
vector<vector<int>> dist;
vector<string> graph;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int bfs(int sr, int sc) {
    dist = vector<vector<int>>(N, vector<int>(M, INF));
    int ret = dist[sr][sc] = 0;

    queue<PII> Q;
    Q.push({sr, sc});
    while(!Q.empty()){
        PII p = Q.front();
        Q.pop();

        int cr = p.first, cc = p.second;
        ret = max(ret, dist[cr][cc]);

        for (int i = 0; i < 4;i++){
            int nr = dir[i][0] + cr, nc = dir[i][1] + cc;
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || graph[nr][nc] == 'W')
                continue;
            if(dist[nr][nc] > dist[cr][cc] + 1){
                dist[nr][nc] = dist[cr][cc] + 1;
                Q.push({nr, nc});
            }
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M;
    graph = vector<string>(N);
    for(string& row : graph)
        cin >> row;

    int ans = 0;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++){
            if(graph[i][j] == 'L')
                ans = max(ans, bfs(i, j));
        }
    }

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}