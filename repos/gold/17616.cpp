#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> higher[100001], lower[100001];
bool visited[100001];
enum {high = 1, low};

int DFS(int node, int type) {
	int ret = 1;
	visited[node] = 1;

	//node를 하위에 둔 그래프에서 탐색
	if (type == high) {
		for (int next : lower[node]) {
			if (!visited[next])
				ret += DFS(next, type);
		}
	}
	else {
		for (int next : higher[node]) {
			if (!visited[next])
				ret += DFS(next, type);
		}

	}

	return ret;
}



int main() {
	FASTIO;
	int N, M, X;
	cin >> N >> M >> X;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		//higher : u가 v보다 높다
		//lower : u가 v보다 낮다
		higher[u].push_back(v);
		lower[v].push_back(u);
	}

	int highest = DFS(X, high);

	memset(visited, 0, sizeof(visited));
	int lowest = N - DFS(X, low) + 1;

	cout << highest << ' ' << lowest << endl;

	//최저 등수 : N - DFS_lower
	//최고 등수 : DFS_higher + 1
}

//컴포넌트 크기를 구하려면 ret = 1로 초기화해야함