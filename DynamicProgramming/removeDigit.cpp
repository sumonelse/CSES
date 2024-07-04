#include<bits/stdc++.h>
using namespace std;

int getMax(int n){
    int maxi = 0;
    while(n > 0){
        maxi = max(maxi, n % 10);
        n /= 10;
    }
    return maxi;
}

int findMin(int n){
    if(n == 0) return 0;

    // cout << "n: " << n << endl;

    int maxi = getMax(n);
    int ans = findMin(n - maxi) + 1;
    return ans;
}

int main(){
    // GREEDY SOLUTION
    /**
     * Time : EASY :)...
     * Help : NO
     */
    int n;
    cin >> n;

    cout << findMin(n) << endl;
}