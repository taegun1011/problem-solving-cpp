#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int calc(vector<PII>& pos, int i, int j, vector<int>& energy){
    return max(0, energy[j] - abs(pos[i].first - pos[j].first) - abs(pos[i].second - pos[j].second));
}

void solve() {
    cin >> N;

    vector<PII> arr(N + 1);
    vector<int> energy(N + 1);
    for (int i = 0; i <= N;i++)
        cin >> arr[i].first >> arr[i].second >> energy[i];

    vector<int> left(N + 1);
    for (int i = 1; i <= N;i++)
        left[i] = calc(arr, i, 0, energy);

    for (int i = 1; i <= N;i++)
        for (int j = 1; j <= N;j++)
            left[i] = max(0, left[i] - calc(arr, i, j, energy));

    int ans = *max_element(left.begin() + 1, left.end());
    cout << (ans ? to_string(ans) : "IMPOSSIBLE") << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}