#include<bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

int main(){
    // SMART-BRUTE-FORCE[DP(SPACE OPTIMIZATION)]
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<int> prev(n, 0);

    // Filling the first-row
    prev[0] = grid[0][0] == '*' ? 0 : 1;
    for(int y = 1; y < n; y++){
        if(grid[0][y] != '*') prev[y] = prev[y - 1];
    }

    for(int x = 1; x < n; x++){
        vector<int> curr(n); // To store all paths of Current Row
        for(int y = 0; y < n; y++){
            if(grid[x][y] == '*'){
                curr[y] = 0;
                continue;
            }

            int left = 0, up = prev[y];
            if(y > 0) left = curr[y - 1];
            
            curr[y] = (left + up) % MOD;
        }
        prev = curr;
    }

    cout << prev[n - 1] << endl;
}