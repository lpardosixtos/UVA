#include <bits/stdc++.h>

using namespace std;

int n, A[100][100];
string res[100][100];
int dfsnum[100];
int dfsnum2[100];

void dfs(int v){
	if(dfsnum[v]==1) return;
	dfsnum[v]=1;
	for(int i=0; i<n; i++){
		if(A[v][i]==1) dfs(i);
	}
}

void dfs2(int v, int u){
	if(dfsnum[u]==1) dfsnum2[u]=1;
	if(dfsnum2[v]==1) return;
	dfsnum2[v]=1;
	for(int i=0; i<n; i++){
		if(A[v][i]==1) dfs2(i, u);
	}
}


int main(void){

	int t;
	cin >> t;
	for(int k=1; k<t+1; k++){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> A[i][j];
			}
		}
		fill(dfsnum, dfsnum+100, 0);
		dfs(0);
		for(int i=0; i<n; i++){
			fill(dfsnum2, dfsnum2+100, 0);
			dfs2(0,i);
			for(int j=0; j<n; j++){
				if(dfsnum2[j]!=dfsnum[j]) res[i][j]="Y";
				else res[i][j]="N";
			}
		}

		for(int i=0; i<n; i++){
			if(dfsnum[i]==1) res[i][i]="Y";
		}
		string s="+";
		for(int i=1; i<2*n; i++){
			s+="-";
		}
		s+="+";

		cout << "Case " << k << ":\n";
		for(int i=0; i<2*n+1; i++){
			if((i & 1)==0) cout << s;
			else{
				for(int j=0; j<n; j++){
					cout << "|" << res[(i-1)/2][j];
				}
				cout << "|";
			}
			cout << "\n";
		}
	}


	return 0;
}

