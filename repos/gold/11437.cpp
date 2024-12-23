#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define PII pair<int, int>
#define ll long long

#define LOG 19
int N, M, Q, X;

int up[200001][LOG];

void solve()
{
    cin >> M;

    //up[i] 배열이 순서대로 채워진다는 보장이 없다
    for (int i = 1; i <= M; i++)
        cin >> up[i][0];

    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= M; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    cin >> Q;
    while (Q--)
    {
        cin >> N >> X;
        for (int i = LOG - 1; i >= 0; i--)
            if (N & (1 << i))
                X = up[X][i];
        cout << X << '\n';
    }
}

int main()
{
    FASTIO;
    int TC = 1;
    // cin >> TC;
    while (TC--)
        solve();
}