#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int n = s.size();
    map<char, int> m;
    for(int i = 0; i < n; i++){
        m[s[i]]++;
    }

    int oddCnt = 0;
    for(auto &v : m){
        if(v.second % 2 != 0) oddCnt++;
    }
    if(oddCnt > 1){
        cout << "NO SOLUTION";
        return 0;
    }

    string ans = "";
    char ch = ' ';
    for(auto &v : m){
        if(v.second % 2 != 0){
            ch = v.first;
            continue;
        } 
        for(int i = 1; i <= v.second / 2; i++){
            ans += v.first;
        }
    }

    int k = 1;
    if(ch != ' '){
        for(int i = 1; i <= m[ch]; i++){
            ans += ch;
            k++;
        }
    }
    for(int i = ans.size() - k; i >= 0; i--){
        ans += ans[i];
    }

    cout << ans << endl;
}