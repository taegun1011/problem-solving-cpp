#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dist[100001];
short dir[3] = { -1,1,0 };

int main() {
	FASTIO;

	int N, K;
	cin >> N >> K;

	queue<int> Q;
	Q.push(N);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == K)
			break;

		for (int i = 0; i < 3; i++) {
			int nxt = cur + dir[i];
			if (nxt == cur) nxt *= 2;

			if (nxt < 0 || nxt > 100000) continue;
			if (!dist[nxt]) {
				dist[nxt] = dist[cur] + 1;
				Q.push(nxt);
			}
		}
	}

	cout << dist[K] << endl;
}