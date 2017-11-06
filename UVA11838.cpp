#include <bits/stdc++.h>

using namespace std;

const int INF=(1<<30);
vector< vector <int> > graph(2000);
int n, tovert[2000];
int dfscont, dfsarr[2000][2];

void dfs(int v){
	int low=INF;
	int u;
	dfscont++;
	tovert[dfscont]=v;
	dfsarr[v][0]=dfscont;
	dfsarr[v][1]=dfscont;
	
	for(int i=0; i<graph[v].size(); i++){
		u=graph[v][i];
		if(dfsarr[u][0]==INF){ 
			dfs(u);
		}
		low=min(low, dfsarr[u][1]);
	}
	dfsarr[v][1]=min(low, dfsarr[v][1]);
}

int main(void){

	int m, aux1, aux2, p;
	cin >> n >> m;
	while(n!=0 && m!=0){
		for(int i=0; i<n; i++){
			dfsarr[i][0]=INF;
			dfsarr[i][1]=INF;
		}

		dfscont=-1;
		for(int i=0; i<m; i++){
			cin >> aux1 >> aux2 >> p;
			aux1--;
			aux2--;
			graph[aux1].push_back(aux2);
			if((p & 1)==0) graph[aux2].push_back(aux1);
		}

		dfs(0);

		int ind=0;

		for(int i=0; i<n; i++){
			if(dfsarr[i][0]!=INF){
				aux1=dfsarr[i][0];
				aux2=dfsarr[i][1];
				while(aux2<aux1){
					aux1=dfsarr[tovert[aux2]][0];
					aux2=dfsarr[tovert[aux2]][1];
				}
				if(aux2!=0){ 
					ind=1;
					break;
				}
			}
			else{
				ind=1;
				break;
			}
			
		}

		if(ind==1) cout << 0 << "\n";
		else cout << 1 << "\n";



		for(int i=0; i<n; i++){
			graph[i].clear();
		}
		cin >> n >> m;
	}


	return 0;
}