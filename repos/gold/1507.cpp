#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9

void solve() {
	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int>(N));

	for (auto& row : arr)
		for (int& x : row)
			cin >> x;

	vector<vector<bool>> invalid(N, vector<bool>(N));

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == k || k == j || i == j)
					continue;

				if (arr[i][j] >= arr[i][k] + arr[k][j])
					invalid[i][j] = 1;
			}
		}
	}

	vector<vector<int>> new_dist(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			new_dist[i][j] = invalid[i][j] ? INF : arr[i][j];

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				new_dist[i][j] = min(new_dist[i][j], new_dist[i][k] + new_dist[k][j]);

	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (new_dist[i][j] != arr[i][j])
				flag = false;
		}
	}

	if (flag) {
		int sum = 0;
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				if (!invalid[i][j])
					sum += arr[i][j];

		cout << sum << endl;
	}
	else
		cout << -1 << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}