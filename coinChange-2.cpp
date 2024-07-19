#include <bits/stdc++.h>
using namespace std;


int coinChangeWays(vector<int> coins, int amount) {

    vector<int> dp(amount+1);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j < dp.size(); j++) {
            if (coins[i] <= j) {
                dp[j] += dp[j-coins[i]];
            }
        }
    }
    return dp[amount];
}

int main() {
    vector<int> moedas = {1,2,5};
    int valor = 5;
    cout << coinChangeWays(moedas, valor) << '\n';
    // Output: 4
    // Explanation: there are four ways to make up the amount:
    // 5=5
    // 5=2+2+1
    // 5=2+1+1+1
    // 5=1+1+1+1+1
}