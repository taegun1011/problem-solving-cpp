#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define PII pair<int, int>
int N;

int setBishop(int idx, const vector<PII> pos, vector<bool>& uw, vector<bool>& dw) {
	if (idx == pos.size())
		return 0;
	int r = pos[idx].first, c = pos[idx].second;
	int uidx = c + r, didx = c - r + N - 1;

	int ret = 0;
	if (!uw[uidx] && !dw[didx]) {
		uw[uidx] = dw[didx] = true;
		ret = setBishop(idx + 1,pos, uw, dw) + 1;
		uw[uidx] = dw[didx] = false;
	}

	ret = max(ret, setBishop(idx + 1,pos, uw, dw));

	return ret;
}

void solve() {
	cin >> N;

	int tile;
	vector<PII> black, white;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tile;
			if (tile) {
				if ((i + j) % 2)
					black.push_back({ i,j });
				else
					white.push_back({ i,j });
			}
		}
	}

	vector<bool> uw(2 * N - 1), dw(2 * N - 1);

	
	cout << setBishop(0, black, uw, dw) + setBishop(0, white, uw, dw)<< endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}