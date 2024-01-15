#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	vector<int> v(5);
	for (int& i : v)
		cin >> i;

	sort(v.begin(), v.end());
	int sum = 0;
	for (int i : v)
		sum += i;

	cout << sum / 5 << '\n' << v[2] << endl;
}