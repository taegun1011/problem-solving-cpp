#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000000
using namespace std;

int lb(vector<int>& arr, int val) {
	int l = 0, r = arr.size(), m;

	//NNNYYYY
	while (l < r) {
		m = (l + r) / 2;
		if (arr[m] >= val)
			r = m;
		else
			l = m + 1;
	}

	return l;
}

void solve() {
	int N, M, c1, c2;
	cin >> N >> M >> c1 >> c2;

	vector<int> a(N), b(M);
	for (int& x : a)
		cin >> x;
	for (int& x : b)
		cin >> x;

	sort(b.begin(), b.end());
	//vector<int> b_neg(b);
	//reverse(b_neg.begin(), b_neg.end());
	//for (int& x : b_neg)
	//	x = -x;

	int mn = INF;
	int cnt = 0;

	for (int x : a) {
		//int idx = lower_bound(b.begin(), b.end(), x) - b.begin();
		int idx = lb(b, x);
		int res1 = idx == M ? INF : b[idx] - x;

		//auto iter1 = lower_bound(b.begin(), b.end(), x);
		//int res1 = iter1 == b.end() ? INT_MAX : *iter1 - x;

		if (res1 < mn) {
			mn = res1;
			cnt = 1;
		}
		else if (res1 == mn) {
			cnt++;
		}

		//auto iter2 = lower_bound(b_neg.begin(), b_neg.end(), -x);
		//int res2 = iter2 == b_neg.end() ? INT_MAX : *iter2 + x;
		
		int res2 = idx > 0 ? x - b[idx - 1] : INF;

		if (res2 < mn) {
			mn = res2;
			cnt = 1;
		}
		else if (res2 == mn) {
			//if(res1 != res2)
				cnt++;
		}
	}

	cout << mn + abs(c1 - c2) << ' ' << cnt << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		cout << '#' << tc << ' ';
		solve();
	}
}