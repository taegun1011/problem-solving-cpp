#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int unused = 2;
unordered_map<string, int> nxt[40005];
string name[40005];

void insert(vector<string>& path) {
	int cur = 1;
	for (string dir : path) {
		if (nxt[cur][dir] == 0)
			nxt[cur][dir] = unused++;
		cur = nxt[cur][dir];
		name[cur] = dir;
	}
}

void DFS(int cur, int depth) {
	if (cur != 1) {
		for (int i = 0; i < depth - 1; i++)
			cout << ' ';
		cout << name[cur] << '\n';
	}

	vector<pair<string, int>> nxt_sorted(nxt[cur].begin(), nxt[cur].end());
	sort(nxt_sorted.begin(), nxt_sorted.end());
	for (auto p : nxt_sorted) {
		DFS(p.second, depth + 1);
	}
}

void solve() {
	int N;
	cin >> N;
	
	string str;
	while (N--) {
		vector<string> res;
		cin >> str;
		string sub = "";
		for (char ch : str) {
			if (ch == '\\') {
				res.push_back(sub);
				sub = "";
			}
			else
				sub += ch;
		}
		res.push_back(sub);
		insert(res);
	}

	DFS(1, 0);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}