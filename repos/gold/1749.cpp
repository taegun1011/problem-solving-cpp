#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>(M + 1));
	vector<vector<int>> psum(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + graph[i][j];
		}
	}

	int ans = INT_MIN;
	for (int er = 1; er <= N; er++)
		for (int ec = 1; ec <= M; ec++)
			for (int sr = 1; sr <= er; sr++)
				for (int sc = 1; sc <= ec; sc++)
					ans = max(ans, psum[er][ec] - psum[sr - 1][ec] - psum[er][sc - 1] + psum[sr - 1][sc - 1]);
	
	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}