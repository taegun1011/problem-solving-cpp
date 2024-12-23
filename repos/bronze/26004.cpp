#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;
int cnt[5];

void solve() {
    cin >> N;
    string str;
    cin >> str;

    map<char, int> M = {{'H', 0}, {'I', 1}, {'A', 2}, {'R', 3}, {'C', 4}};
    for(char ch : str){
        if(M.find(ch) != M.end())
            cnt[M[ch]]++;
    }

    cout << *min_element(cnt, cnt + 5) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}