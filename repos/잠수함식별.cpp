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

    //앞에서부터 읽는다
    //패턴 첫 문자 기록
    //0 -> 1 : 패턴 초기화
    //  -> 0 : 무효
    //1 -> 0
    //       -> 0 : 1이 나오면 패턴 이동
    //       -> 1 : 0이 나오면 패턴 이동
    //  -> 1 : 무효

    N = str.length();
    for(int i=0;i<N;i++){
        
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}