#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N;

void DFS(vector<short>& cycle, vector<int>& graph, int start) {
	stack<int> S;

	vector<bool> visited(N + 1);
	int cur = start;

	while (!cycle[cur]) {
		S.push(cur);
		visited[cur] = 1;
		cur = graph[cur];

		if (visited[cur]) {
			while (!S.empty()){
				cycle[S.top()] = 1;
				S.pop();

				if (S.top() == cur) {
					cycle[S.top()] = 1;
					S.pop();
					break;
				}
			}
		}
	}

	while (!S.empty()) {
		cycle[S.top()] = -1;
		S.pop();
	}
}

void solve() {
	cin >> N;

	vector<int> graph(N + 1);
	vector<short> cycle(N + 1); //-1 : acyclic, 0 : ¹ÌÁ¤, 1 : cyclic

	graph[0] = -1;
	for (auto& i : graph)
		if (!i) cin >> i;

	for (int i = 1; i <= N; i++)
		if (graph[i] == i)
			cycle[i] = 1;

	for (int i = 1; i <= N; i++) {
		if (!cycle[i])
			DFS(cycle, graph, i);
	}

	cout << count(cycle.begin(), cycle.end(), -1) << endl;
}

int main() {
	FASTIO;

	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}