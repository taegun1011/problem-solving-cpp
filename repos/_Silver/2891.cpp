#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, K;

void solve() {
	cin >> N >> M >> K;
	vector<bool> visited(N);
	vector<int> arr;

	int num;
	while(M--){
		cin >> num;
		visited[num - 1] = true;
	}

	while(K--){
		cin >> num;
		if(visited[--num])
			visited[num] = false;
		else
			arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	for(int x : arr){
		if(x && visited[x - 1])
			visited[x - 1] = false;
		else if(x + 1 < N && visited[x + 1])
			visited[x + 1] = false;
	}
	int ans = 0;
	for(bool b : visited)
		ans += b;
	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}