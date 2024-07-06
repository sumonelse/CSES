#include<bits/stdc++.h>
using namespace std;

int main(){
    // SMART-BRUTE-FORCE[DP(SPACE-OPTIMIZATION)]
    /*
    The Question based on 0/1 KNAPSACK(BOUNDED) as we can buy the book at max ONCE.
    Observations:
    1) Here, x -> the TOTAL AMT. to spend is the same, as the TOTAL SPACE in bag to use in KNAPSACK.
    2) Get MAX PAGES is same, as Get MAX PROFIT in KNAPSACK.
    */
    int n, x;
    cin >> n >> x;

    int price[n], pages[n];
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<int> prev(x + 1, 0);
    // dp[i][x] represents maximum pages that we can from '0' to 'i' having amount 'x'

    // Handling the BASE-CASE
    for(int budget = 1; budget <= x; budget++){
        if(price[0] <= budget){
            prev[budget] = pages[0];
        }
    }

    for(int i = 1; i < n; i++){
        vector<int> curr(x + 1);
        curr[0] = 0;
        for(int budget = 1; budget <= x; budget++){
            int notTake = prev[budget];
            int take = 0;
            if(price[i] <= budget){
                take = pages[i] + prev[budget - price[i]];
            }
            curr[budget] = max(notTake, take);
        }
        prev = curr;
    }

    cout << prev[x] << endl;
}