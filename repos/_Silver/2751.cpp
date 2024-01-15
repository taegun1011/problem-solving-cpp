#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	int N;
	cin >> N;

	int num;
	while (N > 0) {
		N--;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int item : v) {
		cout << item << '\n';
	}
}