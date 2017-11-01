#include <bits/stdc++.h>

#define vert vector<int>

using namespace std;

vector <int> empt;
int dfsnum[26];
vector<vert> graph(26);

void dfs(int u){
    dfsnum[u]=1;
    for(int i=0; i<graph[u].size(); i++){
        int v=graph[u][i];
        if(dfsnum[v]==0) dfs(v);
    }
}


int main(void){

    int T, last, x1, x2, cont;
    cin >> T;
    string s;
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    while(T>1){
        cont=0;
        fill(dfsnum, dfsnum+26, 0);
        last=s[0]-65;
        getline(cin,s);
        while(s.length()>0){
            x1=s[0]-65;
            x2=s[1]-65;
            graph[x1].push_back(x2);
            graph[x2].push_back(x1);
            getline(cin, s);
        }
        for(int i=0; i<=last; i++){
            if(dfsnum[i]==0){
                dfs(i);
                cont++;
            }
        }
        cout << cont << "\n";
        cout << "\n";
        getline(cin,s);
        T--;
        for(int i=0; i<=last; i++) graph[i].clear();
    }

    cont=0;
    fill(dfsnum, dfsnum+26, 0);
    last=s[0]-65;
    getline(cin,s);

    while(s.length()>0){
        x1=s[0]-65;
        x2=s[1]-65;
        graph[x1].push_back(x2);
        graph[x2].push_back(x1);
        getline(cin, s);
    }


    for(int i=0; i<=last; i++){
        if(dfsnum[i]==0){
            dfs(i);
            cont++;
        }
    }
    cout << cont << "\n";


    return 0;
}
