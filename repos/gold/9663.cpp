#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int recursive(int cr, int N, vector<pair<int, int>> v) {
	if (cr > N)
		return 1;

	int ret = 0;

	for (int cc = 1; cc <= N; cc++) {
		pair<int, int> nxt = { cr, cc };
		bool flag = 0;

		if (!v.empty()) {
			for (auto p : v) {
				if (p.second == cc || abs(cr - p.first) == abs(cc - p.second)) {
					flag = 1;
					break;
				}
			}
		}
		if (!flag) {
			v.push_back(nxt);
			ret += recursive(cr + 1, N, v);
			v.pop_back();
		}
	}

	return ret;
}

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	cout << recursive(1, N, v) << endl;
}