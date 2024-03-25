#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long curr = 0, prevMx = 0;
    long long minMove = 0;

    for(int i = 0; i < n; i++){
        cin >> curr;
        if(curr < prevMx){
            long long diff = prevMx - curr;
            minMove += diff;
            prevMx = curr + diff;
        }else{
            prevMx = curr;
        }
    }

    cout << minMove << "\n";
}