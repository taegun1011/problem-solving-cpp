#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//소수를 미리 구할 필요가 없다.
//'에라토스테네스의 체'라는 도구만 활용해도 됨

int main() {
	ll min, max;
	cin >> min >> max;

	int sz = max - min + 1;
	vector<bool> checked(sz + 1);

	for (ll i = 2; (i * i) <= max; i++) {
		ll sqr = i * i;

		ll temp = (min / sqr) * sqr;
		if (min % sqr)
			temp += sqr;

		for (temp; temp <= max; temp += sqr)
			checked[temp - min + 1] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= sz; i++)
		if (!checked[i])
			cnt++;

	cout << cnt << endl;
}