#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
	vector<ll> arr(N + 1), psum(N + 1), pow_psum(N + 1);
	for (int i = 1; i <= N;i++){
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
		pow_psum[i] = pow_psum[i - 1] + arr[i] * arr[i];
	}

	int l, r;
	while(M--){
		cin >> l >> r;
		ll a = psum[r] - psum[l - 1], b = pow_psum[r] - pow_psum[l - 1];
		cout << (a * a - b) / 2 << '\n';
	}
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}