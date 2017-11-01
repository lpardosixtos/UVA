#include <bits/stdc++.h>

using namespace std;

int s;

long long int sieve_size;
    bitset<20000005> bs;
    vector<int> primes;
    vector<int> tprimes;

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
    for(int i=0;i<(int)primes.size();i++)
        if(N%primes[i]==0) return false;
    return true;
}

void twin(){
    for(int i=0; i<s-1; i++){
        if(primes[i+1]-primes[i]==2){
            tprimes.push_back(primes[i]);
        }
    }


}

int main(void){

    sieve(20000000);
    s=primes.size();
    twin();

    int S;
    while(cin >> S){
        int aux=tprimes[S-1];
        cout << "(" << aux << ", " << aux+2 << ")" << "\n";
    }



    return 0;
}

