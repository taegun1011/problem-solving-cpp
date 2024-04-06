#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

vector<vector<ll>> arr;
vector<vector<ll>> bomb;
vector<vector<ll>> sum;

ll psum(int sr, int sc, int er, int ec) {
	sr = max(1, sr);
	sc = max(1, sc);
	return sum[er][ec] - sum[sr - 1][ec] - sum[er][sc - 1] + sum[sr - 1][sc - 1];
}

void solve() {

	int N, M;
	cin >> N >> M;

	int d = M / 2;
	
	arr = vector<vector<ll>>(N, vector<ll>(N));
	bomb = vector<vector<ll>>(N, vector<ll>(N));
	sum = vector<vector<ll>>(N, vector<ll>(N));

	for (auto& row : arr)
		for (ll& x : row)
			cin >> x;

	if (d) {
		for(int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				//폭발 범위 넘어가면
				if (i - d < 0 || i + d >= N || j - d < 0 || j + d >= N) {
					bomb[i][j] = 0;
				}
				else {
					/*
						aaab
						aaab
						aaab
						ccc
					*/
					ll a = psum(i - M + 1, j - M + 1, i - 1, j - 1);
					ll b = psum(i - M + 1, j, i - 1, j);
					ll c = psum(i, j - M + 1, i, j - 1);

					bomb[i][j] = -arr[i - d][j - d] - (a + b + c);
				}

				if (i && j)
					sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + bomb[i][j];
			}
		}
	}

	//M이 1이면 처리 곤란;; 따로 처리
	else {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				bomb[i][j] = -arr[i][j];
	}

	for (auto& row : bomb) {
		for (ll& x : row) {
			cout << x << ' ';
		}
		cout << '\n';
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