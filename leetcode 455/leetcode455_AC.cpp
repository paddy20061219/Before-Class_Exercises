#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 455 - Assign Cookies
// AC version

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;
        int count = 0;

        while(child < g.size() && cookie < s.size()){
            // 如果這塊餅乾可以滿足這個小孩
            if(s[cookie] >= g[child]){
                count++;
                child++;
                cookie++;
            } else {
                // 餅乾太小，就換下一塊比較大的餅乾
                cookie++;
            }
        }

        return count;
    }
};
