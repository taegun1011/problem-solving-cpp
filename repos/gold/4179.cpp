#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int fdist[1001][1001];
int jdist[1001][1001];
short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;

	vector<string> graph(N);
	for (int i = 0; i < N; i++)
		cin >> graph[i];

	queue<pair<int, int>> Q;

	int jr, jc;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M;j++) {
			if (graph[i][j] == 'F') {
				Q.push({ i,j });
			}
			else if (graph[i][j] == 'J')
				jr = i, jc = j;
		}
	}

	//불 도달 시간 기록
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if ((graph[nr][nc] == '.' || graph[nr][nc] == 'J') && !fdist[nr][nc]) {
				fdist[nr][nc] = fdist[cr][cc] + 1;
				Q.push({ nr,nc });
			}
		}
	}

	Q.push({ jr,jc });

	int time = INT_MAX;
	//지훈 도달 시간 기록
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int cr = cur.first, cc = cur.second;

		if (cr == 0 || cr == N - 1 || cc == 0 || cc == M - 1) {
			time = min(time, jdist[cr][cc]);
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (graph[nr][nc] == '.' && !jdist[nr][nc]) {
				if (fdist[nr][nc] && jdist[cr][cc] + 1 >= fdist[nr][nc]) continue;

				jdist[nr][nc] = jdist[cr][cc] + 1;
				Q.push({ nr,nc });
			}
		}
	}

	if (time == INT_MAX)
		cout << "IMPOSSIBLE\n";
	else
		cout << time + 1 << endl;
}