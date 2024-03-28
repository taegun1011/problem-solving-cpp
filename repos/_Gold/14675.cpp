#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

void solve() {
	FASTIO;

	int N, Q;
	cin >> N;

	vector<int> degree(N + 1);
	vector<PII> edge(N - 1);
	for (auto& e : edge) {
		cin >> e.first >> e.second;
		degree[e.first]++;
		degree[e.second]++;
	}

	cin >> Q;
	while (Q--) {
		int cmd, k;
		cin >> cmd >> k;
		if (cmd == 1)
			cout << (degree[k] > 1 ? "yes" : "no") << '\n';

		else {
			cout << "yes" << '\n';
		}
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}