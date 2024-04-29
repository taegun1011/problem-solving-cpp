#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define PII pair<int, int>

int dir[2] = { -1,1 };

void solve() {
	int N, K;
	cin >> N >> K;

	queue<PII> Q;
	set<int> S;
	while (N--) {
		int num;
		cin >> num;
		Q.push({ num, 0 });
		S.insert(num);
	}

	ll sum = 0;
	while (K) {
		PII cur = Q.front();
		Q.pop();

		int cr = cur.first, cd = cur.second;
		for (int i = 0; i < 2; i++) {
			int nr = cr + dir[i];
			int nd = cd + 1;
			if (S.find(nr) != S.end())
				continue;
			S.insert(nr);
			Q.push({ nr, nd });
			sum += nd;

			K--;
			if (!K)
				break;
		}
	}

	cout << sum << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}