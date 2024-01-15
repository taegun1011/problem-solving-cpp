#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e9

int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int h, w;

vector<string> graph;
bool visited[51][51][1 << 6];
int dist[51][51][1 << 6];

bool inRange(int num, int lim) {
	return 0 <= num && num < lim;
}

int BFS(PII start, PII end) {
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));

	queue<pair<PII, int>> Q;
	Q.push({ start, 0 });

	while (!Q.empty()) {
		auto [cur, cur_key] = Q.front();
		auto [cur_row, cur_col] = cur;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nxt_row = cur_row + dir[i][0];
			int nxt_col = cur_col + dir[i][1];
			int nxt_key = cur_key;

			if (!inRange(nxt_row, h) || !inRange(nxt_col, w)) continue;

			if (nxt_row == end.first && nxt_col == end.second) {
				return dist[nxt_row][nxt_col][cur_key] = dist[cur_row][cur_col][cur_key] + 1;
			}

			if (visited[nxt_row][nxt_col][cur_key]) continue;

			char temp;
			if ((temp = graph[nxt_row][nxt_col]) == '#') continue;
			
			//문
			if (isupper(temp)) {

				//이동 불가능
				if (!(cur_key & (1 << (temp - 'A'))))
					continue;
			}

			//열쇠
			if (islower(temp))
				nxt_key |= (1 << (temp - 'a'));

			visited[nxt_row][nxt_col][nxt_key] = 1;
			dist[nxt_row][nxt_col][nxt_key] = dist[cur_row][cur_col][cur_key] + 1;
			Q.push({ {nxt_row, nxt_col}, nxt_key });
		}
	}

	return INF;
}

void solve() {
	cin >> h >> w;

	graph.resize(h);
	
	PII s;
	vector<PII> end;
	for (int i = 0; i < h; i++) {
		cin >> graph[i];
		for (int j = 0; j < w; j++) {
			if (graph[i][j] == '0')
				s = { i,j };
			if (graph[i][j] == '1')
				end.push_back({ i,j });
		}
	}

	int res = INF;
	for (auto e : end)
		res = min(res, BFS(s, e));

	cout << (res == INF ? -1 : res) << endl;
}

int main() {
	FASTIO;

	int TC = 1;
	while (TC) {
		TC--;
		solve();
	}
}

//비트마스킹을 이용해 열쇠의 보유 상태를 확장한다