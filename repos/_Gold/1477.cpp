#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> arr;

bool check(int x, int left) {
	int N = arr.size();
	for (int i = 1; i < N; i++) {
		//현재 구간을 x 이하의 구간으로 나누기
		//x가 140, 구간이 140이면 필요 휴게소는 0개 -> -1 추가
		//입력 조건에서 의해 음수가 발생할 수 없음
		left -= (arr[i] - arr[i - 1] - 1) / x;
		if (left < 0)
			return false;
	}
	return true;
}

void solve() {
	int N, M, L;
	cin >> N >> M >> L;

	arr.push_back(0);
	while (N--) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	arr.push_back(L);

	int s = 1, e = L, m;

	//NNNNYYYY
	while (s < e) {
		m = (s + e) / 2;
		if (check(m, M))
			e = m;
		else
			s = m + 1;
	}

	cout << s << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}