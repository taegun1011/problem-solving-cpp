#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
    vector<int> A, B;
    int num;
    while(N--){
        cin >> num;
        A.push_back(num);
    }
    while(M--){
        cin >> num;
        B.push_back(num);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int res = 0;
    for(int a : A)
        res += lower_bound(B.begin(), B.end(), a) - B.begin();

    cout << res << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}