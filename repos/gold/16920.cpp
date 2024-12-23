#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int S[10];
int N, M, P;

int BFS(queue<pair<int, int>>& src, int num, vector<string>& graph) {
	queue<tuple<int, int, int>> Q;
	int ret = 0, maxMov = S[num];

	while (!src.empty()) {
		auto cur = src.front();
		src.pop();
		ret++;

		Q.push({ cur.first, cur.second, 0 });
	}

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = get<0>(cur), cc = get<1>(cur), cm = get<2>(cur);
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1], nm = cm + 1;
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || cm == maxMov) continue;

			if (graph[nr][nc] == '.') {
				graph[nr][nc] = '0' + num;
				ret++;
				Q.push({ nr,nc,nm });

				if (nm == maxMov)
					src.push({ nr,nc });
			}
		}
	}

	return ret;
}

int main() {
	FASTIO;

	cin >> N >> M >> P;

	for (int i = 1; i <= P; i++)
		cin >> S[i];

	vector<string> graph(N);
	for (int i = 0; i < N; i++)
		cin >> graph[i];

	queue<pair<int, int>> Q[10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp = graph[i][j];
			if (temp > '0' && temp <= '9')
				Q[temp - '0'].push({ i,j });
		}
	}

	int inc;
	do {
		inc = 0;
		for (int i = 1; i <= P; i++)
			inc += BFS(Q[i], i, graph);
	} while (inc);

	vector<int> sum(P);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp = graph[i][j];
			if (temp > '0' && temp <= '9')
				sum[temp - '1']++;
		}
	}

	for (int i : sum)
		cout << i << ' ';
}