#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int N, K;

//배열 A에서 n 이하의 수의 개수가 k개 이상인가?
bool decision(ll num) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {

		if (N <= num / i)
			cnt += N;
		else
			cnt += num / i;
		if (cnt >= K)
			return true;
	}

	return false;
}

int main() {
	cin >> N >> K;

	//99999 * 99999 : overflow
	ll l = 1, r = (ll)N * N, mid;
	//NNNYYY
	while (l < r) {
		mid = (l + r) / 2;

		if (decision(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
}

//이 문제에서의 decision은 앞으로도 알아두자