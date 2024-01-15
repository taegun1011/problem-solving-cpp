#define _CRT_SECURE_NO_WARNINGS
#define PII pair<int, int>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<PII> graph[1001];
vector<int> to(1001); //X번 마을에서 각 마을까지

class Compare {
public:
	bool operator()(PII a, PII b) {
		if (a.second > b.second) {
			return true;
		}
		return false;
	}
};

void solve(int target);
int dijkstra(int start, int target);

int V;

int main() {
	int E, target;
	cin >> V >> E >> target;

	int u, v, w;
	while (E > 0) {
		E--;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}
	solve(target);
}

void solve(int target) {
	vector<int> from(V + 1); //각 마을에서 X번 마을까지

	for (int i = 1; i <= V; i++) {
		from[i] = (i == target ? 0 : dijkstra(i, target));
		fill(to.begin(), to.end(), -1);
	}

	dijkstra(target, 0);

	int max = 0;
	for (int i = 1; i <= V; i++) {
		if (max < from[i] + to[i])
			max = from[i] + to[i];
	}
	cout << max << endl;
}

int dijkstra(int start, int target) {

	vector<int> visited(V + 1);
	to[start] = 0;

	//인접한 노드들을 최소 힙에 삽입
	priority_queue<PII, vector<PII>, Compare> pq;
	for (auto adj : graph[start]) {
		pq.push(adj);
		to[adj.first] = adj.second;
	}


	visited[start] = 1;
	PII next;
	int new_distance;

	while (!pq.empty()) {
		next = pq.top(); pq.pop();
		if (!visited[next.first]) {
			visited[next.first] = 1;
			if (next.first == target)
				return to[target];

			//next 노드에 인접한 노드들의 거리 갱신
			for (auto adj : graph[next.first]) {
				new_distance = to[next.first] + adj.second;
				if (to[adj.first] == -1 || to[adj.first] > new_distance) {
					to[adj.first] = new_distance;
					pq.push({ adj.first, new_distance });
				}
			}
		}
	}

	return to[target];
}