#include<bits/stdc++.h>
using namespace std;

int findMin(int n, vector<int> &dp){
    if(n == 0) return 0;

    // cout << "n: " << n << endl;

    if(dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    int temp = n;
    while(temp > 0){
        int digit = temp % 10;
        if(digit != 0){
            ans = min(ans, findMin(n - digit, dp) + 1);
        } 
        temp /= 10;
    }

    return dp[n] = ans;
}

int main(){
    // SMART-BRUTE-FORCE[DP(MEMOIZATION)]
    /**
     * Time : EASY :)...
     * Help : NO
     */
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << findMin(n, dp) << endl;
}