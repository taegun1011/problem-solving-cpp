#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 15 Èü

void solve(int tc) {
	int N;
	cin >> N;

	string ans = "";
	priority_queue<int> pq;
	while (N--) {
		int cmd, num;
		cin >> cmd;
		if (cmd == 1) {
			cin >> num;
			pq.push(num);
		}
		else {
			if (pq.empty())
				ans += to_string(-1);
			else {
				ans += to_string(pq.top());
				pq.pop();
			}
			ans.push_back(' ');
		}
	}
	cout << '#' << tc << ' ' << ans << '\n';
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		solve(tc);
	}
}