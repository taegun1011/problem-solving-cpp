#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dist[100001];
short dir[2] = { -1,1 };

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

		queue<int> T;
		int temp = cur;
		while (temp <= 100000) {
			T.push(temp);
			dist[temp] = dist[cur];

			if (temp == K) {
				cout << dist[K] - 1 << endl;
				return 0;
			}
			temp *= 2;

			if (!temp)
				break;
		}

		while (!T.empty()) {
			for (int i = 0; i < 2; i++) {
				int nxt = T.front() + dir[i];
				if (nxt < 0 || nxt > 100000) continue;

				if (!dist[nxt]) {
					dist[nxt] = dist[cur] + 1;
					Q.push(nxt);
				}
			}

			T.pop();
		}
	}
}