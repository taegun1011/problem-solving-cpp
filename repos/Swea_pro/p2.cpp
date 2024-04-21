#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//No. 2 이진수 표현
string solve() {
	int N, M;
	cin >> N >> M;
	M %= (1 << N);

	return ((M + 1) & (1 << N)) ? "ON" : "OFF";
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cout << '#' << tc << ' ' << solve() << '\n';
	}
}