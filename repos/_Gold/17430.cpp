#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
	int N;
	cin >> N;

	set<int> Sx, Sy;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		Sx.insert(x); Sy.insert(y);
	}

	//x와 y에 대해 가능한 모든 조합이 존재한다 => Sx.size * Sy.size = N

	if (Sx.size() * Sy.size() == N)
		cout << "BALANCED\n";
	else
		cout << "NOT BALANCED\n";
}

int main() {
	FASTIO
	int TC;
	cin >> TC;
	
	while (TC) {
		TC--;
		solve();
	}
}