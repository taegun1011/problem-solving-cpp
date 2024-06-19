#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<vector<int>> graph;
vector<int> arr;

int dp[10001];

int re_dp(int cur){
    if(dp[cur] != -1)
        return dp[cur];
    int &ret = dp[cur] = arr[cur];

    for(int nxt : graph[cur])
        ret = max(ret, re_dp(nxt) + arr[cur]);
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N;

    graph = vector<vector<int>>(N + 1, vector<int>());
    arr = vector<int>(N + 1);
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
        cin >> M;
        if(!M){
            graph[0].push_back(i);
            continue;
        }

        int j;
        while(M--){
            cin >> j;
            graph[j].push_back(i);
        }
    }

    cout << re_dp(0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}