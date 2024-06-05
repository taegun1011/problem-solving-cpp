#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

void solve() {
	cin >> N;

	map<int, int> M;
	int a, b;
	while (N--) {
		cin >> a >> b;
		M[a]++;
		M[b]--;
	}

	vector<PII> arr;
	int sum = 0;
	for (PII p : M) {
		sum += p.second;
		arr.push_back({ sum, -p.first });
	}

	auto iter = max_element(arr.begin(), arr.end());
	int mx = (*iter).first, from = -((*iter).second);
	for (; iter != arr.end() && (*iter).first == mx; iter++);
	int to = -(*iter).second;
	cout << mx << '\n' << from << ' ' << to << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}