#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

map<int, string> expr = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "quarter"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {21, "twenty one"},
        {22, "twenty two"},
        {23, "twenty three"},
        {24, "twenty four"},
        {25, "twenty five"},
        {26, "twenty six"},
        {27, "twenty seven"},
        {28, "twenty eight"},
        {29, "twenty nine"},
        {30, "half"}
    };

string convert_to_minute(string str, int min){
    if(min % 15 == 0)
        return str;
    if(min == 1)
        return str + " minute";
    return str + " minutes";
}

void solve() {
    

    cin >> N >> M;

    if(M == 0){
        cout << expr[N] << ' ' << "o' clock" << endl;
    }
    else if(M <= 60 - M){
        cout << convert_to_minute(expr[M], M) << " past " << expr[N] << endl;
    }
    else{
        cout << convert_to_minute(expr[60 - M], 60 - M) << " to " << expr[N % 12 + 1] << endl;
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}