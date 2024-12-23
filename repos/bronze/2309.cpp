#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	vector<int> v(9), ans;
	for (int& i : v)
		cin >> i;

	bool found = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (found) break;

			if (i == j)
				continue;
			int sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) continue;
				sum += v[k];
			}
			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					ans.push_back(v[k]);
				}
				found = 1;
			}
		}
	}

	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << endl;
}