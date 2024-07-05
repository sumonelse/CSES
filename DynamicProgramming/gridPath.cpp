#include<bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

int main(){
    // SMART-BRUTE-FORCE[DP(TABULATOIN)]
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(grid[x][y] == '*'){
                dp[x][y] = 0;
                continue;
            }

            int left = 0, up = 0;
            if(y > 0) left = dp[x][y - 1];
            if(x > 0) up = dp[x - 1][y];
            
            dp[x][y] += (left + up) % MOD;
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}