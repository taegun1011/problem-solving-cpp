#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define PII pair<int, int>

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	ll sum = 0;
	stack<int> S1;

	for (int i = 0; i < N; i++) {
		while (!S1.empty() && v[i] > S1.top()) {
			sum++;
			S1.pop();
		}
		S1.push(v[i]);
	}

	stack<PII> S2;

	for (int i = N - 1; i >= 0; i--) {
		int cnt = 1;
		while (!S2.empty() && v[i] >= S2.top().first) {
			sum += S2.top().second;
			if (v[i] == S2.top().first)
				cnt = S2.top().second + 1;
			S2.pop();
		}
		S2.push({ v[i], cnt });
	}

	cout << sum << endl;
}