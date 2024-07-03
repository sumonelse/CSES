#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// MEMOIZATION
// int findCoinComb(int i, int x, int n, int *coins, vector<vector<int>> &dp){
//     if(x == 0) return 1;
//     if(i == n) return 0;

//     if(dp[i][x] != -1) return dp[i][x];

//     int notTake = findCoinComb(i + 1, x, n, coins, dp) % MOD;
//     int take = 0;
//     if(coins[i] <= x){
//         take = findCoinComb(i, x - coins[i], n, coins, dp) % MOD;
//     }

//     return dp[i][x] = (notTake + take) % MOD;
// }

int main(){
    // SMART-BRUTE-FORCE[DP]
    /**
     * Time : TOUGH :) but COOL phew...
     * Help : YES
     */
    int n, x;
    cin >> n >> x;

    int coins[n];

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    // vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // cout << findCoinComb(0, x, n, coins, dp) << endl;

    vector<int> prev(x + 1, 0);
    prev[0] = 1;

    for(int i = n - 1; i >= 0; i--){
        vector<int> curr(x + 1, 0);
        curr[0] = 1;
        for(int sum = 1; sum <= x; sum++){
            int notTake = prev[sum] % MOD;
            int take = 0;
            if(coins[i] <= sum){
                take = curr[sum - coins[i]] % MOD;
            }
            curr[sum] = (notTake + take) % MOD;
        }
        prev = curr;
    }

    cout << prev[x] << endl;

    return 0;
}