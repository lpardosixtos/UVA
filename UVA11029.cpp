#include <bits/stdc++.h>

using namespace std;

int exp(int n, int k){
    if(k==1) return n;
    if(k & 1){
        int temp=exp(n,(k-1)/2);
        temp*=temp*n;
        return temp%1000;
    }

    else{
        int temp=exp(n, k/2);
        temp*=temp;
        return temp%1000;
    }
}



int main(void){

    int T, n, k;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> n >> k;
        long double l=log10(n), aux1;
        int aux=floor(k*l);
        aux1=k*l-aux+2;
        long double x=pow(10, aux1);

        cout << floor(x) << "...";

        aux=n%1000;
        aux=exp(aux, k);

        if(aux==0){
            cout << "000\n";
        }
        else{
            if(aux<10){
                cout << "00" << aux << "\n";
            }
            else{
                if(aux<100){
                    cout << "0" << aux << "\n";
                }
                else cout << aux << "\n";

            }
        }


    }


    return 0;
}
