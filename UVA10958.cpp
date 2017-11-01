#include <bits/stdc++.h>

using namespace std;

long long int sieve_size;
    bitset<10000> bs;
    vector<int> primes;

void sieve(long long int up){
    primes.push_back(0);
    sieve_size = up+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(long long int i=2;i<=sieve_size;i++) if(bs[i]){
        for(long long int j=i*i;j<=sieve_size;j+=i) bs[j]=0;
        primes.push_back((int) i);
    }
}


int main(void){

    sieve(1000);
    int s;
    s=primes.size();
    int A[s];

    int m, n, p, cases=0;
    cin >> m >> n >> p;
    while(m!=0 || n!=0 || p!=0){
        cases++;
        long long ans=1;

        if(m!=0 && n!=0){
            for(int i=1; i<s; i++){
                A[i]=0;
                while(m%primes[i]==0) {
                    A[i]++;
                    m=m/primes[i];
                }
                while(n%primes[i]==0){
                    A[i]++;
                    n=n/primes[i];
                }
                while(p%primes[i]==0){
                    A[i]+=2;
                    p=p/primes[i];
                }
            }

            for(int i=1; i<s; i++){
            ans*=A[i]+1;
            }
            ans=2*ans-1;
            cout << "Case " <<cases << ": " << ans << "\n";
        }
        else{
            cout << "Case " <<cases << ": " << ans << "\n";
        }

        cin >> m >> n >> p;
    }



return 0;
}
