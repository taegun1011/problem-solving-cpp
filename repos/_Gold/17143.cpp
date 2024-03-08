#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int R, C;

set<int> alive;
vector<pair<int, int>> pos;
vector<int> S, D, Z;

pair<int, pair<int, int>> move(pair<int, int> cur, int dir, int speed) {
	int cr = cur.first, cc = cur.second;

	if (dir == 1) {
		speed %= 2 * (R - 1);
		if (cr - speed >= 1)
			return { 1, { cr - speed, cc } };
		speed -= cr - 1;
		if (1 + speed <= R)
			return{ 2, {1 + speed, cc} };
		speed -= R - 1;
			return { 1, {R - speed, cc} };
	}
	if (dir == 2) {
		speed %= 2 * (R - 1);
		if (cr + speed <= R)
			return { 2, { cr + speed, cc } };
		speed -= R - cr;
		if (R - speed >= 1)
			return{ 1, {R - speed, cc} };
		speed -= R - 1;
		return { 2, {1 + speed, cc} };
	}
	if (dir == 3) {
		speed %= 2 * (C - 1);
		if (cc + speed <= C)
			return { 3, { cr, cc + speed } };
		speed -= C - cc;
		if (C - speed >= 1)
			return{ 4, {cr, C - speed} };
		speed -= C - 1;
		return { 3, {cr, 1 + speed} };
	}
	speed %= 2 * (C - 1);
	if (cc - speed >= 1)
		return { 4, { cr, cc - speed } };
	speed -= cc - 1;
	if (1 + speed <= C)
		return{ 3, {cr, 1 + speed} };
	speed -= C - 1;
	return { 4, {cr, C - speed} };
}

void move_all(set<int>& alive, vector<vector<int>>& board) {
	set<int> dead;
	vector<vector<int>> new_board(R + 1, vector<int>(C + 1));

	for (int cur : alive) {
		//이동은 수학으로 한번에

		pair<int, pair<int, int>> nxt = move(pos[cur - 1], D[cur - 1], S[cur - 1]);

		int nd = nxt.first, nr = nxt.second.first, nc = nxt.second.second;

		D[cur - 1] = nd;
		if (new_board[nr][nc]) {
			if (Z[cur - 1] > Z[new_board[nr][nc] - 1]) {
				dead.insert(new_board[nr][nc]);
				new_board[nr][nc] = cur;
				pos[cur - 1] = { nr, nc };
			}
			else
				dead.insert(cur);
		}
		else {
			new_board[nr][nc] = cur;
			pos[cur - 1] = { nr, nc };
		}
	}

	for (int deadShark : dead)
		alive.erase(deadShark);

	board = new_board;
}

int catch_shark(int c, vector<vector<int>>& board) {
	for(int r=1;r<=R;r++)
		if (board[r][c]) {
			int target = board[r][c];
			alive.erase(target);
			int ret = Z[target - 1];
			board[r][c] = 0;

			return ret;
		}
	return 0;
}

//시간제한 걱정은 하지 말자
void solve() {
	int M;
	cin >> R >> C >> M;

	vector<vector<int>> board(R + 1, vector<int>(C + 1));
	
	int r, c, s, d, z;
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;

		alive.insert(i);
		pos.push_back({ r,c });
		board[r][c] = i;
		S.push_back(s);
		D.push_back(d);
		Z.push_back(z);
	}

	int sum = 0;
	for (int i = 1; i <= C; i++) {
		sum += catch_shark(i, board);
		move_all(alive, board);
	}

	cout << sum << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}