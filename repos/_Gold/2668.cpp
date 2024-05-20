#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> arr;

void dfs(int cur, int start, vector<int>& res, vector<bool>& visited) {
	if (visited[cur]) {
		if (start != cur)
			res.clear();
		return;
	}
	visited[cur] = 1;
	res.push_back(cur);
	dfs(arr[cur], start, res, visited);
}

void solve() {
	int N;
	cin >> N;

	arr = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		vector<int> res;
		vector<bool> visited(N + 1);

		//사이클을 찾았을 때 시작점이 자기 자신이면 추가하고 아니면 무시한다
		dfs(i, i, res, visited);
		ans.insert(ans.end(), res.begin(), res.end());
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}