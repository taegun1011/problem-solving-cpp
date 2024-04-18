#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dp[101][1000];
int N;
string A, B;

int get_diff(int a, int b) {
	int up = b - a;
	if (up < 0)
		up += 10;
	int down = a - b;
	if (down < 0)
		down += 10;
	if (up < down)
		return up;
	return -down;
}

int rotate(int n, int r, int len) {
	int a[3];
	int d = 100;
	for (int i = 0; i < 3; i++) {
		a[i] = n / d;
		n -= a[i] * d;
		d /= 10;
	}

	for (int i = 0; i < len; i++) {
		a[i] += r;
		if (a[i] >= 10)
			a[i] -= 10;
		if (a[i] < 0)
			a[i] += 10;
	}

	int ret = 0;
	d = 100;
	for (int i = 0; i < 3; i++) {
		ret += d * a[i];
		d /= 10;
	}

	return ret;
}

int re_dp(int idx, int cur3) {
	if (idx == N)
		return 0;

	if (dp[idx][cur3] != -1)
		return dp[idx][cur3];

	int& ret = dp[idx][cur3];

	int diff[3];
	int tmp = cur3;
	for (int i = 0; i < 3; i++) {
		diff[i] = idx + i < N ? get_diff(tmp / 100, B[idx + i] - '0') : 0;
		tmp = tmp % 100 * 10;
	}
	
	int nxt3 = cur3 % 100 * 10 + (idx + 3 < N ? A[idx + 3] - '0' : 0);

	//현재 1칸만 돌리기
	ret = re_dp(idx + 1, nxt3) + (abs(diff[0]) + 2) / 3;

	//i : 돌릴 칸 수, j : 맞출 위치
	if (diff[0]) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 0; j <= 9; j++)
				ret = min(ret, re_dp(idx, rotate(cur3, j, i)) + (j + 2) / 3);
			for (int j = -1; j >= -9; j--)
				ret = min(ret, re_dp(idx, rotate(cur3, j, i)) + (-j + 2) / 3);
		}
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;
	cin >> A >> B;

	int start = atoi(A.substr(0, 3).c_str());
	cout << re_dp(0, start) << endl;
}


int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}