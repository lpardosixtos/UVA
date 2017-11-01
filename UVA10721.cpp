#include <bits/stdc++.h>

using namespace std;

int m;
long long int mem[51][51];
long long int BC(int n, int k){
    if(n<=0) return 0;
    if(mem[n][k]!=-1) return mem[n][k];
    if(k==1 && m<n){
        mem[n][k]=0;
        return 0;
    }
    if(k==1 && n<=m){
        mem[n][k]=1;
        return 1;
    }
    mem[n][k]=0;
    for(int i=1; i<=m; i++){
        mem[n][k]+=BC(n-i, k-1);
    }
    return mem[n][k];
}


int main(void){

    int n, k;
    while(cin >> n){
        memset(mem, -1, sizeof mem);
        cin >>k >> m;
        cout << BC(n,k) << "\n";
    }

    return 0;
}
