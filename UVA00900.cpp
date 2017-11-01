#include <bits/stdc++.h>

using namespace std;

int main(void){

    int fib[51];
    fib[0]=1;
    fib[1]=1;
    for(int i=2; i<51; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }

    int n;
    cin >> n;
    while(n!=0){
        cout << fib[n] << "\n";

        cin >> n;
    }


return 0;
}
