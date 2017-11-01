#include <bits/stdc++.h>

using namespace std;

int main(void){

    int d;

    cin >> d;

    while(d!=0){

        int sum=0;
        int cont=0;

        while(sum!=d){
            if(2*sum+1>=d) sum=d;
            else{
                sum=2*sum+1;
                cont++;
            }
        }

        cout << cont << "\n";


         cin >> d;


    }


return 0;
}
