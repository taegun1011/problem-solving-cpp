#include <deque>

using namespace std;

#define MOD 20
deque<int> cards;
int offset;
int joker;

//sum_cards[i][j] : 조커가 i일 때 합이 j인 애들
deque<int> sum_cards[MOD][MOD];

void init(int mJoker, int mNumbers[5])
{
    cards = deque<int>();
    for (int i = 0; i < 5; i++)
        cards.push_back(mNumbers[i]);
    offset = 0;

    joker = mJoker % MOD;
    for (int i = 0; i < MOD; i++)
        for (int j = 0; j < MOD; j++)
            sum_cards[i][j] = deque<int>();

    for (int i = 0; i < MOD; i++) {
        int result = 0;
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                for (int k = 0; k < 4; k++) {
                    int val = cards[k];
                    if (val == -1)
                        val = i;
                    result += val;
                }
            }
            else {
                int front = cards[j - 1];
                if (front == -1)
                    front = i;
                int back = cards[j + 3];
                if (back == -1)
                    back = i;
                result = result - front + back;
            }
            sum_cards[i][result % MOD].push_back(j);
        }
    }
}

void putCards(int mDir, int mNumbers[5])
{
    if (mDir) {
        for (int i = 0; i < 5; i++)
            cards.push_back(mNumbers[i]);

        int start = cards.size() - 8;
        for (int i = 0; i < MOD; i++) {
            int result = 0;
            for (int j = 0; j < 5; j++) {
                if (j == 0) {
                    for (int k = 0; k < 4; k++) {
                        int val = cards[start + k];
                        if (val == -1)
                            val = i;
                        result += val;
                    }
                }
                else {
                    int front = cards[start + j - 1];
                    if (front == -1)
                        front = i;
                    int back = cards[start + j + 3];
                    if (back == -1)
                        back = i;
                    result = result - front + back;
                }
                sum_cards[i][result % MOD].push_back(start + offset + j);
            }
        }
    }
    else {
        offset -= 5;

        for (int i = 0; i < 5; i++)
            cards.push_front(mNumbers[4 - i]);

        for (int i = 0; i < MOD; i++) {
            int result = 0;
            for (int j = 4; j >= 0; j--) {
                if (j == 4) {
                    for (int k = 0; k < 4; k++) {
                        int val = cards[j + k];
                        if (val == -1)
                            val = i;
                        result += val;
                    }
                }
                else {
                    int front = cards[j];
                    if (front == -1)
                        front = i;
                    int back = cards[j + 4];
                    if (back == -1)
                        back = i;
                    result = result + front - back;
                }
                sum_cards[i][result % MOD].push_front(offset + j);
            }
        }
    }
}

int findNumber(int mNum, int mNth, int ret[4])
{
    if (mNth - 1 >= sum_cards[joker][mNum].size())
        return 0;
    int start = sum_cards[joker][mNum][mNth - 1];
    for (int i = 0; i < 4; i++)
        ret[i] = cards[start - offset + i];
    return 1;
}

void changeJoker(int mValue)
{
    joker = mValue % MOD;
}