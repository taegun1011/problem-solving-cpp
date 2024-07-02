#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define SIZE 1000000

int N;
int segtree[SIZE * 4];

int update(int idx, int val, int node, int nl, int nr){
    if(nl > idx || nr < idx)
        return segtree[node];
    if(nl == nr)
        return segtree[node] += val;
    int nm = nl + (nr - nl) / 2;
    return segtree[node] = update(idx, val, node * 2, nl, nm)
    + update(idx, val, node * 2 + 1, nm + 1, nr);
}

int query(int k, int node, int nl, int nr){
    if(nl == nr)
        return nl;
    int nm = nl + (nr - nl) / 2;
    if(k > segtree[node * 2])
        return query(k - segtree[node * 2], node * 2 + 1, nm + 1, nr);
    return query(k, node * 2, nl, nm);
}

void solve() {
    cin >> N;

    int a, b, c;
    while(N--){
        cin >> a;
        if(a == 1){
            cin >> b;
            c = query(b, 1, 1, SIZE);
            cout << c << '\n';
            update(c, -1, 1, 1, SIZE);
        }
        
        else{
            cin >> b >> c;
            update(b, c, 1, 1, SIZE);
        }
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}