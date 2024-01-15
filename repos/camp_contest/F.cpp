#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
vector<vector<int>> graph(501, vector<int>(501));
vector<int> adj_list[501];

int DFS(int center) {
	//i와 인접하고 서로 연결된 j, k를 고른다
	//j, k와 서로 다르며 i와 인접하고 서로 연결된 l, m을 고른다

	int ret = 0;

	//j를 선택
	for (int j : adj_list[center]) {

		//j와 인접한 k를 선택
		for (int k : adj_list[j]) {
			if (k < j) continue;
			if (graph[k][center])

				//l을 선택
				for (int l : adj_list[center]) {
					if (l <= k) continue;

					//l과 인접한 m을 선택
					for (int m : adj_list[l]) {
						if (m < l) continue;

						if (graph[m][center]) {
							ret++;
						}
					}
				}
		}
	}
	

	return ret;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	//c를 기준으로
	//graph[i].size() >= 6 인 i에 대해
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (adj_list[i].size() >= 6) {

			//날개 2개를 고르는 경우의 수
			int wings = DFS(i);

			//나머지 간선에서 더듬이 2개를 고르는 경우의 수
			int dudms = (adj_list[i].size() - 4) * (adj_list[i].size() - 5) / 2;
			cnt += wings * dudms;
		}
	}

	cout << cnt << endl;
}