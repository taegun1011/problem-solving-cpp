#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int prv[1000001], nxt[1000001];
void solve() {
    cin >> N >> M;

    vector<int> arr(N);
    for(int& x : arr)
        cin >> x;

    for (int i = 0; i < N;i++){
        nxt[arr[i]] = arr[(i + 1) % N];
        prv[arr[(i + 1) % N]] = arr[i];

        prv[arr[i]] = arr[(i - 1 + N) % N];
        nxt[arr[(i - 1 + N) % N]] = arr[i];
    }

    string str;
    map<string, int> cmd = {{"BN", 1}, {"BP", 2}, {"CN", 3}, {"CP", 4}};
    int i, j;
    while(M--){
        cin >> str;
        switch(cmd[str]){
            case 1:
                cin >> i >> j;
                cout << nxt[i] << '\n';
                nxt[j] = nxt[i];
                prv[nxt[j]] = j;
                prv[j] = i;
                nxt[i] = j;
                break;
            case 2:
                cin >> i >> j;
                cout << prv[i] << '\n';
                prv[j] = prv[i];
                nxt[prv[j]] = j;
                nxt[j] = i;
                prv[i] = j;
                break;
            case 3:
                cin >> i;
                cout << nxt[i] << '\n';
                nxt[i] = nxt[nxt[i]];
                prv[nxt[i]] = i;
                break;
            case 4:
                cin >> i;
                cout << prv[i] << '\n';
                prv[i] = prv[prv[i]];
                nxt[prv[i]] = i;
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