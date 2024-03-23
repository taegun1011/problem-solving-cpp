#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int recur(int n) {
	if (!n)
		return 2;
	return 2 * recur(n - 1) - 1;
}

void solve() {
	int N;
	cin >> N;

	int a = recur(N);
	cout << a * a << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}