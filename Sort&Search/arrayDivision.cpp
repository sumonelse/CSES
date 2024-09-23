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
	// if (!name.empty()) {
	// 	freopen((name + ".in").c_str(), "r", stdin);
	// 	freopen((name + ".out").c_str(), "w", stdout);
	// }
}

bool check(ll mid, int k, vi& arr){
    int n = arr.size();
    int i = 0;
    ll sum = 0;
	while(k > 1){
        while(i < n){
            sum += arr[i++];
            if(sum > mid){
                i--;
                break;
            }
        }
        sum = 0;
        k--;
    }
    for(int j = i; j < n; j++){
        sum += arr[j];
    }
    return sum <= mid;
}


int main(){
    setIO();

    int t = 1;
    // cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;

        ll sum = 0;
        vi arr(n);
        REP(0, n){
            cin >> arr[i];
            sum += arr[i];
        }

		ll st = 1, end = sum;
		ll ans = 0;

		while(st <= end){
			ll mid = st + (end - st) / 2;
			if(check(mid, k, arr)){
				ans = mid;
				end = mid - 1;
			}else{
				st = mid + 1;
			}
		}

		cout << ans << ln;
    }
} 