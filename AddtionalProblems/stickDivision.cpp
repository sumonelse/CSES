#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln "\n"
#define REP(a, b) for(int i = a; i < b; i++)
#define PRINTARR(arr, a, b) for(int i = a; i < b; i++) cout << arr[i] << " "; cout << ln;
#define vi vector<int> 
#define PB push_back
#define RB pop_back

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--){
        int x, n;
        cin >> x >> n;

        priority_queue<int, vector<int>, greater<int>> pq;
        REP(0, n){
            int a;
            cin >> a;
            pq.push(a);
        }

        ll ans = 0;
        for(int i = 1; i < n; i++){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            ans += a + b;
        }

        cout << ans << ln;
    }
}