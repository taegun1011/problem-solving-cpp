#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, P;

void solve() {
	cin >> N >> M >> P;
	queue<int> Q;
	for (int i = 1; i <= M; i++)
		Q.push(i);

	vector<int> ans;
	while (!Q.empty()) {
		for (int i = 0; i < N; i++) {
			if (i == N - 1)
				ans.push_back(Q.front());
			Q.pop();
			if (Q.empty())
				break;
			for (int j = 0; j < P; j++) {
				Q.push(Q.front());
				Q.pop();
			}
		}
	}

	sort(ans.begin(), ans.end());
	for (int x : ans)
		cout << x << '\n';
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}