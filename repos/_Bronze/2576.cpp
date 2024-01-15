#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	vector<int> v(7);
	for (int& i : v)
		cin >> i;

	int min = 100, sum = 0;
	for(int i : v)
		if (i % 2) {
			sum += i;
			if (min > i)
				min = i;
		}
	if (sum)
		cout << sum << '\n' << min << endl;
	else
		cout << -1 << endl;
}