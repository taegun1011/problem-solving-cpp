#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> cost;
vector<int> R;
int N;

//dp[i][j] : i번 카드가 j번째 합쳐질 때의 최솟값
int dp[401][401];

void solve() {

	//dp[i][1] : cost[i] + cost[i+1]
	for (int i = 0; i < N - 1; i++)
		dp[i][1] = cost[i] + cost[i + 1];


}

int main() {
	FASTIO;
	cin >> N;
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	cost.resize(N);
	R.resize(N);
	for (int& i : cost)
		cin >> i;



	solve();
}