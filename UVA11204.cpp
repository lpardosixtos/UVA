#include <bits/stdc++.h>

using namespace std;

int main(void){

    int T;
    int N, M;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N >> M;

        int A[N+1];
        for(int j=1; j<N+1; j++){
            A[j]=0;
        }
        int aux;
        for(int j=0; j<M; j++){
            for(int k=1; k<N+1; k++){
                cin >> aux;
                if(aux==1) A[k]++;
            }
        }
        unsigned long long int ans=1;
        for(int j=1; j<=N; j++){
            if(A[j]>0) ans*=A[j];
        }
        cout << ans << "\n";

    }

return 0;
}
