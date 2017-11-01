#include <bits/stdc++.h>

using namespace std;

long long int sieve_size;
    bitset<100000> bs;
    vector<int> primes;

void sieve(long long int up){
    sieve_size = up+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(long long int i=2;i<=sieve_size;i++) if(bs[i]){
        for(long long int j=i*i;j<=sieve_size;j+=i) bs[j]=0;
        primes.push_back((int) i);
    }
}

bool isPrime(long long int N){
    if(N<=sieve_size) return bs[N];
    for(int i=0;i<(int)primes.size() && primes[i]*primes[i]<=N;i++)
        if(N%primes[i]==0) return false;
    return true;
}



int main(void){

    sieve(100000);

    long long int L, U;
    long long int p, u;
    long long int m, n;
    int d, D;
    long long int l1, l2, h1, h2;

    while(cin>> L >> U){

        p=0;
        u=0;
        d=3000000;
        D=0;


        for(long long int i=L; i<=U; i++){

        if(u==0 && isPrime(i)){

           p=i;
           n=i;

        }

        if(isPrime(i)){

            u=i;

        }

        if(u!=0 && isPrime(i)){

            m=n;
            n=i;

            if(n-m>D){

            D=n-m;
            h1=m;
            h2=n;

            }

            if(n-m<d && n-m!=0){

            d=n-m;
            l1=m;
            l2=n;

            }

        }




        }

    if(u==0 || u==p){

        cout<< "There are no adjacent primes."<<"\n";

    }

    else {
        cout << l1 << "," << l2 << " are closest" << ", " << h1 << "," << h2 << " are most distant." << "\n";
    }

    }






return 0;
}
