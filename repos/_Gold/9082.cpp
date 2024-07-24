#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    string a, b;
    cin >> a >> b;

	string c(b);
    
	for(int i=0;i<N;i++){
		char cnt = '0';
		for(int j=i-1;j<=i+1;j++){
			if(j < 0 || j >= N)
				continue;
			cnt += b[j] == '*';
		}

		int diff = a[i] - cnt;
		for(int j=i+1;j>=i-1;j--){
			if(j < 0 || j >= N || b[j] == '*')
				continue;
			if(diff > 0){
				b[j] = '*';
				diff--;
			}
		}
	}

	for(int i=N-1;i>=0;i--){
		char cnt = '0';
		for(int j=i-1;j<=i+1;j++){
			if(j < 0 || j >= N)
				continue;
			cnt += c[j] == '*';
		}

		int diff = a[i] - cnt;
		for(int j=i-1;j<=i+1;j++){
			if(j < 0 || j >= N || c[j] == '*')
				continue;
			if(diff > 0){
				c[j] = '*';
				diff--;
			}
		}
	}

	cout << max(count(c.begin(), c.end(), '*'), count(b.begin(), b.end(), '*')) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}