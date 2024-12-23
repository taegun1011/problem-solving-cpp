#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int graph[1000001][2];

void post_order(int rt) {
	if (graph[rt][0])
		post_order(graph[rt][0]);
	if (graph[rt][1])
		post_order(graph[rt][1]);
	if (rt)
		cout << rt << '\n';
}

void solve() {
	int num;
	int rt = 0;
	while (cin >> num) {
		if (!rt)
			rt = num;
		else {
			int cur = rt, prv;
			while (cur) {
				prv = cur;
				cur = graph[cur][(num < cur ? 0 : 1)];
			}
			graph[prv][(num < prv ? 0 : 1)] = num;
		}
	}
	post_order(rt);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}