#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

#define MAX 2400000
#define SIZE 26

int N, M;
int rt = 1, idx = 2;

bool check[MAX];
int nxt[MAX][SIZE];
int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
map<int, int> MAP = {{1, 0}, {2, 0}, {3, 1}, {4, 1}, {5, 2}, {6, 3}, {7, 5}, {8, 11}};
bool visited[4][4];
bool word_visited[MAX];

inline int convert(char ch){
    return ch - 'A';
}

struct node {
    int r;
    int c;
    int idx;
    string str;
};

int score, cnt;
string word;

void insert(string str){
    int cur = rt;
    for(char ch : str){
        int type = convert(ch);
        if(nxt[cur][type] == -1)
            nxt[cur][type] = idx++;
        cur = nxt[cur][type];
    }
    check[cur] = true;
}

void dfs(int cr, int cc, int ci, vector<string>& board, string& str) {
    visited[cr][cc] = true;
    if(check[ci]){
        if(!word_visited[ci]){
            cnt++;
            score += MAP[(int)str.length()];
        }
        word_visited[ci] = true;

        if(word.length() == str.length()){
            if(word > str)
                word = str;
        }
        else if(word.length() < str.length())
            word = str;
    }

    for (int i = 0; i < 8; i++) {
        int nr = cr + dir[i][0], nc = cc + dir[i][1];
        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || visited[nr][nc])
            continue;
        int ni = nxt[ci][convert(board[nr][nc])];
        if(ni == -1)
            continue;
        str.push_back(board[nr][nc]);
        dfs(nr, nc, ni, board, str);
        str.pop_back();
    }

    visited[cr][cc] = false;
}

void solve() {
    memset(nxt, -1, sizeof(nxt));

    cin >> N;
    while(N--){
        string str;
        cin >> str;
        insert(str);
    }

    cin >> M;
    vector<string> board(4);
    while(M--){
        score = cnt = 0;
        word.clear();
        memset(word_visited, 0, sizeof(word_visited));

        for (int i = 0; i < 4;i++)
            cin >> board[i];

        for (int i = 0; i < 4;i++){
            for (int j = 0; j < 4;j++){
                int idx = nxt[rt][convert(board[i][j])];
                if(idx == -1)
                    continue;
                string str = "";
                str.push_back(board[i][j]);
                dfs(i, j, idx, board, str);
            }
        }

        cout << score << ' ' << word << ' ' << cnt << '\n';
    }
    

}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}