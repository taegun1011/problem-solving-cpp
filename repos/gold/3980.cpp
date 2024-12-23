#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<vector<int>> arr(11, vector<int>(11)), pos(11, vector<int>());
vector<bool> visited(11);

int recur(int idx, int sum) {
	if (idx == 11) {
		return find(visited.begin(), visited.end(), 0) == visited.end() ? sum : 0;
	}

	int ret = 0;
	for (int p : pos[idx]) {
		if (!visited[p]) {
			visited[p] = true;
			ret = max(ret, recur(idx + 1, sum + arr[idx][p]));
			visited[p] = false;
		}
	}

	return ret;
}

void solve() {
	for (int i = 0; i < 11; i++)
		pos[i].clear();
	visited = vector<bool>(11);

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				pos[i].push_back(j);
		}
	}

	cout << recur(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}