#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int T;
	cin >> T;

	int N, M, num;
	cin >> N;
	vector<int> Asum(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> num;
		Asum[i] = Asum[i - 1] + num;
	}
	vector<int> subA;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			subA.push_back(Asum[j] - Asum[i]);
	sort(subA.begin(), subA.end());

	cin >> M;
	vector<int> Bsum(M + 1);
	for (int i = 1; i <= M; i++) {
		cin >> num;
		Bsum[i] = Bsum[i - 1] + num;
	}
	vector<int> subB;
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j <= M; j++)
			subB.push_back(Bsum[j] - Bsum[i]);
	sort(subB.begin(), subB.end());

	//합의 가짓수는 10^6
	long sum = 0;
	for (int l : subA)
		sum += upper_bound(subB.begin(), subB.end(), T - l) - lower_bound(subB.begin(), subB.end(), T - l);
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