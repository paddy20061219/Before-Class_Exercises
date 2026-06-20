#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// LeetCode 950 - Reveal Cards In Increasing Order
// Correct version

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.begin(), deck.end());

        queue<int> q;
        vector<int> ans(n);

        // 先把所有位置放進 queue
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        // 從小到大安排每張牌應該放在哪個位置
        for (int card : deck) {
            int index = q.front();
            q.pop();

            ans[index] = card;

            // 模擬題目中「把下一張牌放到牌堆底部」的動作
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};
