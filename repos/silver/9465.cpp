#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void solve();
int dp(vector<vector<int>>& v);

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC > 0) {
		TC--;

		solve();
	}
}

void solve() {
	cin >> N;

	vector<vector<int>> sticker(2, vector<int>(N + 1));

	for (int i = 1; i <= N; i++)
		cin >> sticker[0][i];
	for (int i = 1; i <= N; i++)
		cin >> sticker[1][i];

	cout << dp(sticker) << endl;
}

int dp(vector<vector<int>>& v)
{
	//case 1
	//한 칸 왼쪽 위/아래의 스티커를 선택하는 경우

	//case 2
	//case1의 스티커를 포기하고 두 칸 왼쪽의 스티커를 선택하는 경우

	vector<vector<int>> score(2, vector<int>(N + 1));

	//setup
	score[0][1] = v[0][1];
	score[1][1] = v[1][1];
	score[0][2] = std::max(v[0][2] + v[1][1], score[0][1]);
	score[1][2] = std::max(v[1][2] + v[0][1], score[1][1]);

	//fill
	for (int i = 3; i <= N; i++) {
		for (int j = 0; j <= 1; j++) {
			score[j][i] = std::max(score[1 - j][i - 1], score[1 - j][i - 2]) + v[j][i];
		}
	}

	return std::max(score[0][N], score[1][N]);
}