/**
 *  @Tip: Only ALLOCATE new room when least departure time is >= new arrival time OR when there is no one to depart
 *        else replace the old with new person 
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<pair<pair<int, int>, int>> v(n);
        REP(0, n){
            cin >> v[i].first.first >> v[i].first.second;
            v[i].second = i; // store the original index
        }

        sort(v.begin(), v.end());

        vi ans(n);
        int lastRoom = 0;

        // stores departure time and allocated room no.
        priority_queue<pair<int, int>> pq;
        REP(0, n){
            if(pq.empty() || -pq.top().first >= v[i].first.first){
                lastRoom++;
                // make the departure time negative so that we create a min heap
                pq.push({-v[i].first.second, lastRoom});
                ans[v[i].second] = lastRoom;
            }else{
                // accessing the minimum departure time
                auto minDept = pq.top();
                pq.pop();
                int roomAlloc = minDept.second;
                pq.push({-v[i].first.second, roomAlloc});
                ans[v[i].second] = roomAlloc;
            }
        }

        cout << lastRoom << ln;
        REP(0, n){
            cout << ans[i] << ' ';
        }cout << ln;
    }
}