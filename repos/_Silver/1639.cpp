#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    string str;
    cin >> str;
    int N = str.length();
    vector<int> psum(N + 1);
    for (int i = 1; i <= N;i++)
        psum[i] = psum[i - 1] + str[i - 1] - '0';

    int i, found = 0;
    for (i = N / 2; i && !found;i--)
        for (int j = 1; j + i * 2 - 1 <= N;j++)
            if(psum[j + i - 1] - psum[j - 1] == psum[j + i * 2 - 1] - psum[j + i - 1])
                found = 1;

    cout << (i + found) * 2 << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}