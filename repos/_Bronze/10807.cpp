#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	int x;
	cin >> x;

	cout << count(v.begin(), v.end(), x) << endl;
}