#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N;
set<int> graph[100001];
vector<int> v;

int visited[100001];
bool connected(int a, int b) {
	return graph[a].find(b) != graph[a].end();
}

//v에 저장된 대로 BFS가 가능한지 시도
bool solve() {
	queue<int> Q;
	Q.push(1);
	visited[1] = 1;

	int cur, pos = 1;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		//cur와 연결된 정점 중 방문하지 않은 정점을 모두 넣는다
		while (pos < N) {
			if (connected(cur, v[pos]) && !visited[v[pos]]) {
				visited[v[pos]] = 1;
				Q.push(v[pos++]);
			}
			else
				break;
		}
	}

	return pos == N ? 1 : 0;
}

int main() {
	FASTIO;

	cin >> N;

	int U, V;
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		graph[U].insert(V);
		graph[V].insert(U);
	}

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	cout << solve() << endl;
}