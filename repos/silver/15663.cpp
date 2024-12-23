#include <bits/stdc++.h>
using namespace std;

int visited[8] = { 0, };
int repeated[8] = { 0, };
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

	for (int i = 1; i < n; i++)
		if (v[i] == v[i - 1])
			repeated[i] = 1;

	recursion(n, m, vector<int>());
}

void recursion(int n, int m, vector<int> res) {
	if (!m) {
		for (auto item : res) {
			cout << item << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			res.push_back(v[i]); visited[i] = 1;

			recursion(n, m - 1, res);

			res.pop_back(); visited[i] = 0;

			for (; i < n && repeated[i + 1]; i++);
		}
	}

}