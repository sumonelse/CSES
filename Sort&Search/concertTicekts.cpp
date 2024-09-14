#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t = 1;
    // cin >> t;

    while (t--){
        int n, m;
        cin >> n >> m;

        int x;
        multiset<int, greater<int>> price;
        for(int i = 0; i < n; i++){
            cin >> x;
            price.insert(x);
        } 

        for(int i = 0; i < m; i++){
            cin >> x;
            auto ans = price.lower_bound(x);
            
            if(ans == price.end()){
                cout << -1 << endl;
            }else{
                cout << *(ans) << endl;
                price.erase(ans);
            }
        }
    }
}