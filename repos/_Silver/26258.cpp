#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> vec_x;
vector<int> vec_y;

int solve(double k) {
	int start = lower_bound(vec_x.begin(), vec_x.end(), k) - vec_x.begin();

	if (vec_y[start - 1] > vec_y[start])
		return -1;
	else if (vec_y[start - 1] == vec_y[start])
		return 0;
	else
		return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x; vec_x.push_back(x);
		cin >> y; vec_y.push_back(y);
	}


	int Q; cin >> Q;
	
	double k;
	for (int i = 0; i < Q; i++) {
		cin >> k;
		cout << solve(k) << '\n';
	}
}