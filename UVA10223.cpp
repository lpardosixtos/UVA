#include <bits/stdc++.h>

using namespace std;


int main(void){

    long long int cat[20];
    cat[0]=1;
    for(int i=0; i<19; i++){
        cat[i+1]=(2*(2*i+1)*cat[i])/(i+2);
    }

    int n;
    while(cin>> n){
        for(int i=1; i<20; i++){
            if(n==cat[i]){
                cout << i << "\n";
                i=20;
            }
        }
    }



return 0;
}
