#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

int D[10][10][10][10];

void eratosthenes(int n) {
	bool* checked = new bool[n + 1];
	memset(checked, 0, n + 1);

	for (int i = 2; i <= n; i++) {
		if (!checked[i]) {
			prime.push_back(i);
			for (int j = i; j <= n; j += i)
				checked[j] = 1;
		}
	}
	delete[] checked;
}

int visited[10001];
int dist[10001];

int BFS(int a, int b) {
	if (a == b)
		return 0;
	queue<int> Q;
	Q.push(a);
	visited[a] = 1;

	int cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		int dig1 = cur / 1000, dig2 = cur % 1000 / 100, dig3 = cur % 100 / 10, dig4 = cur % 10;

		for (int i = 0; i <= 9; i++) {
			int next = cur + (i - dig1) * 1000;
			if (next >= 1000 && D[i][dig2][dig3][dig4] == 1 && !visited[next]) {
				dist[next] = dist[cur] + 1;
				visited[next] = 1;
				Q.push(next);
				if (next == b)
					return dist[next];
			}
		}

		for (int i = 0; i <= 9; i++) {
			int next = cur + (i - dig2) * 100;
			if (next >= 1000 && D[dig1][i][dig3][dig4] == 1 && !visited[next]) {
				dist[next] = dist[cur] + 1;
				visited[next] = 1;
				Q.push(next);
				if (next == b)
					return dist[next];
			}
		}

		for (int i = 0; i <= 9; i++) {
			int next = cur + (i - dig3) * 10;
			if (next >= 1000 && D[dig1][dig2][i][dig4] == 1 && !visited[next]) {
				dist[next] = dist[cur] + 1;
				visited[next] = 1;
				Q.push(next);
				if (next == b)
					return dist[next];
			}
		}

		for (int i = 0; i <= 9; i++) {
			int next = cur + i - dig4;
			if (next >= 1000 && D[dig1][dig2][dig3][i] == 1 && !visited[next]) {
				dist[next] = dist[cur] + 1;
				visited[next] = 1;
				Q.push(next);
				if (next == b)
					return dist[next];
			}
		}
	}

	return -1;
}

void solve() {
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));

	int a, b;
	cin >> a >> b;

	int res = BFS(a, b);
	if (res == -1)
		cout << "Impossible\n";
	else
		cout << res << endl;
}

int main() {
	eratosthenes(10000);
	
	//1000 이상 10000 이하 소수를 미리 저장
	for (int i : prime)
		if (i >= 1000)
			D[i / 1000][i % 1000 / 100][i % 100 / 10][i % 10] = 1;

	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}