#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    string time, action;
    cin >> time;
    int hh = atoi(time.substr(0, 2).c_str()), mm = atoi(time.substr(3).c_str());
    mm += hh * 60;
    int clock[6];
    bool visited[6] = {0,};
    for(int i=0;i<6;i++)
        cin >> clock[i];

    cin >> N;

    map<string, int> M = {{"^", 0}, {"10MIN", 10},{"30MIN", 30},{"50MIN", 50},{"2HOUR", 120},{"4HOUR", 240},{"9HOUR", 540}};
    while(N--){
        cin >> time >> action; //time 안 쓰는 거 아님?
        int d = M[action];
        mm += d;
        mm %= 720;

        if(!d)
            visited[mm / 120] = true;
    }

    int ans = 0;
    for(int i=0;i<6;i++){
        if(visited[i])
            continue;
        ans += clock[i];
    }

    cout << min(ans, 100) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}