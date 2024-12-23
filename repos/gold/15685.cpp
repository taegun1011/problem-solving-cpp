#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

bool visited[100][100][4];

void shoot(vector<pair<PII, int>>& arr, int left) {

}

void solve() {
	int N;
	cin >> N;

	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<pair<PII, int>> arr;
		arr.push_back({ {x,y}, d });
		shoot(arr, g);
	}

	int res = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			res++;
			for (int k = 0; k < 4; k++) {
				if (!visited[i][j][k]) {
					res--;
					break;
				}
			}
		}
	}

	cout << res << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}