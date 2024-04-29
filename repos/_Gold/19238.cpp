#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 987654321

vector<vector<int>> board;
vector<bool> visited;
vector<PII> dst;

int N;
int dir[4][2] = { -1,0,0,-1,1,0,0,1 };

//ÁÂÇ¥, °Å¸®
pair<PII, int> find_src(PII s) {
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
	dist[s.first][s.second] = 0;

	queue<PII> Q;
	Q.push(s);

	int mn = INF;
	vector<PII> arr;

	while (!Q.empty()) {
		PII cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		int cn = board[cr][cc];
		if (cn && !visited[cn]) {
			if (dist[cr][cc] < mn) {
				arr = vector<PII>();
				arr.push_back({ cr,cc });
				mn = dist[cr][cc];
			}
			else if (dist[cr][cc] == mn)
				arr.push_back({ cr,cc });
		}

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];

			if (nr <= 0 || nr > N || nc <= 0 || nc > N || board[nr][nc] < 0)
				continue;

			if (dist[nr][nc] > dist[cr][cc] + 1) {
				dist[nr][nc] = dist[cr][cc] + 1;
				Q.push({ nr, nc });
			}
		}
	}

	PII ret = { INF, INF };
	for (PII p : arr)
		ret = min(ret, p);
	return { ret,mn };
}

int find_dst(PII s, PII e) {
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
	dist[s.first][s.second] = 0;

	queue<PII> Q;
	Q.push(s);

	while (!Q.empty()) {
		PII cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		if (cr == e.first && cc == e.second)
			return dist[cr][cc];

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];

			if (nr <= 0 || nr > N || nc <= 0 || nc > N || board[nr][nc] < 0)
				continue;

			if (dist[nr][nc] > dist[cr][cc] + 1) {
				dist[nr][nc] = dist[cr][cc] + 1;
				Q.push({ nr, nc });
			}
		}
	}

	return INF;
}

void solve() {
	int M, K;
	cin >> N >> M >> K;

	board = vector<vector<int>>(N + 1, vector<int>(N + 1));
	visited = vector<bool>(M + 1);
	dst = vector<PII>(M + 1);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j])
				board[i][j] *= -1;
		}

	PII cur;
	cin >> cur.first >> cur.second;

	for (int i = 1; i <= M; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = i;
		cin >> dst[i].first >> dst[i].second;
	}

	while (M) {
		auto nxt = find_src(cur);

		if (K < nxt.second)
			break;

		K -= nxt.second;
		cur = nxt.first;
		int no = board[cur.first][cur.second];

		int dist = find_dst(cur, dst[no]);
		if (K < dist)
			break;

		K += dist;
		cur = dst[no];
		visited[no] = true;
		M--;
	}

	cout << (M ? -1 : K) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}