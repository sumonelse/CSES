#include<bits/stdc++.h>
using namespace std;

int main(){
    // SMART-BRUTE-FORCE[DP(TABULATION)]
    /**
     * Time : EASY :)...
     * Help : NO
     */
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp > 0){
            int digit = temp % 10;
            if(digit != 0){
                dp[i] = min(dp[i], dp[i - digit]+ 1);
            } 
            temp /= 10;
        }
    }

    cout << dp[n] << endl;
}