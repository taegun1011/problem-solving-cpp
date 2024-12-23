#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	vector<int> v(N);

	int Y = 0, M = 0;
	for (int& i : v)
		cin >> i;

	for (int i : v) {
		Y += (i / 30 + 1) * 10;
		M += (i / 60 + 1) * 15;
	}

	if (Y < M)
		cout << "Y " << Y << endl;
	else if (Y > M)
		cout << "M " << M << endl;
	else
		cout << "Y M " << Y << endl;
}