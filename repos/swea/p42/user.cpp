//No. 42[Pro] 블록쌓기게임

struct Result {
    int top;
    int count;
};

#define MAX 4000055

struct Node {
    int sum;
    int mx;
    int mn;
} segtree[MAX];

int MOD = 1000000;
int N;

Node update(int ql, int qr, int val, int node, int nl, int nr) {
    if (ql > nr || nl > qr)
        return segtree[node];
    
}

Node query(int ql, int qr, int node, int nl, int nr) {
    if(ql > nr || nl > qr)
}

void init(int C)
{
    N = C;
    for (int i = 0; i < MAX; i++)
        segtree[i] = { 0,0,0 };
}

Result dropBlocks(int mCol, int mHeight, int mLength)
{
    update(mCol, mCol + mLength - 1, mHeight, 1, 0, N - 1);
    Node result = query(0, N - 1, 1, 0, N - 1);

    Result ret;
    ret.top = result.mx - result.mn;
    ret.count = result.sum;
    return ret;
}
