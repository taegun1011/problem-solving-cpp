#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int recursion(int sum, int cur, int N, int S, vector<int>& v) {
	if (sum == S)
		return 1;
	else if (cur >= N)
		return 0;
	else
		return recursion(sum + v[cur], cur + 1, N, S, v) + recursion(sum, cur + 1, N, S, v);
}

int main() {
	FASTIO;

	int N, S;
	cin >> N >> S;

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	cout << recursion(0, 0, N, S, v) << endl;
}