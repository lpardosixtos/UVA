    #include <bits/stdc++.h>

    using namespace std;

    long long int x,y, d;

    void comb(long long int a, long long int b){

        if(b==0){
            x=1;
            y=0;
            d=a;
            return;
        }

        comb(b, a%b);
        long long int x1=y;
        long long int y1=x-(a/b)*y;
        x=x1;
        y=y1;

    }


    int main(void){

        long long int n, a, b, c1, c2;
        cin >> n;
        while(n!=0){
            cin >> c1 >> a >> c2 >> b;
            comb(a, b);

            if(n%d!=0 || a+b>n) cout << "failed\n";
            else{
                x=x*(n/d);
                y=y*(n/d);
                
                long long int ans1, ans1x, ans1y, ans2, ans2x, ans2y, ansx, ansy;
                
                double aux1x=d;
                    aux1x*=-x;
                    aux1x/=b;
                double aux1y=d;
                    aux1y*=y;
                    aux1y/=a;
                double aux2x=d;
                    aux2x*=x;
                    aux2x/=b; 
                double aux2y=d;
                    aux2y*=-y;
                    aux2y/=a;

                if(x<y){

                    if(ceil(aux1x)>floor(aux1y)) cout << "failed\n";
                    else{

                        ans1x=x+(b/d)*ceil(aux1x);
                        ans1y=y-(a/d)*ceil(aux1x);
                        ans1=c1*ans1x+c2*ans1y;
                        ans2x=x+(b/d)*floor(aux1y);
                        ans2y=y-(a/d)*floor(aux1y);
                        ans2=c1*ans2x+c2*ans2y;

                        if(ans1<=ans2){
                            ansx=ans1x;
                            ansy=ans1y;
                        }
                        else{
                            ansx=ans2x;
                            ansy=ans2y;
                        }

                        cout <<ansx << " " << ansy << "\n";

                    }
                    
                    
                }
                else{

                    if(floor(aux2x)<ceil(aux2y)) cout << "failed\n";
                    else{
                        ans1x=x-(b/d)*ceil(aux2y);
                        ans1y=y+(a/d)*ceil(aux2y);
                        ans1=c1*ans1x+c2*ans1y;
                        ans2x=x-(b/d)*floor(aux2x);
                        ans2y=y+(a/d)*floor(aux2x);
                        ans2=c1*ans2x+c2*ans2y;

                        if(ans1<=ans2){
                            ansx=ans1x;
                            ansy=ans1y;
                        }
                        else{
                            ansx=ans2x;
                            ansy=ans2y;
                        }

                        cout <<ansx << " " << ansy << "\n";
                    }      
                }
            }

            cin >> n;
        }

        return 0;
    }
