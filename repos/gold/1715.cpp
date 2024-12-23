#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;


	while (N--) {
		int num;
		cin >> num;
		pq.push(num);
	}

	long long total = 0;

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		total += a + b;
		pq.push(a + b);
	}

	cout << total << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}