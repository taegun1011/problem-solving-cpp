#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//No. 24 영어 공부
int solve() {
	int n, p;
	cin >> n >> p;

	int ans = 1 + p;

	vector<int> arr(n);
	for (int& x : arr)
		cin >> x;

	int i = 0, j = 1;
	while (j < n && i < j) {
		//전체 arr[j] - arr[i] + 1일 중 j - i + 1일은 실제로 공부를 했으며, 나머지는 p로 채워야 한다
		int diff = arr[j] - arr[i] + i - j;
		if (diff <= p)
			//가능한 구간에서, 남은 p (p - diff)만큼 기간을 늘릴 수도 있다
			ans = max(ans, arr[j++] - arr[i] + 1 + p - diff);
		else
			i++;
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