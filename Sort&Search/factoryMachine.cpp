/**
 *  @Tip: Take initial range between 1 to 1e18, cauz in worst case(n = 1, m = 1e9, [1e9])
 */

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

bool check(ll mid, int targetCnt, vi& time){
	int n = time.size();
	ll canMake = 0;
	REP(0, n){
		canMake += mid / time[i];
		if(canMake >= targetCnt) return true;
	}
	return false;
}


int main(){
    setIO();

    int t = 1;
    // cin >> t;

    while (t--){
        int machineCnt, targetCnt;
		cin >> machineCnt >> targetCnt;
		
		vi time(machineCnt);
		REP(0, machineCnt) cin >> time[i];

		ll st = 1, end = 1e18 * 1ll;
		ll ans = 0;

		while(st <= end){
			ll mid = st + (end - st) / 2;
			if(check(mid, targetCnt, time)){
				ans = mid;
				end = mid - 1;
			}else{
				st = mid + 1;
			}
		}

		cout << ans << ln;
        // Approach 2: Can also use map to store frequency and then do [ans += mid / (it.first) * it.second]
    }
} 