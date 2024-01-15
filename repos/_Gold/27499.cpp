//하나의 센서를 향해 쏠 때를 기준으로

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define coord pair<int, int>

vector<int> vec_x[1001];
vector<int> vec_y;
int n, width, k;

void solve();

int main() {

	cin >> n >> width >> k;

	//x좌표는 n * k개 존재한다
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vec_x[i].push_back(x);
		vec_y.push_back(y);
	}

	solve();
}

void solve() {
	//n개의 센서를 벽에 k-1번 반사시킨다
	int new_x;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k; j++) {
			new_x = j * width;
			if (j % 2)
				new_x = new_x + width - vec_x[i][0];
			else
				new_x += vec_x[i][0];
			vec_x[i].push_back(new_x);
		}
	}

	//n * k개의 점에 대해 기울기를 구한다
	map<double, int> m;
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			double slope = (double)vec_y[i] / vec_x[i][j];
			m[slope]++;
			if (m[slope] > max)
				max = m[slope];
		}
	}

	cout << max << endl;
}