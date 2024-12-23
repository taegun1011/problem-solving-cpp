#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int C;
	cin >> C;

	int arr[4] = { 25, 10, 5, 1 };
	for (int i = 0; i < 4; i++) {
		cout << C / arr[i] << (i == 3 ? '\n' : ' ');
		C %= arr[i];
	}
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}