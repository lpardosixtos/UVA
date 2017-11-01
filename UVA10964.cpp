#include <bits/stdc++.h>

using namespace std;

int main(void){

    int a, b;
    cin >> a;
    cin >> b;

    while(a!=-1){


        int auxa=sqrt(a/2), auxb=sqrt(b/2);
        int lessa=2*auxa*(auxa+1), lessb=2*auxb*(auxb+1);
        int inda=0, indb=0;
        double xa, ya, xb, yb;


        if(lessa>=a){
            auxa--;
            lessa=2*auxa*(auxa+1);
        }

        if(lessb>=b){
            auxb--;
            lessb=2*auxb*(auxb+1);
        }


        if(lessa+auxa+1<=a){
            lessa+=auxa+1;
            inda=1;
            if(lessa+auxa+1<=a){
                lessa+=auxa+1;
                inda=2;
                if(lessa+auxa+1<=a){
                    lessa+=auxa+1;
                    inda=3;
                }
            }
        }
        if(lessb+auxb+1<=b){
            lessb+=auxb+1;
            indb=1;
            if(lessb+auxb+1<=b){
                lessb+=auxb+1;
                indb=2;
                if(lessb+auxb+1<=b){
                    lessb+=auxb+1;
                    indb=3;
                }
            }
        }


        if(inda==0){
            ya=a-lessa;
            xa=-auxa-1+(a-lessa);
        }
        else{
            if(inda==1){
                ya=auxa+1-(a-lessa);
                xa=(a-lessa);
            }
            else{
                if(inda==2){
                    ya=lessa-a;
                    xa=auxa+1-(a-lessa);
                }
                else{
                    ya=-auxa-1+(a-lessa);
                    xa=lessa-a;
                }
            }
        }

        if(indb==0){
            yb=b-lessb;
            xb=-auxb-1+(b-lessb);
        }
        else{
            if(indb==1){
                yb=auxb+1-(b-lessb);
                xb=(b-lessb);
            }
            else{
                if(indb==2){
                    yb=lessb-b;
                    xb=auxb+1-(b-lessb);
                }
                else{
                    yb=-auxb-1+(b-lessb);
                    xb=lessb-b;
                }
            }
        }

        double d;
        d=sqrt(pow(xa-xb,2)+pow(ya-yb, 2));

        cout << fixed << setprecision(2) << d << "\n";


        cin >> a;
        cin >> b;
    }



return 0;
}
