#include<bits/stdc++.h>
using namespace std;

const int mod = (int)1e9+7;

int main(){
    // SMART-BRUTE-FORCE[DP(SPACE-OPTIMIZATION)]
    int n;
    cin >> n;

    // Use a rolling window of size 6 for dp
    vector<int> dp(6, 0);

    // BASE-CASE
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        int current = 0;
        for (int j = 1; j <= 6; ++j) {
            if (i >= j) {
                current = (current + dp[(i - j) % 6]) % mod;
            }
        }
        dp[i % 6] = current;
    }

    cout << dp[n % 6] << endl;
}