#include <deque>
#include <vector>
using namespace std;

#define MOD 20

deque<int> cards;
int joker;
deque<vector<int>> sum_cards[20];

void init(int mJoker, int mNumbers[5])
{
    cards = deque<int>();
    for (int i = 0;i < 5;i++)
        cards.push_back(mNumbers[i]);
    joker = mJoker;
    for (int i = 0;i < 20;i++)
        sum_cards[i] = deque<vector<int>>(0, vector<int>());
}

void putCards(int mDir, int mNumbers[5])
{
    if (mDir) {
        for (int i = 0;i < 5;i++)
            cards.push_back(mNumbers[i]);
        int offset = cards.size() - 8;
        for (int i = 1;i <= 30;i++) {
            for (int j = 0;j < 5;j++) {
                int result = 0;
                vector<int> arr(4);
                //슬라이딩 윈도우 쓰면 더 빠르겠지만 헷갈림
                for (int k = 0;k < 4;k++) {
                    int val = cards[offset + j + k];
                    arr[k] = val;
                    if (val == -1)
                        val = i;
                    result += val;
                }
                result %= 20;
                sum_cards[result].push_back(arr);
            }
        }
    }
    else {
        for (int i = 4;i >= 0;i--)
            cards.push_front(mNumbers[i]);
        int offset = 0;
        for (int i = 1;i <= 30;i++) {
            for (int j = 0;j < 5;j++) {
                int result = 0;
                vector<int> arr(4);
                for (int k = 0;k < 4;k++) {
                    int val = cards[offset + j + k];
                    arr[k] = val;
                    if (val == -1)
                        val = i;
                    result += val;
                }
                result %= 20;
                sum_cards[result].push_back(arr);
            }
        }
    }
}

int findNumber(int mNum, int mNth, int ret[4])
{
    if (mNth - 1 >= sum_cards[mNum].size())
        return 0;
    vector<int> result = sum_cards[mNum][mNth - 1];
    for (int i = 0;i < 4;i++)
        ret[i] = result[i];
    return 1;
}

void changeJoker(int mValue)
{
    joker = mValue;
}