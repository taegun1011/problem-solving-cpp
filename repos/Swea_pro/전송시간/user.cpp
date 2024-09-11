#include <queue>

using namespace std;

#define INF 1e9
#define PII pair<int, int>
int inner[301][31][31];
int outer[301][4][301][4];

//checkTime 결과를 캐싱
int cache[4][4];

int sz;

int inner_dijkstra(int group, int s, int e) {
	int dist[31];
	for (int i = 0;i <= 30;i++)
		dist[i] = INF;

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ dist[s] = 0, s });

	while (!pq.empty()) {
		PII p = pq.top();
		pq.pop();

		int w = p.first, u = p.second;
		if (dist[u] != w)
			continue;
		if (u == e)
			return w;

		for (int v = 1;v <= 30;v++) {
			int uv = inner[group][u][v];
			if (uv == INF)
				continue;
			if (dist[v] > dist[u] + uv)
				pq.push({ dist[v] = dist[u] + uv, v });
		}
	}

	return INF;
}

int outer_dijkstra(int s, int e) {
	//여기를 최적화해야지

	int dist[301][4];
	for (int i = 0;i <= sz;i++)
		for (int j = 1;j <= 3;j++)
			dist[i][j] = INF;

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ dist[0][s] = 0, s });
	while(!pq.empty()) {
		PII p = pq.top();
		pq.pop();

		int w = p.first, u = p.second;
		int ug = u / 100, un = u % 100;
		if (dist[ug][un] != w)
			continue;

		if (u == e)
			return w;

		//g(group), n(number)
		for (int vg = 0;vg <= sz;vg++) {
			for (int vn = 1;vn <= 3;vn++) {
				int uv = outer[ug][un][vg][vn];
				if (uv == INF)
					continue;
				if (dist[vg][vn] > dist[ug][un] + uv)
					pq.push({ dist[vg][vn] = dist[ug][un] + uv, vg * 100 + vn });
			}
		}
	}

	return INF;
}

void init(int N, int K, int mNodeA[], int mNodeB[], int mTime[])
{
	sz = N;

	//inner 초기화
	for (int i = 0;i <= sz;i++)
		for (int j = 0;j <= 30;j++)
			for (int k = 0;k <= 30;k++)
				inner[i][j][k] = INF;

	//outer 초기화
	for (int i = 0;i <= sz;i++)
		for (int j = 1;j <= 3;j++)
			for (int k = 0;k <= sz;k++)
				for (int l = 1;l <= 3;l++)
					outer[i][j][k][l] = INF;

	for (int i = 0;i < K;i++) {
		int u = mNodeA[i], v = mNodeB[i], w = mTime[i];
		int ug = u / 100, un = u % 100, vg = v / 100, vn = v % 100;

		//둘 다 대표 노드일 경우 outer를 갱신
		if (un <= 3 && vn <= 3) {
			outer[ug][un][vg][vn] = outer[vg][vn][ug][un] = w;
			//같은 그룹의 대표 노드일 경우 inner도 갱신
			if (ug == vg)	
				inner[ug][un][vn] = inner[vg][vn][un] = w;
		}
		//하나라도 대표 노드가 아닐 경우 inner만 갱신
		else
			inner[ug][un][vn] = inner[vg][vn][un] = w;
	}

	for (int i = 1;i <= sz;i++) {
		for (int j = 1;j <= 3;j++) {
			int u = j, v = j % 3 + 1;
			int dist = inner_dijkstra(i, u, v);
			outer[i][u][i][v] = outer[i][v][i][u] = dist;
		}
	}

	for (int i = 1;i <= 3;i++)
		for (int j = 1;j <= 3;j++)
			cache[i][j] = -1;
}

void addLine(int mNodeA, int mNodeB, int mTime)
{
	int u = mNodeA, v = mNodeB, w = mTime;
	int ug = u / 100, un = u % 100, vg = v / 100, vn = v % 100;

	bool isLineInner = false;

	if (un <= 3 && vn <= 3) {
		if (w == INF && outer[ug][un][vg][vn] == INF)
			return;
		outer[ug][un][vg][vn] = outer[vg][vn][ug][un] = w;
		if (ug == vg) {
			isLineInner = true;
			inner[ug][un][vn] = inner[vg][vn][un] = w;
		}
	}
	else {
		if (w == INF && inner[ug][un][vn] == INF)
			return;
		isLineInner = true;
		inner[ug][un][vn] = inner[vg][vn][un] = w;
	}

	if (isLineInner) {
		for (int i = 1;i <= 3;i++) {
			int u = i, v = i % 3 + 1;
			int dist = inner_dijkstra(ug, u, v);
			outer[ug][u][ug][v] = outer[ug][v][ug][u] = dist;
		}
	}

	for (int i = 1;i <= 3;i++)
		for (int j = 1;j <= 3;j++)
			cache[i][j] = -1;
}

void removeLine(int mNodeA, int mNodeB)
{
	addLine(mNodeA, mNodeB, INF);
}

int checkTime(int mNodeA, int mNodeB)
{
	if(cache[mNodeA][mNodeB] == -1)
		cache[mNodeA][mNodeB] = cache[mNodeB][mNodeA] = outer_dijkstra(mNodeA, mNodeB);
	return cache[mNodeA][mNodeB];
}