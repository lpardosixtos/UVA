#include <bits/stdc++.h>

using namespace std;

int main(void){

	int n;
	cin >> n;

	while(n!=0){

		int A[n][n];

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> A[i][j];
			}
		}

		int aux=0;

		for(int i=0; i<n-1 && aux==0; i++){
			for(int j=0; j<n-1 && aux==0; j++){
				if(A[i][j]+A[i+1][j+1]!=A[i][j+1]+A[i+1][j]){
					cout << "not homogeneous\n";
					aux=1;
				}
			}
		}

		if(aux==0) cout << "homogeneous\n";


		cin >> n;
	} 


	return 0;
}