#include <bits/stdc++.h>
using namespace std;

int visited[8] = { 0, };
vector<int> v;
void recursion(int n, int m, vector<int>);

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	recursion(n, m, vector<int> ());
}

void recursion(int n, int m, vector<int> res) {
	if (m == 0) {
		for (int item : res) {
			cout << item << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			res.push_back(v[i]); visited[i] = 1;

			recursion(n, m - 1, res);

			res.pop_back(); visited[i] = 0;
		}
	}
}