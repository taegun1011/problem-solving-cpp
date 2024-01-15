#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void hanoi(int N, int from, int to) {
	int mid = 6 - from - to;

	if (N == 1)
		cout << from << ' ' << to << '\n';
	else {
		hanoi(N - 1, from, mid);
		cout << from << ' ' << to << '\n';
		hanoi(N - 1, mid, to);
	}
}

int main() {
	FASTIO;

	int N;
	cin >> N;

	cout << (int)pow(2, N) - 1 << endl;
	hanoi(N, 1, 3);
}