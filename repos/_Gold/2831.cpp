#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int calc(vector<int>& a, vector<int>& b){
    int i=0,j=0,ret=0;
    while(i < a.size() && j < b.size()){
        if(a[i] + b[j] < 0){
            ret++;
            i++;
        }
        j++;
    }
    return ret;
}

//합이 음수인 쌍을 많이 만들기
void solve() {
    cin >> N;
    //남자 양수, 남자 음수, 여자 양수, 여자 음수
    vector<int> arr[4];
    int num;
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin >> num;
            if(num > 0)
                arr[i << 1].push_back(num);
            else
                arr[(i << 1) + 1].push_back(num);
        }
    }

    for(int i=0;i<4;i++){
        sort(arr[i].begin(), arr[i].end());
        if(i % 2)
            reverse(arr[i].begin(), arr[i].end());
    }

    cout << calc(arr[0], arr[3]) + calc(arr[2], arr[1]) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}