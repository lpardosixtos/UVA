#include<bits/stdc++.h>

using namespace std;

int mem[502][502];
int n,k;
int weights(int i, int l){

    int aux;
    int sum;

    if(mem[i][l]!=-1){

        return mem[i][l];
    }

    if(i+1==l || i==l || i+2==l){

        mem[i][l]=0;
        return 0;
    }
        aux=((l-i-1)*(i+1+k))+weights(i+1, l);

        for(int m=i+2; m<l; m++){

            aux=min(aux, ((l-i-1)*(m+k))+weights(i,m)+weights(m,l));

        }

        mem[i][l]=aux;
        return aux;
    }



int main(void){


    int t;
    cin >> t;
    for(int r=0; r<t; r++){
        cin >> n>> k;
        memset(mem, -1, sizeof mem);
        cout << "Case " << r+1 << ": " << weights(0,n+1) << "\n";





        }







return 0;
}
