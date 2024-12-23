#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
    for (int i = 2 - N; i <= M;i++){
        cout << " ";
        if(i <= 0)
            cout << "  ";
        else if (i < 10)
            cout << ' ' << i;
        else
            cout << i;

        if(i > 0 && (i - (1 - N)) % 7 == 0)
            cout << endl;
        else
            cout << " ";
    }
    cout << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}