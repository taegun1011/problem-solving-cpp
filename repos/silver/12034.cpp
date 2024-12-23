#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    cin >> N;

    vector<int> arr(N * 2);
    for(int&x : arr)
        cin >> x;
    map<int, int> M;
    for (int i = 0; i < N * 2;i++)
        if(M[arr[i]]){
            M[arr[i]]--;
        }
        else{
            cout << arr[i] << ' ';
            M[arr[i] / 3 * 4]++;
        }
    cout << endl;
}

int main() {
	FASTIO;
	int TC, tc = 1;
	cin >> TC;
    while(tc <= TC)
        solve(tc++);
}