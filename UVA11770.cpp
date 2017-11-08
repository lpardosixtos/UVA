#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int n, dfsnum[10000], cont, dfscont, ind;
vector< vector<int> > graph(10000);
int A[10000], B[10000], C[10000];

void dfs(int v){
	cont++;
	dfsnum[v]=cont;
	int u;
	for(int i=0; i<graph[v].size(); i++){
		u=graph[v][i];
		if(dfsnum[u]==-1) dfs(u);
	}
}
void dfs1(int v, int w){
    if(v==w) B[v]=ind;
	cont++;
	dfsnum[v]=cont;
	int u;
	for(int i=0; i<graph[v].size(); i++){
		u=graph[v][i];
		if(B[u]>-1 && B[u]<ind && C[B[u]]==0){
            C[B[u]]=1;
			dfscont++;
		}
		if(dfsnum[u]==-1) dfs1(u, w);
		if(B[u]==ind) B[v]=ind;
	}
}


int main(void){
	//fstream fout;
	//fout.open("t.txt");
	int t, m, a, b, ans;
	cin >> t;
	for(int k=1; k<=t; k++){
		fill(A, A+10000, 0);
		fill(B, B+10000, 0);
		fill(C, C+10000, 0);
		fill(dfsnum, dfsnum+10000, -1);
		cin >> n >> m;
		ans=0;
		for(int i=0; i<m; i++){
			cin >> a >> b;
			a--;
			b--;
			graph[a].push_back(b);
			A[b]++;
		}
		cont=-1;
		for(int i=0; i<n; i++){
			if(A[i]==0){
				dfs(i);
				ans++;
			}
		}
		ind=-1;
		for(int i=0; i<n; i++){
			if(dfsnum[i]==-1){
                ind++;
				dfscont=0;
				dfs1(i, i);
				B[i]=ind;
				ans++;
				ans-=dfscont;
			}
		}

		for(int i=0; i<n; i++){
			graph[i].clear();
		}


		cout << "Case " << k << ": " << ans << "\n";
	}
	//fout.close();
	return 0;
}
