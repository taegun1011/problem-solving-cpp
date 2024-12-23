#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dist[100001];
int path[100001];
short dir[3] = { -1,1,0 };

int main() {
	FASTIO;

	int N, K;
	cin >> N >> K;

	queue<int> Q;
	Q.push(N);
	dist[N] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == K) {
			cout << dist[K] - 1 << endl;
			stack<int> S;
			S.push(K);

			while (S.top() != N)
				S.push(path[S.top()]);

			while (!S.empty()) {
				cout << S.top() << ' ';
				S.pop();
			}
		}

		for (int i = 0; i < 3; i++) {
			int nxt = cur + dir[i];
			if (nxt == cur) nxt *= 2;
			if (nxt < 0 || nxt > 100000) continue;

			if (!dist[nxt]) {
				dist[nxt] = dist[cur] + 1;
				path[nxt] = cur;
				Q.push(nxt);
			}
		}
	}
}