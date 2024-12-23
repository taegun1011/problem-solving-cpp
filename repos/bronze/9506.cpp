#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int num;
	cin >> num;

	while (num != -1) {
		vector<int> div;
		int sum = 0;
		for (int i = 1; i <= num / 2; i++) {
			if (num % i == 0) {
				div.push_back(i);
				sum += i;
			}
		}
		if (sum == num) {
			cout << num << " =";
			for (int i = 0; i < div.size(); i++)
				cout << ' ' << div[i] << (i < div.size() - 1 ? " +" : "");
			cout << '\n';
		}
		else
			cout << num << " is NOT perfect.\n";

		cin >> num;
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