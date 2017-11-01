#include<bits/stdc++.h>

using namespace std;

int main(void){

    long long int n;


    cin >> n;

    while(n>=0){

        if(n==1){
            cout << 0 << "%" << "\n";
            cin >> n;
        }
        else{
        cout <<  (n*100)/4 << "%" << "\n";
        cin >> n;
        }
    }


return 0;
}
