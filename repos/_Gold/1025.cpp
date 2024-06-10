#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, ans = -1;
vector<string> arr;

bool chk(int num) {
	int rt = (int)sqrt(num);
	return rt * rt == num;
}

void recur(int cr, int cc, int dr, int dc, int num) {
	if (cr < 0 || cc < 0 || cr >= N || cc >= M)
		return;

	num = num * 10 + arr[cr][cc] - '0';
	if (chk(num))
		ans = max(ans, num);

	if (!dr && !dc)
		return;
	int nr = cr + dr, nc = cc + dc;
	recur(nr, nc, dr, dc, num);
}

void solve() {
	cin >> N >> M;
	arr = vector<string>(N);
	for (auto& row : arr)
		cin >> row;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int di = -N + 1; di < N; di++) {
				for (int dj = -M + 1; dj < M; dj++) {
					recur(i, j, di, dj, 0);
				}
			}
		}
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}