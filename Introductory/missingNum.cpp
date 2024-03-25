#include<iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n;

    int serXor = 0, inpXor = 0;
    for(int i = 1; i < n; i++){
        cin >> x;
        serXor ^= i;
        inpXor ^= x;
    }
    serXor ^= n;
    
    int ans = serXor ^ inpXor;
    cout << ans << "\n";
}