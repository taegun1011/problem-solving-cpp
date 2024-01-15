#include <bits/stdc++.h>
#define Matrix vector<vector<int>>
using namespace std;

int getIntervalSum(Matrix& sum, int x1, int y1, int x2, int y2);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int size, TC;
	cin >> size >> TC;

	Matrix v(size + 1, vector<int>(size + 1));

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			cin >> v[i][j];
		}
	}

	//sum[i][j] = i번쨰 행 j번째 열까지 모든 원소의 합
	Matrix sum(size + 1, vector<int>(size + 1));

	//setup
	for (int i = 1; i <= size; i++) {
		sum[1][i] = sum[1][i - 1] + v[1][i];
		sum[i][1] = sum[i - 1][1] + v[i][1];
	}

	//fill
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i][j];

	int x1, y1, x2, y2;
	while (TC > 0) {
		TC--;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << getIntervalSum(sum, x1, y1, x2, y2) << '\n';
	}
}

int getIntervalSum(Matrix& sum, int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}