#include<iostream>
using namespace std;

#define ll long long
int main(){
    int t;
    cin >> t;

    while(t--){
        ll x, y;
        cin >> x >> y;

        ll ans;
        ll mxNum = max(x, y);
        ll mid = mxNum * mxNum - (mxNum - 1);

        if(mxNum % 2 != 0){
            ans = mid + (y - x);
        }else{
            ans = mid + (x - y);
        }
        cout << ans << endl;
    }
}