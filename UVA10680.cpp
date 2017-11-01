#include <bits/stdc++.h>

using namespace std;

long long int sieve_size;
    bitset<10000001> bs;
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

int main(void){

    sieve(10000000);
    int s=primes.size();
    double n, aux;
    int aux1;
    cin >> n;

    while(n!=0){
        if(n==1) cout << 1 << "\n";
        else{
            int ans=1;
            for(int i=0; primes[i]<=n && i<s; i++){
                aux=(log(n)/log(primes[i]));
                aux1=aux;
                if(primes[i]%10==3){
                    if(aux1%4==1) ans=(ans*3)%10;
                    else{
                        if(aux1%4==2) ans=(ans*9)%10;
                        else if(aux1%4==3) ans=(ans*7)%10;
                    }
                }
                else{
                    if(primes[i]%10==7){
                        if(aux1%4==1) ans=(ans*7)%10;
                        else{
                            if(aux1%4==2) ans=(ans*9)%10;
                            else if(aux1%4==3) ans=(ans*3)%10;
                        }

                    }
                    else if(primes[i]%10==9) if(aux1%2==1) ans=(ans*9)%10;
                }
            }

            int p5, p2;
            aux=(log(n)/log(5));
            p5=aux;
            aux=(log(n)/log(2));
            p2=aux;
            p2-=p5;

            if(p2%4==1) ans=(ans*2)%10;
            else{
                if(p2%4==2) ans=(ans*4)%10;
                else{
                    if(p2%4==3) ans=(ans*8)%10;
                    else ans=(ans*6)%10;
                }
            }

            cout << ans << "\n";
        }
        cin >> n;
    }




    return 0;
}
