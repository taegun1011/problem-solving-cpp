#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1000005

int root = 1, unused = 2;
map<char, int> nxt[MAX];

void insert(const string& S) {
	int cur = 1;
	for (char ch : S) {
		if (nxt[cur].find(ch) == nxt[cur].end())
			nxt[cur][ch] = unused++;
		cur = nxt[cur][ch];
	}
	nxt[cur]['\0'] = 1;
}

int find(const string& S) {
	int cur = 1, ret = 0;
	for (char ch : S) {
		if (cur == 1 || nxt[cur].size() > 1)
			ret++;
		cur = nxt[cur][ch];
	}

	return ret;
}

void solve() {
	int N;
	while (cin >> N) {
		for (int i = 0; i < MAX; i++)
			nxt[i].clear();

		string str;
		vector<string> arr;
		double sum = 0;
		while (N--) {
			cin >> str;
			arr.push_back(str);
			insert(str);
		}

		for (string str : arr)
			sum += find(str);
		printf("%.2lf\n", sum / arr.size());
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