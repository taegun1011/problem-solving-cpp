#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;
vector<int> S, W;

int calc(int cur) {

	if (cur == N) {
		return 0;
	}

	int ret = 0;
	bool found = false;
	if (S[cur] > 0) {
		for (int nxt = 0; nxt < N; nxt++) {
			if (nxt == cur || S[nxt] <= 0)
				continue;
			found = true;
			S[nxt] -= W[cur];
			S[cur] -= W[nxt];
			ret = max(ret, (S[nxt] <= 0) + (S[cur] <= 0) + calc(cur + 1));
			S[nxt] += W[cur];
			S[cur] += W[nxt];
		}
	}
	
	if (!found)
		ret = max(ret, calc(cur + 1));
	return ret;
}

void solve() {
	cin >> N;
	S.resize(N);
	W.resize(N);

	for (int i = 0; i < N; i++)
		cin >> S[i] >> W[i];

	cout << calc(0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}