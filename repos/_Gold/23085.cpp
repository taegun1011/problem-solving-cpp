#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, K;

bool visited[3001];
int dist[3001];

//start부터 N까지의 BFS
int BFS(int start) {

	if (start == N)
		return 0;

	queue<int> Q;
	Q.push(start);
	visited[start] = 1;
	dist[start] = 0;

	int cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		//next = cur - 2 * i + K (i : 다시 뒤집는 개수)
		for (int i = 0; i < K; i++) {
			int next = cur - i;

			//cur(현재 T 개수) >= i (뒤집을 T 수)
			//N-cur(남은 H 개수) >= K - i (뒤집을 H 수)
			if (next >= 0 && N - K >= next) {
				next += (K - i);

				if (!visited[next]) {
					Q.push(next);
					dist[next] = dist[cur] + 1;
					visited[next] = 1;

					if (next == N)
						return dist[next];

				}
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> K;

	string str;
	cin >> str;

	int start = 0;
	for (char c : str)
		if (c == 'T')
			start++;

	cout << BFS(start) << endl;
}