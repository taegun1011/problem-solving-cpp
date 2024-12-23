#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int n;
	cin >> n;

	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	int x;
	cin >> x;

	int h = 0, t = v.size() - 1, ans = 0;
	while (h < t) {
		int sum = v[h] + v[t];
		if (sum > x)
			t--;
		else if (sum < x)
			h++;
		else {
			ans++;
			h++;
		}
	}

	cout << ans << endl;
}