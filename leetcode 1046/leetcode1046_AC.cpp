#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode 1046 - Last Stone Weight
// AC version

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // 把所有石頭重量放進 max heap
        for(int stone : stones){
            pq.push(stone);
        }

        // 每次拿出最重的兩顆石頭互撞
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            if(first != second){
                pq.push(first - second);
            }
        }

        if(pq.empty()){
            return 0;
        }

        return pq.top();
    }
};
