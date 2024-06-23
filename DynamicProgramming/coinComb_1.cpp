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
        for(int j = 0; j < n; j++){
            if(coins[j] <= sum){
                dp[sum] = (1ll * dp[sum] + dp[sum - coins[j]]) % mod;
            }
        }
    }

    cout << dp[x] << endl;
}