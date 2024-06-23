#include<iostream>
using namespace std;

void toh(int n, int src, int helper, int dest){
    if(n == 1){
        cout << src << " " << dest << endl;
        return;
    }
    
    toh(n - 1, src, dest, helper);
    cout << src << " " << dest << endl;
    toh(n - 1, helper, src, dest);
}

int main(){
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    toh(n, 1, 2, 3);
}