#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
    vector<int> pos, neg;
    int num;
    for(int i=0;i<N;i++){
        cin >> num;
        if(num > 0)
            pos.push_back(num);
        else if(num < 0)
            neg.push_back(num);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int sum = 0;
    int mx = 0;
    for(int i=pos.size() - 1;i>=0;i-=M){
        sum += pos[i] * 2;
        mx = max(mx, pos[i]);
    }

    for(int i=0;i<neg.size();i+=M){
        sum -= neg[i] * 2;
        mx = max(mx, -neg[i]);
    }

    cout << sum - mx << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}