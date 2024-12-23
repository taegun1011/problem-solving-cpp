#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<pair<int, int>> graph;
string preorder(int cur) {
	string ret = "";
	ret += (char)cur + 'A';
	if (graph[cur].first != -1)
		ret += preorder(graph[cur].first);
	if (graph[cur].second != -1)
		ret += preorder(graph[cur].second);

	return ret;
}

string inorder(int cur) {
	string ret = "";
	if (graph[cur].first != -1)
		ret += inorder(graph[cur].first);
	ret += (char)cur + 'A';
	if (graph[cur].second != -1)
		ret += inorder(graph[cur].second);

	return ret;
}

string postorder(int cur) {
	string ret = "";
	if (graph[cur].first != -1)
		ret += postorder(graph[cur].first);
	if (graph[cur].second != -1)
		ret += postorder(graph[cur].second);
	ret += (char)cur + 'A';

	return ret;
}

void solve() {
	int N;
	cin >> N;

	graph = vector<pair<int, int>>(N);
	while (N--) {
		char p, l, r;
		cin >> p >> l >> r;
		graph[p - 'A'].first = l != '.' ? l - 'A' : -1;
		graph[p - 'A'].second = r != '.' ? r - 'A' : -1;
	}

	cout << preorder(0) << endl;
	cout << inorder(0) << endl;
	cout << postorder(0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}