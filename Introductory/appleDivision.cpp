#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll findAns(int index, ll sum1, ll sum2, vector<int>& v){
    if(index == (int)v.size()){
        return abs(sum1 - sum2);
    }

    // Including in first group means Excluding from second group
    ll firstInc = findAns(index + 1, sum1 + v[index], sum2, v);
    // Including in second group means Excluding from first group
    ll secondInc = findAns(index + 1, sum1, sum2 + v[index], v);

    return min(firstInc, secondInc);
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int &t: v) cin >> t;

    cout << findAns(0, 0, 0, v) << endl;
}