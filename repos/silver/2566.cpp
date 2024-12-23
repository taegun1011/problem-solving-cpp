#include <bits/stdc++.h>
using namespace std;

void recursion(int n, int m, vector<int> v);

int main() {
	int n, m;
	cin >> n >> m;

	recursion(n, m, vector<int> ());
}

void recursion(int n, int m, vector<int> v) {
	if (!m) {
		for (auto item : v)
			cout << item << ' ';
		cout << endl;
		return;
	}

	int i = (v.empty() ? 1 : v[v.size() - 1] + 1);
	for (; i <= n; i++) {
		v.push_back(i);
		recursion(n, m - 1, v);
		v.pop_back();
	}
}