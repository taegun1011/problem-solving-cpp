#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, dish, k, coupon;
	cin >> N >> dish >> k >> coupon;

	vector<int> v(N), checked(dish + 1);
	for (int& i : v)
		cin >> i;

	int res = 0, cnt = 0;
	//0부터 k-1개 접시에서 시작
	for (int i = 0; i < k; i++) {
		if (!checked[v[i]])
			cnt++;
		checked[v[i]]++;
	}
	if (!checked[coupon])
		cnt++;
	checked[coupon]++;
		


	for (int i = 0; i < N; i++) {
		//i번째 초밥을 빼고 i+k번째 초밥을 추가
		if (checked[v[i]]) {
			checked[v[i]]--;
			if (!checked[v[i]])
				cnt--;
		}
		if (!checked[v[(i + k) % N]])
			cnt++;
		checked[v[(i + k) % N]]++;
		if (!checked[coupon])
			cnt++;
		checked[coupon]++;

		res = max(cnt, res);
	}

	cout << res << endl;
}