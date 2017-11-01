#include <bits/stdc++.h>

using namespace std;

long long int sieve_size;
    vector<long long int> primes;

long long int A[20000005];

void sieve(long long int up){
    sieve_size = up+1;
    fill(A, A+20000005, 0);
    A[1]=1;
    for(long long int i=2;i<=sieve_size;i++){
        if(A[i]==0){
            A[i]=i;
            primes.push_back(i);
            for(long long int j=i*i;j<=sieve_size;j+=i){
            if(A[j]==0) A[j]=i;
            }
        }
    }

}


long long int numdiv(unsigned long long int n1){
    if(n1==1) return 1;

    long long int aux1=A[n1], aux2=1;
    while(n1%aux1==0){
        aux2++;
        n1=n1/aux1;
    }

    return aux2*numdiv(n1);
}

int main(void){

    sieve(20000003);
    long long int n;
    cin >> n;
    long long int s=primes.size();

    if(n==1){
        cout << n << " " << 1 << "\n";
        cin >> n;
    }

    while(n!=0){
        long long int n1;
        n1=4*n-3;


        if(n1<=20000000){

            cout << n << " " << numdiv(n1) << "\n";
        }
        else{
            long long int ans=1, aux;
            for(long long int i=0; primes[i]*primes[i]<n1 && i<s && n1>20000000; i++){
                aux=1;
                while(n1%primes[i]==0){
                    aux++;
                    n1/=primes[i];
                }
                ans*=aux;
            }

            if(aux==1 || n1>20000000) ans*=2;
            else ans*=numdiv(n1);
            cout << n << " " << ans << "\n";
        }
        cin >> n;
    }

return 0;
}
