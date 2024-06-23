#include<bits/stdc++.h>
using namespace std;

int main(){
    // SMART-BRUTE-FORCE[DP(TABULATION)]
    int n, x;
    cin >> n >> x;

    int coin[n];
    vector<int> dp(x + 1, -1);

    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }

    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        int mini = (int)1e9;
        for(int j = 0; j < n; j++){
            if(coin[j] <= i){
                mini = min(mini, dp[i - coin[j]] + 1);
            }
        }
        dp[i] = mini;
    }

    cout << (dp[x] != 1e9 ? dp[x] : -1) << endl;
}