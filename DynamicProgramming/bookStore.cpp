#include<bits/stdc++.h>
using namespace std;

int main(){
    // SMART-BRUTE-FORCE[DP(TABULATION)]
    int n, x;
    cin >> n >> x;

    int price[n], pages[n];
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    // dp[i][x] represents maximum pages that we can from '0' to 'i' having amount 'x'

    // Handling the BASE-CASE
    for(int budget = 1; budget <= x; budget++){
        if(price[0] <= budget){
            dp[0][budget] = pages[0];
        }
    }

    for(int i = 1; i < n; i++){
        dp[i][0] = 0;
        for(int budget = 1; budget <= x; budget++){
            int notTake = dp[i - 1][budget];
            int take = 0;
            if(price[i] <= budget){
                take = pages[i] + dp[i - 1][budget - price[i]];
            }
            dp[i][budget] = max(notTake, take);
        }
    }


    cout << dp[n-1][x] << endl;
}