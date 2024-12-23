#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, cnt;
int visited[100001];
vector<vector<int>> graph;
vector<int> ans;

int dfs(int cur, int prv){
    visited[cur] = cnt++;

    int ret = 100002, child = 0;
    bool flag = false;
    for(int nxt : graph[cur]){
        if(visited[nxt] < 0){
            child++;
            int res = dfs(nxt, cur);
            if(prv && res >= visited[cur])
                flag = true;
            ret = min(ret, res);
        }
        
        else
            //무향 그래프에서는 교차 간선이 존재하지 않는다.
            //다시 말해 v를 이미 방문했으면 방문 순서의 대소에 따라
            //순방향, 역방향 간선으로 나뉜다.
            //순방향일 경우 v의 방문 순서가 더 크므로 min에 의해 걸러지며,
            //역방향일 경우 그 중 가장 순서가 작은 값을 저장해 반환한다.
            ret = min(ret, visited[nxt]);
    }

    if((prv == 0 && child >= 2) || flag)
        ans.push_back(cur);

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
    for(int x : ans)
        cout << x << ' ';
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}