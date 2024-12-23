#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
int arr[100001], tree[400000];

int init(int node, int nl, int nr){
    if(nl == nr)
        return tree[node] = arr[nl];
    int nm = nl + (nr - nl) / 2;
    return tree[node] = init(node * 2, nl, nm) * init(node * 2 + 1, nm + 1, nr);
}

int update(int idx, int val, int node, int nl, int nr){
    if(idx > nr || idx < nl)
        return tree[node];
    if(nl == nr)
        return tree[node] = val > 0 ? 1 : (val < 0 ? -1 : 0);
    int nm = nl + (nr - nl) / 2;
    return tree[node] = update(idx, val, node * 2, nl, nm) * update(idx, val, node * 2 + 1, nm + 1, nr);
}

int query(int l, int r, int node, int nl, int nr){
    if(r < nl || l > nr)
        return 1;
    if(l <= nl && nr <= r)
        return tree[node];
    int nm = nl + (nr - nl) / 2;
    return query(l, r, node * 2, nl, nm) * query(l, r, node * 2 + 1, nm + 1, nr);
}

void solve() {
    while(cin >> N){
        cin >> M;

        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));

        for (int i = 0; i < N;i++){
            cin >> arr[i];
            arr[i] = arr[i] > 0 ? 1 : (arr[i] < 0 ? -1 : 0);
        }

        init(1, 0, N - 1);

        char cmd;
        int a, b;
        string ans = "";
        while(M--){
            cin >> cmd >> a >> b;
            if(cmd == 'C')
                update(a - 1, b, 1, 0, N - 1);
            else{
                int res = query(a - 1, b - 1, 1, 0, N - 1);
                ans.push_back(res > 0 ? '+' : (res < 0 ? '-' : '0'));
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