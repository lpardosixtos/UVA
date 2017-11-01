#include <bits/stdc++.h>

using namespace std;;

int main(void){

    int a,b,c,d,e;

    cin >> a;

    while(a!=0){
        cin >>b >> c >> d >> e;

        int ans;
        ans=a*b*c*d*d*e*e;
        cout << ans << "\n";

        cin >> a;
    }

return 0;
}
