#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln "\n"
#define REP(a, b) for(int i = a; i < b; i++)
#define PRINTARR(arr, a, b) for(int i = a; i < b; i++) cout << arr[i] << " "; cout << ln;
#define vi vector<int> 
#define PB push_back
#define RB pop_back
void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
}

bool check(ll mid, int n){
    ll cnt = 0;
    for(int row = 1; row <= n; row++){
        cnt += min(n * 1ll, mid / row);
    }
    return cnt >= (n * 1ll * n + 1) / 2;
}

int main(){
    setIO();

    int t = 1;
    // cin >> t;

    while(t--){
        int n;
        cin >> n;

        ll st = 1, end = n * 1ll * n;

        while(st < end) {
            ll mid = (st + end) * 1ll / 2;
            if(check(mid, n)){
                end = mid;
            }else{
                st = mid + 1;
            }
        }

        cout << end << ln;
    }
	
} 