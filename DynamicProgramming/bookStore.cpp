#include<bits/stdc++.h>
using namespace std;

int findMaxPage(int i, int budget, int *price, int *pages, vector<vector<int>> &dp){
    // BASE-CASE
    if(i == 0){
        return (price[i] <= budget ? pages[i] : 0);
    }

    if(dp[i][budget] != -1) return dp[i][budget];

    int notTake = findMaxPage(i - 1, budget, price, pages, dp);
    int take = 0;
    if(price[i] <= budget){
        take = pages[i] + findMaxPage(i - 1, budget - price[i], price, pages, dp);
    }

    return dp[i][budget] = max(notTake, take);
}

int main(){
    // SMART-BRUTE-FORCE[DP(MEMOIZATION)]
    int n, x;
    cin >> n >> x;

    int price[n], pages[n];
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    cout << findMaxPage(n - 1, x, price, pages, dp) << endl;
}