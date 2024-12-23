#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 50000

int nxt[MAX + 1][26];
int cnt[MAX + 1];
bool check[MAX + 1];
int rt = 1, new_node = 2;

int convert(char ch){
    return ch - 'a';
}

void insert(string str){
    int cur = rt;
    for(char ch : str){
        int idx = convert(ch);
        if(nxt[cur][idx] == -1){
            nxt[cur][idx] = new_node++;
        }
        cur = nxt[cur][idx];
    }
    check[cur] = true;
}

int re_dp(int cur){
    int& ret = cnt[cur];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i=0;i<26;i++)
        if(nxt[cur][i] != -1)
            ret += re_dp(nxt[cur][i]);

    return ret += check[cur];
}

string kth(int K){
    string ret = "";

    int cur = rt;
    for(int i=0;i<26;i++){
        int idx = nxt[cur][i];
        if(cnt[idx] <= K){
            K -= cnt[idx];
            if(K == 0)
                break;
        }
        else{
            ret.push_back('a' + idx);
            cur = idx;
        }
    }
}

void init(){
    memset(nxt, -1, sizeof(nxt));
    memset(cnt, -1, sizeof(cnt));
    memset(check, 0, sizeof(check));
    rt = 1; new_node = 2;
}

void solve(){
    int K;
    cin >> K;

    string str;
    cin >> str;

    int N = str.length();
    for(int i=0;i<N;i++)
        for(int j = 1; i + j - 1 < N;j++)
            insert(str.substr(i, j));

    re_dp(rt);

    cout << kth(K) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;

    for(int tc=1;tc<=TC;tc++){
        init();
        cout << '#' << tc << ' ';
        solve();
    }
}