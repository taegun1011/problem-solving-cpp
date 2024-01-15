#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> dist(1000001);

int main() {
	FASTIO;

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	queue<int> Q;
	Q.push(S);
	dist[S] = 1;

	bool flag = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == G) {
			flag = 1;
			cout << dist[cur] - 1 << endl;
			break;
		}

		int nxt;
		if ((nxt = cur + U) <= F && !dist[nxt]) {
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}

		if ((nxt = cur - D) >= 1 && !dist[nxt]) {
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}

	if (!flag)
		cout << "use the stairs" << endl;
}