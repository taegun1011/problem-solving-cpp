#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<pair<double, int>> arr(N);
    vector<int> rank(N);

    int a, b, c;
    for (int i = 0; i < N;i++) {
        cin >> a >> b >> c;
        arr[i] = {sqrt(a * a + b * b) / c, i};
    }

    sort(arr.begin(), arr.end());
    for(const auto& p : arr)
        cout << p.second + 1 << '\n';
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}