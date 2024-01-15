#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int s, e, m;
	int ans1, ans2, ans3;
	ll sum, mn = 1e18;
	
	//투포인터로 이동
	for (e = 2; e < N; e++) {

		for (s = 0; s < e - 1; s++) {
			//v[e]가 음수일 경우 : 0에 인접한 값은 v[e] + v[e-1] + v[s]
			if (v[e] < 0)
				m = e - 1;

			//v[s]가 양수일 경우 : 답은 v[s] + v[s+1] + v[e]
			else if (v[s] > 0)
				m = s + 1;


			//v[s]는 음수, v[e]는 양수일 경우 : 이분탐색으로 v[m] 구하기
			else {
				m = lower_bound(v.begin() + s + 1, v.begin() + e - 1, -(v[s] + v[e])) - v.begin();
				if (m > s + 1 && abs(v[s] + v[m] + v[e]) > abs(v[s] + v[m - 1] + v[e]))
					m--;
			}

			sum = abs(0ll + v[s] + v[m] + v[e]);
			if (mn > sum) {
				ans1 = v[s]; ans2 = v[m]; ans3 = v[e];
				mn = sum;
			}
		}
	}

	cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
}