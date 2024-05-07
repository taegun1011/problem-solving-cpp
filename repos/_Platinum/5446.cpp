#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX	100000

bool visited[MAX];
map<char, int> M_all[MAX], M_delete[MAX];
int root = 1, unused = 2;

void insert(const string& S, int flag) {
	int cur = root;
	for (char ch : S) {
		if (M_all[cur].find(ch) == M_all[cur].end()) {
			if (flag) return;
			M_all[cur][ch] = M_delete[cur][ch] = unused++;
		}
		cur = M_all[cur][ch];
		if (flag)
			visited[cur] = 1;
	}
}

int dfs(int cur) {
	int ret = 1;

	for (const auto& nxt : M_delete[cur])
		if (visited[nxt.second])
			ret += dfs(nxt.second);

	return ret;
}

void solve() {
	unused = 2;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < MAX; i++) {
		M_all[i].clear(); M_delete[i].clear();
	}

	int N1, N2;
	string str;
	cin >> N1;
	
	for (int i = 0; i < N1; i++) {
		cin >> str;
		insert(str, 0);
	}
	cin >> N2;
	while (N2--) {
		cin >> str;
		insert(str, 1);
	}
	
	cout << dfs(root) - N1 << '\n';
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}