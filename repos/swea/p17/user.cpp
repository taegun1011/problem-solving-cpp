#define MAX 110000
#include <string>
#include <map>

using namespace std;

int cur_origin_str_id = 0;
int cur_copy_str_id = 10;
map<string, int> map_str_id;

int str_to_id(const string& str, bool isCopy) {
    if (map_str_id.find(str) == map_str_id.end())
        return map_str_id[str] = isCopy ? cur_copy_str_id++ : cur_origin_str_id++;
    return map_str_id[str];
}

struct Node {
    int idx; //idx = -1 : deep copy || tail
    int data;
    Node* prev;
};

int cur = 0;
Node pool[MAX];

Node* new_node(int idx, int data) {
    pool[cur].idx = idx;
    pool[cur].data = data;
    pool[cur].prev = nullptr;

    return &pool[cur++];
}

int origin[11][200001]; //원본 리스트
Node* tails[5011]; //각 리스트의 tail 노드
int p[5011]; //유니온 파인드

int find(int x) {
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    p[max(x, y)] = min(x, y);
}

void init()
{
    cur_origin_str_id = 0;
    cur_copy_str_id = 10;
    map_str_id = map<string, int>();

    cur = 0;

    for (int i = 0; i < 5011; i++) {
        Node* tail = new_node(-1, 0);
        tails[i] = tail;
        p[i] = i;
    }
}

void makeList(char mName[], int mLength, int mListValue[])
{
    string name(mName);
    int idx = str_to_id(name, false);
    for (int i = 0; i < mLength; i++)
        origin[idx][i] = mListValue[i];
}

void copyList(char mDest[], char mSrc[], bool mCopy)
{
    string src(mSrc), dest(mDest);
    int src_idx = map_str_id[src];
    if (mCopy) {
        Node* node = new_node(-1, 0);
        node->prev = tails[src_idx]->prev;

        int dest_idx = str_to_id(dest, true);
        Node* dest_tail = tails[dest_idx];
        dest_tail->prev = node;

        merge(p[src_idx], p[dest_idx]);
    }
    else {
        map_str_id[dest] = src_idx;
    }
}

void updateElement(char mName[], int mIndex, int mValue)
{
    string name(mName);
    int idx = map_str_id[name];
    Node* node = new_node(mIndex, mValue);
    node->prev = tails[idx]->prev;
    tails[idx]->prev = node;
}

int element(char mName[], int mIndex)
{
    string name(mName);
    Node* cur = tails[map_str_id[name]];

    while (cur != nullptr) {
        if (cur->idx == mIndex)
            return cur->data;
        cur = cur->prev;
    }

    return origin[find(map_str_id[name])][mIndex];
}