#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 56 - Merge Intervals
// AC version

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if(intervals.size() == 0){
            return ans;
        }

        // 先照起點由小到大排序
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            int lastEnd = ans.back()[1];

            // 如果目前區間的起點 <= 前一段的終點，代表有重疊
            if(currentStart <= lastEnd){
                ans.back()[1] = max(ans.back()[1], currentEnd);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
