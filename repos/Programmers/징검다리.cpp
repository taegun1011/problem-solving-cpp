#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int lim, const vector<int>& arr, int mx){
    int cur = 0, cnt = 0;
    
    while(cnt++ < mx){
        auto nxt = upper_bound(arr.begin(), arr.end(), cur + lim);
        if(nxt == arr.end())
            return true;
        cur = *nxt;
    }
    
    return false;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    int mx = rocks.size() - n;
    
    int s = 1, e = 1000000001, m;
    
    //NNNYYY
    while(s < e){
        m = s + (e - s) / 2;
        if(check(m, rocks, mx))
            e = m;
        else
            s = m + 1;
    }
    
    return s;
}