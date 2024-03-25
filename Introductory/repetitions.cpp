#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int maxLen = 1, cnt = 0, size = s.size();
    for(int i = 1; i < size; i++){
        if(s[i] == s[i - 1]){
            cnt++;
        }else{
            cnt = 0;
        }
        if(cnt + 1 > maxLen){
            maxLen = cnt + 1;
        }
    }
    
    cout << maxLen << endl;
}