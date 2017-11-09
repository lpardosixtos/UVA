#include <bits/stdc++.h>

using namespace std;
int n, m, s;
char B[100][100];
string seq;



int main(void){
    cin >> n >> m >> s;
    int d1[]={0, 1, 0, -1};
    int d2[]={-1, 0, 1, 0};
    while(n!=0 || m!=0 || s!=0){
        int pos1, pos2, dir;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> B[i][j];
                if(B[i][j]=='N'){
                    pos1=i;
                    pos2=j;
                    dir=0;
                }
                else{
                   if(B[i][j]=='L'){
                    pos1=i;
                    pos2=j;
                    dir=1;
                    }
                    if(B[i][j]=='S'){
                    pos1=i;
                    pos2=j;
                    dir=2;
                    }
                    else{
                        if(B[i][j]=='O'){
                        pos1=i;
                        pos2=j;
                        dir=3;
                        }
                    }
                }
            }
        }
        cin >> seq;
        int aux1, aux2, ans=0;
        for(int i=0; i<s; i++){
            if(seq[i]=='F'){
                aux1=pos1+d2[dir];
                aux2=pos2+d1[dir];
                if(aux1<n && aux1>=0 && aux2<m && aux2>=0 && B[aux1][aux2]!='#'){
                    pos1+=d2[dir];
                    pos2+=d1[dir];
                    if(B[pos1][pos2]=='*'){
                        ans++;
                        B[pos1][pos2]='.';
                    }
                }
            }
            else{
                if(seq[i]=='D') dir=(dir+1)%4;
                else dir=(dir+3)%4;
            }
        }
        cout << ans << "\n";
        cin >> n >> m >> s;
    }


    return 0;
}
