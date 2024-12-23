#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); 

int main() {
	FASTIO
	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		if (val)
			pq.push(val);
		else if (pq.empty())
			cout << 0 << '\n';
		else {
			cout << pq.top() << '\n';
			pq.pop();
		}
			
	}
}