#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

// bool comp_pair(PII a, PII b){
//     return a.first <= b.first && a.second <= b.second;
// }

// bool r_first(PII a, PII b){
//     if(a.first == b.first)
//         return a.second <= b.second;
//     return a.first <= b.first;
// }

// bool c_first(PII a, PII b){
//     if(a.second == b.second)
//         return a.first <= b.first;
//     return a.second <= b.second;
// }

// int lis(PII s, PII e, vector<PII>& arr, bool (*comp)(PII a, PII b)){
//     vector<PII> dp(N + 1, {INT_MAX, INT_MAX});
//     dp[0] = s;
//     for (int i = 0; i < N;i++){
//         int idx = lower_bound(dp.begin(), dp.end(), arr[i], comp) - dp.begin();
//         dp[idx] = arr[i];
//     }

//     for (int i = 0; i <= N;i++)
//          print_pair(dp[i]);

//     return upper_bound(dp.begin(), dp.end(), e, comp) - dp.begin() - 1;
// }

// int rev(int a, int b){
//     return 2 * a - b;
// }

// void solve() {
//     cin >> N;
//     vector<PII> arr(N);

//     PII s, e;
//     cin >> s.first >> s.second >> e.first >> e.second;

//     for(auto& p : arr)
//         cin >> p.first >> p.second;

//     //무조건 우상향으로
//     if(s.first > e.first){
//         for (int i = 0; i < N;i++)
//             arr[i].first = rev(s.first, arr[i].first);
//         e.first = rev(s.first, e.first);
//     }

//     if(s.second > e.second){
//         for (int i = 0; i < N;i++)
//             arr[i].second = rev(s.second, arr[i].second);
//         e.second = rev(s.second, e.second);
//     }

//     sort(arr.begin(), arr.end(), r_first);
//     int a = lis(s, e, arr, c_first);

//     sort(arr.begin(), arr.end(), c_first);
//     int b = lis(s, e, arr, r_first);
    
//     cout << max(a, b) << '\n';
// }

int rev(int a, int b){
    return 2 * a - b;
}

void print_pair(PII p){
    cout << p.first << ' ' << p.second << '\n';
}

int lb(vector<set<PII>>& lis, PII p){
    int s = 0, e = lis.size(), m;

    //NNNNYYYY
    while(s < e){
        m = (s + e + 1) / 2;
        if(lis[m].lower_bound(p, ))

    }
}

void insert(map<int, PII>& M, PII p){
    //TLE 뜨면 최적화
    M[p.first].second++;
}

void solve(){
    cin >> N;
    vector<PII> arr(N);

    PII s, e;
    cin >> s.first >> s.second >> e.first >> e.second;

    for(auto& p : arr)
        cin >> p.first >> p.second;

    //무조건 우상향으로
    if(s.first > e.first){
        for (int i = 0; i < N;i++)
            arr[i].first = rev(s.first, arr[i].first);
        e.first = rev(s.first, e.first);
    }

    if(s.second > e.second){
        for (int i = 0; i < N;i++)
            arr[i].second = rev(s.second, arr[i].second);
        e.second = rev(s.second, e.second);
    }

    sort(arr.begin(), arr.end());

    //좌표 LIS
    //lis[i] : i번째 올 수 있는 모든 좌표의 배열
    vector<map<int, PII>> lis;
    lis.push_back({{s.first, {s.second, 1}}});

    for(auto p : arr){
        //p가 들어갈 수 있는 가장 작은 위치를 찾는다
        int idx = lb(lis, p);

        if(idx == lis.size())
            lis.push_back(set<PII>());
        insert(lis[idx], p);
    }

    cout << lb(lis, e) - 1 << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}