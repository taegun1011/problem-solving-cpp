#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    //5
    int ans = e;

    //4 1
    ans += d;
    a = max(a - d, 0);

    //3 2
    ans += c;

    //3 1 1
    if(b < c)
        a = max(a - 2 * (c - b), 0);

    b = max(b - c, 0);
    
    //2 2 1
    ans += b / 2;
    a = max(a - b / 2, 0);

    //2 1 1 1
    ans += b % 2;
    a = max(a - b % 2 * 3, 0);

    //1 1 1 1 1
    ans += (a + 4) / 5;

    cout << ans << endl;
}

void tc(){
    srand(time(NULL));

    for (int i = 0; i < 10;i++){
        for (int j = 0; j < 5;j++){
            cout << rand() % 1001 << ' ';
        }
        cout << endl;
    }
}

int main() {
	FASTIO;
    //tc();
    int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}
