#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

vector<vector<int>> arr;
int calc(int bits){
    int ret = 0;
    for (int i = 0; i < N;i++){
        if(!(bits & (1<<i)))
            continue;
        for (int j = 0; j < N;j++){
            if(bits & (1<<j))
                ret += arr[i][j];
        }
    }
    return ret;
}

void solve() {
    cin >> N;
    arr = vector<vector<int>>(N, vector<int>(N));
    for(auto& row : arr)
        for(int& x : row)
            cin >> x;

    int ans = INT_MAX;
    for (int bits = 1; bits < ((1 << N) - 2);bits++) {
        int a = calc(bits);
        int b = calc((1 << N) - 1 - bits);
        ans = min(ans, abs(a - b));
    }

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}