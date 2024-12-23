#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
vector<string> arr;

ll calc(vector<int> res){
    ll ret = 0;
    for(auto str : arr){
        ll base = 1;
        for (int i = str.length() - 1; i >= 0;i--){
            ret += base * res[str[i] - 'A'];
            base *= 10;
        }
    }

    return ret;
}

void solve() {
    cin >> N;
    arr = vector<string>(N);
    for(auto& str : arr)
        cin >> str;

    vector<ll> cnt(10);
    vector<bool> first(10);
    for(auto str : arr){
        first[str[0] - 'A'] = true;
        ll base = 1;
        for (int i = str.length() - 1; i >= 0;i--){
            cnt[str[i] - 'A'] += base;
            base *= 10;
        }
    }

    priority_queue<pair<ll, int>> pq;
    for (int i = 0; i < 10;i++)
        pq.push({cnt[i], i});
    vector<int> tmp(10), res(10);

    int val = 9;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        tmp[val--] = p.second;
    }

    for (int i = 0; i < 10;i++){
        if(!first[tmp[i]]){
            for (int j = i; j - 1 >= 0;j--)
                swap(tmp[j], tmp[j - 1]);
            break;
        }
    }
    for (int i = 0; i < 10;i++)
        res[tmp[i]] = i;

    cout << calc(res) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}