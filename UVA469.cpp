#include<bits/stdc++.h>

using namespace std;

vector<string> land;

int dr[8][2], ans;
int R, C;
int A[100][100];

int toNum(string s){
    int aux=0, aux1;
    for(int i=0; i<s.length(); i++){
        aux1=s[i]-'0';
        aux=10*aux+aux1;
    }
    return aux;
}

int floodFill(int r, int c, int k){
    if(r<0 || r>=R || c<0 || c>=C) return 0;
    if(land[r][c]!='W') return 0;
    int aux=1;
    land[r][c]='L';
    A[r][c]=k;
    for(int d=0; d<8; d++) aux+=floodFill(r+dr[d][0], c+dr[d][1], k);
    return aux;
}

int main(void){

    int T;
    dr[0][0]=1;
    dr[1][0]=1;
    dr[2][0]=0;
    dr[3][0]=-1;
    dr[4][0]=-1;
    dr[5][0]=-1;
    dr[6][0]=0;
    dr[7][0]=1;

    dr[0][1]=0;
    dr[1][1]=1;
    dr[2][1]=1;
    dr[3][1]=1;
    dr[4][1]=0;
    dr[5][1]=-1;
    dr[6][1]=-1;
    dr[7][1]=-1;

    cin >> T;
    string s;
    vector<int> resp;
    getline(cin, s);
    getline(cin, s);
    int cont=0;
    while(T>cont){
        memset(A, -1, sizeof A);
        ans=0;
        getline(cin, s);
        while(!isdigit(s[0])){
            land.push_back(s);
            getline(cin, s);
        }
        R=land.size();
        C=land[0].length();

        int x1=0, x2=0, k=0, aux3;
        while(s[k]!=' '){
            aux3=s[k]-'0';
            x1=10*x1+aux3;
            k++;
        }
        x1--;
        k++;
        while(k<s.length()){
            aux3=s[k]-'0';
            x2=10*x2+aux3;
            k++;
        }
        x2--;
        resp.push_back(floodFill(x1, x2, 0));
        cout << resp.back() << "\n";

        getline(cin, s);
        while(s.length()>0){
            k=0;
            x1=0;
            while(s[k]!=' '){
                aux3=s[k]-'0';
                x1=10*x1+aux3;
                k++;
            }
            x1--;
            k++;
            x2=0;
            while(k<s.length()){
                aux3=s[k]-'0';
                x2=10*x2+aux3;
                k++;
            }
            x2--;

            if(A[x1][x2]!=-1) cout << resp[A[x1][x2]] << "\n";
            else{
                int aux2=floodFill(x1, x2, resp.size());
                resp.push_back(aux2);
                cout << resp.back() << "\n";
            }
            getline(cin, s);
        }

        if(cont<T-1) cout << "\n";
        cont++;
        resp.clear();
        land.clear();
    }




    return 0;
}
