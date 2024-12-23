#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
bool checked[MAX + 1];

void Eratosthenes() {
	long long i, j;
	for (i = 2; i <= MAX; i++) {
		if (!checked[i]) {
			for (j = i * i; j <= MAX; j += i)
				checked[j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int M, N;
	cin >> M >> N;

	Eratosthenes();

	for (int i = M; i <= N; i++) {
		if (i > 1 && !checked[i])
			cout << i << '\n';
	}
}