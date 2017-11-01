#include <bits/stdc++.h>

using namespace std;

int A[52];
int mem[52][52];

int cost(int s,  int e){

    int aux;


    if(mem[s][e]!=-1){

                return mem[s][e];

            }

    if(e==s+2){

        mem[s][e]=A[e]-A[s];
        return mem[s][e];

    }

    if(e-s<2){

        mem[s][e]=0;
        return 0;
    }

    aux=A[e]-A[s]+cost(s,s+1)+cost(s+1, e);

    for(int i=s+2; i<e; i++){

        aux=min(aux, A[e]-A[s]+cost(s, i)+cost(i, e));
    }
    mem[s][e]=aux;

    return aux;







}


int main(void){

     int l, n;
    while(true!=false){

        cin >> l;

        memset(mem, -1, sizeof mem);

        if(l==0){

                return 0;

        }

        cin >> n;

        A[0]=0;
        A[n+1]=l;

        for(int i=1; i<=n; i++){

        cin >> A[i];
        }

        cout << "The minimum cutting is " << cost(0, n+1) << "."<< "\n";

    }

return 0;
}
