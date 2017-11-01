#include <bits/stdc++.h>

using namespace std;

int main(void){

    unsigned long long int fib[51];
    fib[0]=1;
    fib[1]=2;
    for(int i=2; i<51; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    int t, n;

    cin >> t;

    for(int i=1; i<=t; i++){
        cin >> n;
        cout << "Scenario #" << i << ":\n";
        cout << fib[n] << "\n";
        cout << "\n";
    }

return 0;
}
