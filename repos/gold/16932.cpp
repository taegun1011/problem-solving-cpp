#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

vector<vector<int>> graph;
vector<vector<int>> visited;
int dfs(int cr, int cc, int idx){
    visited[cr][cc] = idx;

    int ret = 1;
    for (int i = 0; i < 4;i++){
        int nr = cr + dir[i][0];
        int nc = cc + dir[i][1];

        if(nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;
        if(graph[nr][nc] && !visited[nr][nc])
            ret += dfs(nr, nc, idx);
    }

    return ret;
}

void solve() {
    cin >> N >> M;
    graph = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<int>>(N, vector<int>(M));
    for(auto& row : graph)
        for(int& x : row)
            cin >> x;

    vector<int> arr;
    int idx = 1;
    for (int i = 0; i < N;i++)
        for (int j = 0; j < M;j++)
            if(graph[i][j] && !visited[i][j])
                arr.push_back(dfs(i, j, idx++));

    int ans = 0;
    for (int cr = 0; cr < N;cr++)
        for (int cc = 0; cc < M;cc++){
            if(graph[cr][cc])
                continue;

            int sum = 1;
            set<int> S;
            for (int i = 0; i < 4;i++){
                int nr = cr + dir[i][0];
                int nc = cc + dir[i][1];
                if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
                if(graph[nr][nc])
                    S.insert(visited[nr][nc]);
            }
            for(int idx : S)
                sum += arr[idx - 1];

            ans = max(ans, sum);
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