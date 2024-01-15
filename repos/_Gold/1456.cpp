#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define limit 100000000000000LL

void solve(ll min, ll max) {
	ll rt = sqrt(max);
	vector<bool> checked(rt + 1);

	ll i, j, cnt = 0;
	for (i = 2; i <= rt; i++) {
		if (!checked[i]) {
			for (j = i * i; j <= rt; j += i)
				checked[j] = 1;
			for (j = i * i; j <= max; j *= i) {
				//소수의 제곱은 겹치지 않는다.
				if (j >= min)
					cnt++;
				if (j > (limit / i))
					break;
			}
		}
	}

	cout << cnt << endl;
}

int main() {
	ll MIN, MAX;
	cin >> MIN >> MAX;

	solve(MIN, MAX);
}