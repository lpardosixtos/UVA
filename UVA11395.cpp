#include <bits/stdc++.h>

using namespace std;

int f(long long int n, int i){
    if(n==1 || n==2) return 0;

    if(i&1){
        long long int aux=sqrt(n);
        return aux-(log(sqrt(n))/log(2))-1+f(n/2, i++);
    }

    return f(n/2, i++);

}

int main(void){

    long long int n;
    cin >>n;
    while(n!=0){
        long long int sq=sqrt(n);
        long long int sq2=sqrt(n/2);
        long long int ans;
        if(n==1) ans=1;
        else{
            if(n==3) ans=1;
            else{
                if(n==4) ans=3;
                else{
                    if(n==5) ans=4;
                    else ans=n-(sq+sq2+f(n/2,2));
                }
            }
        }



        cout << ans << "\n";
        cin >> n;
    }


    return 0;
}
