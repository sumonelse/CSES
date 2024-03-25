#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 3 || n == 2){
        cout << "NO SOLUTION\n";
        return 0;
    }
    int st = 2;
    while(st <= n){
        cout << st << ' ';
        st += 2;
    }
    st = 1;
    while(st <= n){
        cout << st << ' ';
        st += 2;
    }
}