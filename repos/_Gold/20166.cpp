#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 100 * (1 << 15) // 100개 점에서 8방향 5번

int rt = 1, nxt_node = 2;
vector<vector<pair<char, int>>> nxt(MAX);
vector<int> cnt(MAX);

vector<string> board;
int dir[8][2] = { -1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1 };
int N, M;

void insert(int cr, int cc, int left, int cur) {
	bool flag = false;
	for (const pair<char, int>& p : nxt[cur]) {
		if (board[cr][cc] == p.first) {
			flag = true;
			cur = p.second;
			break;
		}
	}
	if (!flag) {
		nxt[cur].push_back({ board[cr][cc], nxt_node });
		cur = nxt_node++;
	}
	cnt[cur]++;
	
	if (left) {
		for (int i = 0; i < 8; i++) {
			int nr = dir[i][0] + cr;
			int nc = dir[i][1] + cc;
			
			nr = nr < 0 ? nr + N : (nr == N ? 0 : nr);
			nc = nc < 0 ? nc + M : (nc == M ? 0 : nc);

			insert(nr, nc, left - 1, cur);
		}
	}
}

int find(string S) {
	int cur = rt;

	for (char ch : S) {
		bool flag = false;
		for (const pair<char, int>& p : nxt[cur]) {
			if (ch == p.first) {
				flag = true;
				cur = p.second;
				break;
			}
		}
		if (!flag)
			return 0;
	}
	return cnt[cur];
}

void solve() {
	//입력받은 그래프로 각 점에서 그래프 탐색 -> 트라이 생성
	//check를 bool이 아닌 int로

	int K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		board.push_back(row);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			insert(i, j, 5, rt);

	while (K--) {
		string str;
		cin >> str;
		cout << find(str) << '\n';
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