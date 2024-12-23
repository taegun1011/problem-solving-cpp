#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;

	priority_queue<int, vector<int>, greater<int>> pq;
	int p, l, num, m;
	while(N--){
		cin >> p >> l;
		priority_queue<int, vector<int>, less<int>> pq2;
		while(p--){
			cin >> num;
			pq2.push(num);
		}

		while(l && !pq2.empty()){
			m = pq2.top();
			pq2.pop();
			l--;
		}

		if(l)
			m = 1;

		pq.push(m);
	}

	int ans = 0;
	while(!pq.empty() && M >= pq.top()){
		ans++;
		M -= pq.top();
		pq.pop();
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}