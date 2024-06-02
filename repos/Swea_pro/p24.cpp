#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> arr;

//start일부터 
int calc(int cur, int left) {
	int ret = 1;
	while (left) {
		int val = arr[cur] + left;
		auto nxt = lower_bound(arr.begin(), arr.end(), val);
		left = nxt - arr.begin() - cur - 1;
		cur = nxt - arr.begin() - 1;
		ret += arr[cur];
		if (*nxt == val) {
			ret -= arr[cur];
			cur++;
			left++;
			ret += arr[cur];
		}
		else

	}

	return ret;
}

//No. 24 영어 공부
int solve() {
	int ans = 0;

	int n, p;
	cin >> n >> p;
	arr = vector<int>(n + 1);
	arr[0] = 1;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	arr.push_back(1e7);

	for (int i = 0; i <= n; i++) {
		ans = max(ans, calc(i, p));
	}

	return ans;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}
}