#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int N;
vector<PII> v;

//dp[i][j] : i번 행렬부터 j번 행렬까지 곱하는 총 연산 횟수의 최솟값
int dp[501][501];

void solve() {

	//setup : 인접한 두 행렬
	for (int i = 0; i < N - 1; i++)
		dp[i][i + 1] = v[i].first * v[i].second * v[i + 1].second;

	//k : 구하는 구간의 길이
	for (int k = 2; k < N; k++) {
		//시작 위치, i + k : 끝구간
		for (int i = 0; i < N - k; i++) {
			int min = INT_MAX;

			//중간
			for (int j = i; j < i + k; j++) {
				int temp = dp[i][j] + dp[j + 1][i + k] + v[i].first * v[j + 1].first * v[i + k].second;
				if (min > temp)
					min = temp;
			}

			dp[i][i + k] = min;
		}
	}

	cout <<  dp[0][N - 1] << endl;
}

int main() {
	FASTIO;
	
	cin >> N;
	
	int r, c;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		v.push_back({ r,c });
	}

	solve();
}