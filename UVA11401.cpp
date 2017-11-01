#include<bits/stdc++.h>

using namespace std;

unsigned long long int f(unsigned long long int n){
    return (n*(n-1)*(n-2)+(n-2)*(n-3)*(n-4)+3*(n-4)*(n-2))/24;
}

int main(void){

    unsigned long long int n;
    cin >> n;
    while(n>=3){
        if(n%2==0){
            cout << f(n) << "\n";
        }
        else{
            n--;
            cout << f(n)+((n/2)-1)*(n/2) << "\n";
        }

        cin >> n;
    }



return 0;
}
