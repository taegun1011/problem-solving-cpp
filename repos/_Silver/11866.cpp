#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool visited[1001];

int main() {
	FASTIO;

	int N, K;
	cin >> N >> K;

	if (N == 1) {
		cout << "<1>\n";
		return 0;
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
		Q.push(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K - 1; j++) {
			Q.push(Q.front());
			Q.pop();
		}
		if (i == 0)
			cout << '<' << Q.front() << ", ";
		else if (i == N - 1)
			cout << Q.front() << ">\n";
		else
			cout << Q.front() << ", ";
		Q.pop();
	}
}

//상상도 못했음 ㄷㄷ