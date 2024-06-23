#include<bits/stdc++.h>
using namespace std;

const int mod = (int)1e9+7;

int main(){
    // SMART-BRUTE-FORCE[DP[TABULATION]]
    int n, x;
    cin >> n >> x;

    vector<int> coins(n), dp(x + 1, 0);
    for(int &coin : coins){
        cin >> coin;
    }

    dp[0] = 1;
    
    for(int sum = 1; sum <= x; sum++){
        int combination = 0;
        for(int j = 0; j < n; j++){
            if(coins[j] <= sum){
                combination = (1ll * combination + dp[sum - coins[j]]) % mod;
            }
        }
        dp[sum] = combination;
    }

    cout << dp[x] << endl;
}