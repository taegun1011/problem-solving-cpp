#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000
#define PII pair<int, int>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

vector<PII> graph[MAX+1];
vector<int> visited(MAX+1);
int V;
int tail;
int diameter;

void solve();
void DFS(int node, int dist);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V;

	int src, dest, cost;
	for (int i = 0; i < V; i++) {
		cin >> src;
		cin >> dest;
		while (dest != -1) {
			cin >> cost;
			graph[src].emplace_back(dest, cost);
			cin >> dest;
		}
	}
	solve();
}

void solve() {
	//1번 노드에서 가장 멀리 떨어진 노드 선택
	DFS(1, 0);

	fill(visited.begin(), visited.end(), 0);
	diameter = 0;

	DFS(tail, 0);
	cout << diameter << endl;
}

void DFS(int node, int dist) {
	visited[node] = 1;

	if (diameter < dist) {
		diameter = dist;
		tail = node;
	}

	PII next;
	for (auto next : graph[node]) {
		if (!visited[next.first]) {
			DFS(next.first, dist + next.second);
		}
	}

}