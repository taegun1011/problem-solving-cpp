#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int calc(string from, const string& to){
    int ret = 0;
    for(int i=1;i<N;i++) {
        if(from[i - 1] != to[i - 1]){
            ret++;
            for(int j=-1;j<=1;j++)
                from[i + j] = 97 - from[i + j];
        }
    }

    return (from == to ? ret : -1);
}

void solve() {
    cin >> N;
    string from, to;
    cin >> from >> to;
    int a = calc(from, to);
    for(int i=0;i<2;i++)
        from[i] = 97 - from[i];
    int b = calc(from, to);
    if(b >= 0)
        b++;

    cout << (a == -1 ? b : (b == -1 ? a : min(a, b))) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}