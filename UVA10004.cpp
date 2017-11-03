#include <bits/stdc++.h>

using namespace std;

const int INF=(1<<30);
vector< vector<int> > graph(200);
int n, d[200], v, u;
queue<int> q;


void bfs(){
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++){
            v=graph[u][i];
            if(d[v]==INF){
                d[v]=1-d[u];
                q.push(v);
            }
            else{
                if(d[v]==d[u]) {
                    cout << "NOT BICOLORABLE.\n";
                    return;
                }
            }
        }
    }
    cout << "BICOLORABLE.\n";
    return;
}

int main(void){

    int l, aux1, aux2;
    cin >> n;
    while(n!=0){
        fill(d, d+200, INF);
        cin >> l;
        for(int i=0; i<l; i++){
            cin >> aux1 >> aux2;
            graph[aux1].push_back(aux2);
            graph[aux2].push_back(aux1);
        }

        q.push(0);
        bfs();
        for(int i=0; i<n; i++){
            graph[i].clear();
        }
        cin >> n;
    }



    return 0;
}
