#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

void solve() {
	FASTIO;
	int N, M;
	cin >> N;

	//난이도, 문제번호 순
	priority_queue<PII> maxH;
	priority_queue<PII, vector<PII>, greater<PII>> minH;

	vector<int> visited(100001);

	while (N--) {
		int p, l;
		cin >> p >> l;
		maxH.push({ l,p });
		minH.push({ l,p });
		visited[p] = l;
	}

	cin >> M;
	
	map<string, int> type = { {"recommend", 1}, {"add", 2}, {"solved", 3} };

	while (M--) {
		string cmd;
		int x, p, l;
		cin >> cmd;
		switch (type[cmd]) {
		case 1:
			cin >> x;
			if (x == 1) {
				while (!maxH.empty()) {
					auto cur = maxH.top();
					if (cur.first == visited[cur.second])
						break;
					maxH.pop();
				}
				cout << maxH.top().second << '\n';
			}
			else {
				while (!minH.empty()) {
					auto cur = minH.top();
					if (cur.first == visited[cur.second])
						break;
					minH.pop();
				}
				cout << minH.top().second << '\n';
			}
			break;
		case 2:
			cin >> p >> l;
			maxH.push({ l,p });
			minH.push({ l,p });
			visited[p] = l;
			break;
		case 3:
			cin >> p;
			visited[p] = -1;
		}
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}