#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int MAX = 100;

int N, M;
vector<vector<int>> arr(MAX + 1, vector<int>(MAX + 1));

void print(){
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}
void R(){
    int mx = 0;
    for (int i = 0; i < N; i++) {
        map<int, int> cnt;
        for (int j = 0; j < M;j++)
            cnt[arr[i][j]]++;
        vector<PII> parr;
        for(auto p : cnt)
            if(p.first)
                parr.push_back({p.second, p.first});
        int sz = parr.size();
        mx = min(MAX, max(mx, sz * 2));
        sort(parr.begin(), parr.end());
        for (int j = 0; j < M; j++){
            arr[i][j * 2] = j < sz ? parr[j].second : 0;
            arr[i][j * 2 + 1] = j < sz ? parr[j].first : 0; 
        }
    }
    M = mx;
}

void C() {
    int mx = 0;
    for (int i = 0; i < M; i++) {
        map<int, int> cnt;
        for (int j = 0; j < N; j++)
            cnt[arr[j][i]]++;
        vector<PII> parr;
        for(auto p : cnt)
            if(p.first)
                parr.push_back({p.second, p.first});
        int sz = parr.size();
        mx = min(MAX, max(mx, sz * 2));
        sort(parr.begin(), parr.end());
        for (int j = 0; j < N; j++){
            arr[j * 2][i] = j < sz ? parr[j].second : 0;
            arr[j * 2 + 1][i] = j < sz ? parr[j].first : 0;
        }
    }
    N = mx;
}

void solve() {
    N = 3;
    M = 3;

    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 0; i < 9;i++)
        cin >> arr[i / 3][i % 3];

    int ans = 0;
    while(ans <= 100 && arr[r-1][c-1] != k) {
        if(N >= M)
            R();
        else
            C();
        // print();
        // cout << endl;
        ans++;
    }

    cout << (ans > 100 ? -1 : ans) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}