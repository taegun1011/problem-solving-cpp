#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

string A, B;

int ctoi(char ch) {
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return ch - 'a' + 10;
}

char itoc(int i) {
	if (i <= 9)
		return '0' + i;
	return 'a' + i - 10;
}

ll convert(int base) {
	ll mul = 1, ret = 0;
	for (char ch : A) {
		int num = ctoi(ch);
		if (num >= base)
			return -1;
		ret += mul * num;
		if (ret < 0)
			return -1;
		mul *= base;
	}
	return ret;
}

bool convert(ll X, ll base) {
	string ret;
	while (X) {
		ret.push_back(itoc(X % base));
		X /= base;
	}

	return ret == B || (ret.empty() && B == "0");
}

void solve() {
	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	vector<int> a, b;

	for (int i = 2; i <= 36; i++) {
		ll X = convert(i);
		if (X >= 0) {
			for (int j = 2; j <= 36; j++) {
				if (j == i)
					continue;
				if (convert(X, j)) {
					a.push_back(i);
					b.push_back(j);
				}
			}
		}
	}

	if (a.empty() || b.empty())
		cout << "Impossible\n";
	else if (a.size() > 1 || b.size() > 1)
		cout << "Multiple\n";
	else {
		cout << convert(a[0]) << ' ' << a[0] << ' ' << b[0] << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}