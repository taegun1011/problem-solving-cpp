#define MAX_N 350

#include <vector>
#include <queue>

using namespace std;

int board[MAX_N][MAX_N];
vector<vector<pair<int, int>>> graph;
int sz, lim;

void init(int N, int mRange, int mMap[MAX_N][MAX_N])
{
	sz = N;
	lim = mRange;
	for (int i = 0;i < MAX_N;i++)
		for (int j = 0;j < MAX_N;j++)
			board[i][j] = mMap[i][j];

	graph = vector<vector<pair<int, int>>>();
	return;
}

struct Tuple {
	int r;
	int c;
	int d;
};

int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void bfs(int u, int sr, int sc) {
	vector<vector<bool>> visited(sz, vector<bool>(sz));
	visited[sr][sc] = true;

	queue<Tuple> Q;
	Q.push({ sr, sc, 0 });

	while (!Q.empty()) {
		Tuple t = Q.front();
		Q.pop();

		int cr = t.r, cc = t.c, cd = t.d;
		if (cd >= lim)
			break;

		for (int i = 0;i < 4;i++) {
			int nr = dir[i][0] + cr, nc = dir[i][1] + cc, nd = cd + 1;
			if (nr < 0 || nr >= sz || nc < 0 || nc >= sz || board[nr][nc] == 1 || visited[nr][nc])
				continue;
			visited[nr][nc] = true;
			Q.push({ nr, nc, nd });
			if (board[nr][nc] >= 2) {
				int v = board[nr][nc] - 2;
				graph[u].push_back({ v, nd });
				graph[v].push_back({ u, nd });
			}
		}
	}
}

void add(int mID, int mRow, int mCol)
{
	graph.push_back(vector<pair<int, int>>());
	board[mRow][mCol] = mID + 2;
	bfs(mID, mRow, mCol);
	return;
}

int distance(int mFrom, int mTo)
{
	int N = graph.size();
	vector<int> dist(N, 1e9);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[mFrom] = 0, mFrom });

	while (!pq.empty()) {
		pair<int, int> pt = pq.top();
		pq.pop();

		int u = pt.second, w = pt.first;
		if (dist[u] != w)
			continue;

		if (u == mTo)
			break;

		for (auto p : graph[u]) {
			int v = p.first, uv = p.second;

			if (dist[v] > uv + w)
				pq.push({ dist[v] = uv + w, v});
		}
	}

	return dist[mTo] == 1e9 ? -1 : dist[mTo];
}