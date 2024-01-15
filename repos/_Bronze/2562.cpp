#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	vector<int> v(9);

	for (int& i : v)
		cin >> i;

	vector<int>::iterator iter = max_element(v.begin(), v.end());
	cout << *iter << '\n' << iter - v.begin() + 1 << endl;
}