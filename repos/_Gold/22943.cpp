#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<int> prime;
vector<bool> isPrime;

void sieve(int lim){
    isPrime = vector<bool>(lim, true);

    for(int i=2;i*i<lim;i++)
        if(isPrime[i])
            for(int j=i*i;j<lim;j+=i)
                isPrime[j] = false;

    for(int i=2;i<lim;i++)
        if(isPrime[i])
            prime.push_back(i);
}

int calc(int num){
    bool flag = false;

    for(int p : prime){
        if(num - p <= 1)
            break;
        if(p != num - p && isPrime[num - p]){
            flag = true;
            break;
        }
    }

    if(!flag)
        return 0;
    
    flag = false;
    while(!(num % M))
        num /= M;
    
    for(int p : prime){
        if(p * p > num)
            break;
        if(num % p)
            continue;
        if(isPrime[num / p]){
            flag = true;
            break;
        }
    }

    return flag;
}

int recur(int cur, int num, int vis){
    if(cur == N)
        return calc(num);
    int ret = 0;
    for(int i=0;i<=9;i++){
        if(vis & (1 << i))
            continue;
        if(cur + i)
            ret += recur(cur + 1, num * 10 + i, vis | (1 << i));
    }

    return ret;
}

void solve() {
    sieve(100000);
    
    cin >> N >> M;
    cout << recur(0, 0, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}