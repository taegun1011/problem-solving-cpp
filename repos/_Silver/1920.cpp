#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool bin_search(int val) {
	int start = 0, end = v.size() - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (val < v[mid])
			end = mid - 1;
		else if (val == v[mid])
			return 1;
		else
			start = mid + 1;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, val;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> val;
		cout << bin_search(val) << '\n';
	}
}
