#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 2e6

int N;

void BFS(int s, int e, vector<vector<int>>& graph) {
	vector<bool> visited(N + 1);
	visited[s] = 1;

	queue<int> Q;
	Q.push(s);

	vector<int> path(N + 1);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == e)
			break;

		for (int nxt : graph[cur]) {
			if (!visited[nxt]) {
				visited[nxt] = 1;
				path[nxt] = cur;
				Q.push(nxt);
			}
		}
	}

	//항상 경로가 존재함이 보장된다
	stack<int> ans;
	int cur = e;
	while (cur != s) {
		ans.push(cur);
		cur = path[cur];
	}
	ans.push(cur);

	cout << ans.size() << endl;
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
		cout << (ans.empty() ? '\n' : ' ');
	}
}

void solve() {
	cin >> N;

	vector<PII> arr;
	arr.push_back({ -INF, 0 });
	arr.push_back({ INF, 0 });
	
	int k, x, r;
	for (int i = 0; i < N; i++) {
		cin >> k >> x >> r;
		arr.push_back({ x - r, k });
		arr.push_back({ x + r, k });
	}

	sort(arr.begin(), arr.end());
	vector<vector<int>> graph(N + 1, vector<int>());

	//트리 구조 생성
	stack<int> S;
	for (auto p : arr) {
		int v = p.second;
		if (!S.empty() && S.top() == v) {
			S.pop();
			if (!S.empty()) {
				int u = S.top();
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}
		else
			S.push(v);
	}

	int A, B;
	cin >> A >> B;

	BFS(A, B, graph);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}