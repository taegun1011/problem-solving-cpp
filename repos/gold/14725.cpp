#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int unused = 2;
unordered_map<string, int> nxt[15005];
string name[15005];

void insert(vector<string>& words) {
	int cur = 1;
	for (string word : words) {
		if (nxt[cur][word] == 0)
			nxt[cur][word] = unused++;
		cur = nxt[cur][word];
		name[cur] = word;
	}
}

void DFS(int cur, int depth) {
	if (cur != 1) {
		for (int i = 0; i < depth - 1; i++)
			cout << "--";
		cout << name[cur] << '\n';
	}

	//따로 정렬
	vector<pair<string, int>> nxt_sorted;
	for (auto p : nxt[cur])
		nxt_sorted.push_back(p);
	sort(nxt_sorted.begin(), nxt_sorted.end());

	for (auto p : nxt_sorted)
		DFS(p.second, depth + 1);
}

void solve() {
	int N;
	cin >> N;

	while (N--) {
		int K;
		cin >> K;

		vector<string> words(K);
		for (auto& word : words)
			cin >> word;

		insert(words);
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