#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<int> pre, in;

void recur(int ps, int pe, int is, int isz){
    int rt = pre[ps];

    if(ps < pe){
        int im = find(in.begin() + is, in.begin() + is + isz, rt) - in.begin();
        int il = im - is, ir = isz - il - 1;
        if(il)
            recur(ps + 1, ps + il, is, il);
        if(ir)
            recur(ps + il + 1, pe, im + 1, ir);
    }

    cout << rt << ' ';
}

void solve() {
    cin >> N;
    pre = vector<int>(N);
    in = vector<int>(N);
    for(int& x : pre)
        cin >> x;
    for(int& x : in)
        cin >> x;
    
    recur(0, N - 1, 0, N);
    cout << '\n';
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}