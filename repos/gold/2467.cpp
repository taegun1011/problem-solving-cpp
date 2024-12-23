#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve(vector<int>& v, int N);

int main() {
	FASTIO
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	solve(v, N);
}

void solve(vector<int>& v, int N) {
	//투포인터로 양끝에서 가운데로 이동하면서
	int i = N - 1, j = 0, sum = 0;
	int ans1, ans2, min = INT_MAX;

	while (j < i) {
		sum = v[i] + v[j];

		//0이 아닌 최솟값은 기록
		if (abs(sum) < min) {
			min = abs(sum);
			ans1 = v[j], ans2 = v[i];
		}

		if (sum == 0) {
			cout << v[j] << ' ' << v[i] << endl;
			return;
		}

		else if (sum > 0)
			i--;
		else
			j++;
	}

	cout << ans1 << ' ' << ans2 << endl;
}