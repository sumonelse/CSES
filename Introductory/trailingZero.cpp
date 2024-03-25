#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt = 0, maxCnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') cnt++;
        else cnt = 0;
        
        if(cnt > maxCnt) maxCnt = cnt;
    }

    cout << maxCnt << endl;
}