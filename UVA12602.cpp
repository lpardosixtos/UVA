#include <bits/stdc++.h>

using namespace std;

int main(void){

    int N;
    cin >> N;
    int first, aux, second;
    char c;

    for(int i=0; i<N; i++){

        first=0;
        second=0;

        for(int j=1; j<=3; j++){

            cin >> c;
            aux=c-65;
            first=first*26+aux;
        }
        cin >> c;

        for(int j=0; j<4; j++){

            cin >> c;
            aux=c-'0';
            second=second*10+aux;
        }

        if(second-first<=100 && first-second<=100) cout << "nice\n";
        else cout << "not nice\n";
    }


return 0;
}
