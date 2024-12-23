#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> v;

bool decision(int height, int M) {
	ll sum = 0;
	for (int i : v) {
		int left = i > height ? i - height : 0;
		sum += left;
		if (sum >= M)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int l = 0, r = 1e9, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;

		if (decision(mid, M))
			l = mid;
		else
			r = mid - 1;
	}

	cout << l << endl;
}