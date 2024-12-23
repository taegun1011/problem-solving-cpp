#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<long long> arr;
int N;
long long M;

bool chk(long long num) {
	long long sum = 0;

	for (int i = 0; i < N; i++) {
		sum += arr[i] / num;
		if (sum >= M)
			return true;
	}
	return false;
}

//No. 26 »çÅÁ °¡¹æ
long long solve() {
	cin >> N >> M;
	arr = vector<long long>(N);
	for (long long& x : arr)
		cin >> x;

	long long s = 0, e = 1e18, m;

	//YYYYNNNN
	while (s < e) {
		m = (s + e + 1) / 2;
		if (chk(m))
			s = m;
		else
			e = m - 1;
	}

	return s;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %lld\n", tc, solve());
	}
}