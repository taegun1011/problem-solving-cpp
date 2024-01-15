#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int BFS(ll A, ll B) {
	queue<ll> Q;
	Q.push(A);

	map<ll, int> M;
	M[A] = 1;

	ll cur, next;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		next = cur * 2;
		if (!M[next] && next <= B) {
			M[next] = M[cur] + 1;
			Q.push(next);
			if (next == B)
				return M[next];
		}

		next = cur * 10 + 1;
		if (!M[next] && next <= B) {
			M[next] = M[cur] + 1;
			Q.push(next);
			if (next == B)
				return M[next];
		}
	}

	return -1;
}

int main() {
	ll A, B;
	cin >> A >> B;
	cout << BFS(A, B) << endl;
}