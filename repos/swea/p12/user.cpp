#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Tuple {
	int d;
	int sr;
	int sc;
};
vector<vector<int>> board;
unordered_map<int, vector<Tuple>> UM;
int sz;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void findBlock(int size, int dir) {

	if (dir == 1) //오른쪽
	{
		for (int r = 1;r <= sz;r++) {
			int sum = 0, base = 1;
			
			for (int c = 1;c + size - 1 <= sz;c++) {
				if (c == 1) {
					for (int i = 1;i <= size;i++) {
						sum = sum * 10 + board[r][i];
						base *= 10;
					}
					base /= 10; //base = 10^(size-1)
				}
				else {
					sum -= board[r][c - 1] * base;
					sum = sum *10 + board[r][c + size - 1];
				}

				UM[sum].push_back({1, r, c});
			}
		}
	}
	else {
		for (int c = 1;c <= sz;c++) {
			int sum = 0, base = 1;

			for (int r = 1;r + size - 1 <= sz;r++) {
				if (r == 1) {
					for (int i = 1;i <= size;i++) {
						sum = sum * 10 + board[i][c];
						base *= 10;
					}
					base /= 10; //base = 10^(size-1)
				}
				else {
					sum -= board[r - 1][c] * base;
					sum = sum * 10 + board[r + size - 1][c];
				}

				UM[sum].push_back({ 2, r, c });
			}
		}
	}
}

void init(int N, int mMap[20][20])
{
	sz = N;
	board = vector<vector<int>>(sz + 2, vector<int>(sz + 2));
	for (int i = 1;i <= sz;i++)
		for (int j = 1;j <= sz;j++)
			board[i][j] = mMap[i - 1][j - 1];

	UM = unordered_map<int, vector<Tuple>>();
	for (int i = 1;i <= 5;i++) {
		findBlock(i, 1);//오른쪽
		if(i != 1)
			findBlock(i, 2);//아래쪽
	}
}

int basicBlock[5] = { 1, 11, 111, 1111, 11111 };

int reverse(int num) {
	int ret = 0;
	while (num) {
		ret = ret * 10 + num % 10;
		num /= 10;
	}
	return ret;
}

int numberOfCandidate(int M, int mStructure[5])
{
	int sum = 0, mx = 0, mn = 4;
	for (int i = 0;i < M;i++) {
		sum = sum * 10 + mStructure[i];
		mx = max(mx, mStructure[i] - 1);
		mn = min(mn, mStructure[i] - 1);
	}

	int rev_sum = reverse(sum);
	sum -= basicBlock[M - 1];

	int ret = 0;
	for (int i = 1;i <= 9;i++) {
		int target = basicBlock[M - 1] * i; //111 ~ 999
		if (i - mn > 5 || i - mx < 1) //더해질수 있는 높이 (=해수면 높이)는 1~5
			continue;
		ret += UM[target - sum].size();
	}

	rev_sum -= basicBlock[M - 1];
	if(rev_sum == sum)
		return ret;

	for (int i = 1;i <= 9;i++) {
		int target = basicBlock[M - 1] * i;
		if (i - mn > 5 || i - mx < 1)
			continue;
		ret += UM[target - rev_sum].size();
	}

	return ret;
}

void set(int d, int sr, int sc, int M, int mStructure[5], int type) {
	for (int i = 0;i < M;i++) {
		int cr = dir[d][0] * i + sr, cc = dir[d][1] * i + sc;
		board[cr][cc] += mStructure[i] * type;
	}
}

int BFS(int lim) {
	//print();
	vector<vector<bool>> visited(sz + 2, vector<bool>(sz + 2));
	visited[0][0] = true;

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });

	int cnt = 0;

	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();

		int cr = p.first, cc = p.second;

		for (int i = 0;i < 4;i++) {
			int nr = dir[i][0] + cr, nc = dir[i][1] + cc;
			if (nr < 0 || nr >= sz + 2 || nc < 0 || nc >= sz + 2 || visited[nr][nc] || board[nr][nc] >= lim)
				continue;
			if (board[nr][nc])
				cnt++;
			visited[nr][nc] = true;
			Q.push({ nr, nc });
		}
	}

	return sz * sz - cnt;
}

int maxArea(int M, int mStructure[5], int mSeaLevel)
{
	int sum = 0, mx = 0, mn = 4;
	for (int i = 0;i < M;i++) {
		sum = sum * 10 + mStructure[i];
		mx = max(mx, mStructure[i] - 1);
		mn = min(mn, mStructure[i] - 1);
	}
	int rev_sum = reverse(sum);
	sum -= basicBlock[M - 1];

	int ret = -1;
	for (int i = 1;i <= 9;i++) {
		int target = basicBlock[M - 1] * i;
		if (i - mn > 5 || i - mx < 1)
			continue;
		for (Tuple t : UM[target - sum]) {
			set(t.d, t.sr, t.sc, M, mStructure, 1);
			ret = max(ret, BFS(mSeaLevel));
			set(t.d, t.sr, t.sc, M, mStructure, -1);
		}
	}

	rev_sum -= basicBlock[M - 1];
	if (rev_sum == sum)
		return ret;

	int rev_mStructure[5] = { 0, };
	for (int i = 0;i < M;i++)
		rev_mStructure[i] = mStructure[M - 1 - i];

	for (int i = 1;i <= 9;i++) {
		int target = basicBlock[M - 1] * i;
		if (i - mn > 5 || i - mx < 1)
			continue;
		for (Tuple t : UM[target - rev_sum]) {
			set(t.d, t.sr, t.sc, M, rev_mStructure, 1);
			ret = max(ret, BFS(mSeaLevel));
			set(t.d, t.sr, t.sc, M, rev_mStructure, -1);
		}
	}
	return ret;
}