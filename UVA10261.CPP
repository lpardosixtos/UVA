#include<bits/stdc++.h>

using namespace std;

int A[200][10001];
int main(void){

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int l;
        cin >> l;
        l=l*100;
        vector<int> cars;
        int aux;
        cin >> aux;
        int maxi=-1;


        if(aux==0){
                cout << 0 << "\n";
        }

        else{



        while(aux!=0){
           cars.push_back(aux);
           cin >> aux;
        }



        int tam=cars.size();
        int maxindex[tam];


        memset(A, -1, sizeof A);
        memset(maxindex, 0, sizeof maxindex);



        if(cars[0]>l){
                cout << 0<< "\n";
        }

        else{


        A[0][cars[0]]=0;
        A[0][0]=cars[0];

        for(int j=1; j<tam; j++){

            for(int k=1; k<l+1; k++){

                if(A[j-1][k]!=-1){


                    if(k+cars[j]<=l){
                        A[j][k+cars[j]]=A[j-1][k];
                        if(j==tam-1){
                            maxi=j;
                        maxindex[j]=k+cars[j];
                        }

                    }

                    if(A[j-1][k]+cars[j]<=l){
                        A[j][k]=A[j-1][k]+cars[j];

                        if(j==tam-1){
                        maxi=j;
                        maxindex[j]=k;
                        }
                    }



                    if(k+cars[j]>l && A[j-1][k]+cars[j]>l && j-1>maxi){

                        maxi=j-1;
                        maxindex[j-1]=k;
                    }


                }
            }
        }

    int maxind;
    int otherind;


    for(int j=tam-1; j>-1; j=j-1){

        if(maxindex[j]!=0){
           maxind=j;
           otherind=maxindex[j];
           break;
           }
    }

    int Ans[maxind];

    for(int j=maxind; j>-1; j=j-1){

        if(j==0){
                if(otherind==0){
                    Ans[j]=0;

                }

                else{
                    Ans[j]=1;
                }

            }

        else{
            if(A[j-1][otherind]==(A[j][otherind]-cars[j])){
                Ans[j]=0;


            }



            else {

                Ans[j]=1;
                otherind=otherind-cars[j];
            }
        }
    }

    cout<< maxi+1 << "\n";

    for(int j=0; j<=maxind; j++){

        if(Ans[j]==0){
            cout << "port" << "\n";
        }

        else{
            cout << "starboard" << "\n";
        }
    }
        }
        }

        cout << "\n";
    }




return 0;
}
