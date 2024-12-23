#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 7 [S/W 문제해결 기본] 9일차 - 중위순회

int N;
vector<vector<int>> graph;
vector<char> arr;

void inorder(int root) {
	if (graph[root][0])
		inorder(graph[root][0]);
	cout << arr[root];
	if (graph[root][1])
		inorder(graph[root][1]);
}

void solve(int tc) {
	cin >> N;
	graph = vector<vector<int>>(N + 1, vector<int>(2));
	arr = vector<char>(N + 1);

	for (int i = 1; i <= N; i++) {
		int n, l, r;
		char ch;
		cin >> n >> ch;
		arr[n] = ch;
		if (n * 2 <= N) {
			cin >> l;
			graph[n][0] = l;
		}
		if (n * 2 + 1 <= N) {
			cin >> r;
			graph[n][1] = r;
		}
	}

	cout << '#' << tc << ' ';
	inorder(1);
	cout << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 10;
	//cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
		solve(tc);
}