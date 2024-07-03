#include<bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

int findPath(int x, int y, vector<string> &grid, vector<vector<int>> &dp){
    // Out of BOUNDS
    if(x < 0 || y < 0) return 0;
    // Trap Cell(Not allowed to move)
    if(grid[x][y] == '*') return 0;

    // Destination Reached
    if(x == 0 && y == 0) return 1;

    // Memoize check
    if(dp[x][y] != -1) return dp[x][y];

    int left = findPath(x, y - 1, grid, dp) % MOD;
    int up = findPath(x - 1, y, grid, dp) % MOD;

    return dp[x][y] = (left + up) % MOD;
}

int main(){
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << findPath(n - 1, n - 1, grid, dp) << endl;
}