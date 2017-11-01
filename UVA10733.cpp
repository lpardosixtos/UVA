#include <bits/stdc++.h>

using namespace std;

int main(void){

    long long int n;
    cin >> n;
    while(n!=0){

        long long int ans;
        ans=(n*n*n*n*n*n+3*n*n*n*n+12*n*n*n+8*n*n)/24;
        cout << ans << "\n";
        cin >> n;
    }

return 0;
}
