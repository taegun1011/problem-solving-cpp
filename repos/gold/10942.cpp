#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool visited[2001][2001];

//dp[i][j] : i번 수부터 j개의 수열이 팰린드롬인가
bool dp[2001][2001];
int N;

bool solve(vector<int>& v, int start, int end) {
	if (visited[start][end])
		return dp[start][end];

	visited[start][end] = 1;

	if (start == end) {
		dp[start][end] = true;
		return true;
	}

	else if (start == end + 1) {
		return (dp[start][end] = (v[start] == v[end]));
	}

	else {
		if (v[start] == v[end])
			return (dp[start][end] = solve(v, start + 1, end - 1));
		else
			dp[start][end] = false;
			return false;
	}
}

int main() {
	FASTIO;
	cin >> N;

	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> v[i];

	int M; cin >> M;
	int S, E;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << solve(v, S, E) << '\n';
	}
}