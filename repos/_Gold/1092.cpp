#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<int> a(N);
    for(int& x : a)
        cin >> x;
    sort(a.begin(), a.end());

    cin >> M;
    vector<int> b(M);
    for(int& x : b)
        cin >> x;
    sort(b.begin(), b.end());
    vector<bool> visited(M);

    if(a[N - 1] < b[M - 1]){
        cout << -1 << '\n';
    } else {
        int ans = 0, left = M;
        while(left > 0){
            ans++;
            for(int i=N-1;i>=0;i--){
                int ub = a[i] > b[M-1] ? M : upper_bound(b.begin(), b.end(), a[i]) - b.begin();
                for(int j=ub - 1;j>=0;j--){
                    if(!visited[j]){
                        visited[j] = true;
                        left--;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}