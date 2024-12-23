#include <iostream>
#include <vector>
using namespace std;

int N;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

vector<vector<int>> arr;
vector<bool> is_edge;
vector<pair<int, int>> pos;

int max_core, ans, idx;

void init() {
	cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N));
	is_edge = vector<bool>();
	pos = vector<pair<int, int>>(N);
	idx = max_core = ans = 0;
}

void solve() {
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if(arr[i][j])
				pos.push_back({ i, j });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		solve();
		cout << '#' << tc << ' ' << ans << '\n';
	}
}