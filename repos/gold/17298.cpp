#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	vector<int> v(N), ans(N, -1);
	for (int& i : v)
		cin >> i;

	stack<int> S;

	for (int i = 0; i < N; i++) {
		while (!S.empty() && v[i] > v[S.top()]) {
			ans[S.top()] = v[i];
			S.pop();
		}
		S.push(i);
	}

	for (int i : ans)
		cout << i << ' ';
}