#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

bool noBlind(char A, char B) {
	return A == B;
}

bool blind(char A, char B) {
	return (A == B || (A != 'B' && B != 'B'));
}

int solve(vector<string>& graph, int N, bool (*cmp)(char, char)) {
	bool visited[101][101] = { 0, };
	int res = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				res++;
				queue<pair<int, int>> Q;
				
				visited[i][j] = 1;
				Q.push({ i,j });

				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();

					int cr = cur.first, cc = cur.second;

					for (int i = 0; i < 4; i++) {
						int nr = cr + dir[i][0], nc = cc + dir[i][1];
						if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

						if (!visited[nr][nc] && cmp(graph[cr][cc], graph[nr][nc])) {
							visited[nr][nc] = 1;
							Q.push({ nr,nc });
						}
					}
				}
			}
		}
	}

	return res;
}

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<string> graph(N);
	for (int i = 0; i < N; i++)
		cin >> graph[i];

	cout << solve(graph, N, noBlind) << ' ' << solve(graph, N, blind) << endl;
}