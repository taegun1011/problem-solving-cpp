#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<bool>> graph;

int ch_i(char ch) {
	if ('A' <= ch && ch <= 'Z')
		return ch - 'A';
	return ch - 'a' + 26;
}

char i_ch(int i) {
	if (0 <= i && i < 26)
		return i + 'A';
	return i - 26 + 'a';
}

void solve() {
	int size = ('Z' - 'A' + 1) * 2;

	graph = vector<vector<bool>>(size, vector<bool>(size));

	int N;
	cin >> N;
	string str;
	getline(cin, str);

	while (N--) {
		getline(cin, str);
		graph[ch_i(str[0])][ch_i(str[5])] = true;
	}

	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
			}
		}
	}

	vector<string> ans;
	char format[7] = { ' ', ' ', '=', '>', ' ', ' ', '\0' };

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (i == j)
				continue;
			if (graph[i][j]) {
				format[0] = i_ch(i);
				format[5] = i_ch(j);

				ans.push_back(string(format));
			}
		}

	cout << ans.size() << endl;
	for (string str : ans)
		cout << str << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}