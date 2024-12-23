#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<int>> arr;

void solve() {
	int N;
	cin >> N;

	vector<int> arr;
	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int dp_min[2][3];
	int dp_max[2][3];

	//√ ±‚»≠
	for (int i = 0; i < 3; i++)
		dp_min[0][i] = dp_max[0][i] = arr[i];

	for (int i = 0; i + 1 < N; i++) {
		for (int j = 0; j < 3; j++)
			cin >> arr[j];

		int cur = i % 2;
		int nxt = (cur + 1) % 2;
		dp_min[nxt][0] = min({ dp_min[cur][0], dp_min[cur][1] }) + arr[0];
		dp_min[nxt][1] = min({ dp_min[cur][0], dp_min[cur][1], dp_min[cur][2] }) + arr[1];
		dp_min[nxt][2] = min({ dp_min[cur][1], dp_min[cur][2] }) + arr[2];

		dp_max[nxt][0] = max({ dp_max[cur][0], dp_max[cur][1] }) + arr[0];
		dp_max[nxt][1] = max({ dp_max[cur][0], dp_max[cur][1], dp_max[cur][2] }) + arr[1];
		dp_max[nxt][2] = max({ dp_max[cur][1], dp_max[cur][2] }) + arr[2];
	}

	int last = (N - 1) % 2;
	cout << max({ dp_max[last][0], dp_max[last][1], dp_max[last][2] }) << ' ' << min({ dp_min[last][0], dp_min[last][1], dp_min[last][2] }) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}