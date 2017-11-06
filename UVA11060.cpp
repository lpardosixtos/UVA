#include <bits/stdc++.h>

using namespace std;

int n;
const int INF=(1<<30);

vector< vector< int> > graph(100);


int main(void){

    int m, pos1, pos2, cases=0;
    string aux, aux1;
    while(cin >> n){
        cases++;
        string A[n+1];
        int inc[n];
        fill(inc, inc+n, 0);

        for(int i=0; i<n; i++){
            cin >> A[i];
        }

        cin >> m;

        for(int i=0; i<m; i++){
            pos1=-1;
            pos2=-1;
            cin >> aux >> aux1;
            for(int i=0; i<n; i++){
                if(pos1==-1) if(aux==A[i]) pos1=i;
                if(pos2==-1) if(aux1==A[i]) pos2=i;
            }
            inc[pos2]++;
            graph[pos1].push_back(pos2);
        }
        priority_queue<int> bf;

        for(int i=0; i<n; i++) if(inc[i]==0) bf.push(-i);
        int d[n];
        fill(d, d+n, INF);
        int u, v;
        vector<int> ans;

        while(!bf.empty()){
            u=-(bf.top());
            bf.pop();
            ans.push_back(u);
            for(int i=0; i<graph[u].size(); i++){
                v=graph[u][i];
                inc[v]--;
                if(inc[v]==0) bf.push(-v);
            }
        }

        cout << "Case #" << cases << ": Dilbert should drink beverages in this order:";

        for(int i=0; i<ans.size(); i++){
            cout << " " << A[ans[i]];
        }
        cout << ".\n";
        cout << "\n";

        ans.clear();
        for(int i=0; i<n; i++) graph[i].clear();




    }

    return 0;
}
