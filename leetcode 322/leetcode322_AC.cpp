#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 322 - Coin Change
// AC version

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for(int money = 1; money <= amount; money++){
            for(int i = 0; i < coins.size(); i++){
                int coin = coins[i];

                if(money - coin >= 0){
                    dp[money] = min(dp[money], dp[money - coin] + 1);
                }
            }
        }

        if(dp[amount] == amount + 1){
            return -1;
        }

        return dp[amount];
    }
};
