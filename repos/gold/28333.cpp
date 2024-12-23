#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];

//복귀 경로 탐색용
vector<int> rev_graph[1001];

bool visited[1001];
int dist[1001];

//1부터 N까지 BFS를 수행 후 최단경로를 반환
set<int> BFS(int N) {
	queue<int> Q;
	Q.push(1);
	visited[1] = 1;
	dist[1] = 1;
	
	set<int> res;

	int cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		//도착하면 역으로 BFS 수행
		if (cur == N) {
			queue<int> Q2;
			bool visited2[1001] = { 0, };

			Q2.push(cur);
			res.insert(cur);

			while (!Q2.empty()) {
				cur = Q2.front();
				Q2.pop();
				if (cur == 1)
					break;

				for (int next : rev_graph[cur]) {
					if (dist[next] == dist[cur] - 1 && !visited2[next]) {
						res.insert(next);
						Q2.push(next);
						visited2[next] = 1;
					}
				}
			}
		}

		for (int next : graph[cur]) {
			if (!visited[next]) {
				visited[next] = 1;
				dist[next] = dist[cur] + 1;
				Q.push(next);
			}
		}
	}

	return res;
}

void solve() {
	for (int i = 0; i < 1001; i++) {
		graph[i].clear();
		rev_graph[i].clear();
	}
	fill(visited, visited + 1001, 0);
	fill(dist, dist + 1001, 0);

	int N, M;
	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}

	for(int i : BFS(N))
		cout << i << ' ';
	cout << '\n';
}

int main() {
	int TC;
	cin >> TC;

	while (TC--)
		solve();
}

//dist[1] 초기화를 1로 해야했다...