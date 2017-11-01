#include <bits/stdc++.h>

using namespace std;

long long int a1, a2;
long long int sieve_size;
long long int A[500005];
    vector<long long int> primes;

void sieve(long long int up){
    sieve_size = up+1;
    for(long long int i=2;i<=sieve_size;i++) if(A[i]==0){
        for(long long int j=i*i;j<=sieve_size;j+=i){
            if(A[j]==0) A[j]=i;
        }
        primes.push_back((int) i);
        A[i]=i;
    }
}

long long int memg[500005];
long long int g(long long int n){
    if(memg[n]!=0) return memg[n];
    if(n==1) return 0;
    long long int aux=n;
    long long int cont=0;
    while(aux%A[n]==0){

        cont+=A[n];
        aux/=A[n];
    }
    return cont+g(aux);


}

long long int mem[500005];
long long int f(long long int n){
    if(mem[n]==0){
        if(n==g(n)){
            mem[n]++;
            return mem[n];
        }
        else{
            mem[n]=f(g(n))+1;
            return mem[n];
        }
    }
    return mem[n];

}


int main(void){
    fill(A, A+500005, 0);
    fill(mem, mem+500005, 0);
    fill(memg, memg+500005, 0);
    sieve(500001);
    int T;
    long long int n, m;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >>n >> m;
        long long int aux=min(n,m), aux1=max(n,m), ans=0;
        for(long long int j=aux; j<=aux1; j++){
            ans=max(ans, f(j));

        }
        cout << "Case #" << i+1 << ":\n" << ans << "\n";
    }



}

