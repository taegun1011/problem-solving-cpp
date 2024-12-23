#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int H, W, N;
	cin >> H >> W >> N;

	int a = N % H, b = N / H + 1;
	if (!a) {
		a = H;
		b--;
	}
	cout << a * 100 + b << endl;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}