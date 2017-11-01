#include <bits/stdc++.h>

using namespace std;

int main(void){

    long long int N, d, sum, uno;
    uno=1;

    while(cin >> N){
        cin >> d;
         sum=(uno<<(d+1));
        sum--;
        if(sum>=N){

            cout << "yes\n";
        }
        else cout << "no\n";


    }



return 0;
}
