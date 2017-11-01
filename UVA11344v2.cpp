#include<bits/stdc++.h>

using namespace std;

int main(void){

int N, ns;
    string M;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> M >> ns;
        int s=M.size();
        int S[ns], aux1, ind=0, num=0;
        for(int j=0; j<ns; j++){
            cin >> S[j];
        }
        for(int j=0; j<ns; j++){
            for(int k=0; k<s; k++){
                aux1=M[k]-'0';
                num=(10*num+aux1)%S[j];
            }
            if(num!=0){
                j=ns;
                ind=1;
            }
        }
        if(ind!=0) cout << M << " - Simple.\n";
        else cout << M << " - Wonderful.\n";

    }
}
