#include <bits/stdc++.h>
using namespace std;

// quantas moedas eu preciso pra atingir amount
int coinChange(vector<int> coins, int amount) {

    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
    }
    return dp[amount];
}

int main() {
    vector<int> nums = {1, 5};
    int amount = 103;
    cout << coinChange(nums, amount) << '\n';
    // ans = 23
}