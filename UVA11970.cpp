#include<bits/stdc++.h>

using namespace std;

int main(void){

    int T, N;
    cin >> T;

    for(int i=0; i<T; i++){

        cin >> N;
        int cont=0;
        vector<int> ans;

        cout << "Case "<< i+1 << ":";

        for(int z=1; z*z<N; z++){

            if(N%z==0) ans.push_back(N-pow(z,2));
        }

        for(int j=ans.size()-1; j>=0; j--){
            cout << " " << ans[j];
        }
        cout << "\n";
    }



return  0;
}
