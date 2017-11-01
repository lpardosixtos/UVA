#include <bits/stdc++.h>

using namespace std;

int main(void){

	int S, N;
	cin >> S;
	for(int j=0; j<S; j++){
		cin >> N;
		int A[N];
		long long int prod=1;
		for(int i=0; i<N; i++){
			cin >> A[i];
			prod*=A[i];
		}
		long long int sum=0;
		for(int i=0; i<N; i++){
			sum+=prod/A[i];
		}
		prod*=N;

		long long int gcd=__gcd(prod, sum);
		long long int m, n; 
		m=prod/gcd;
		n=sum/gcd;
		cout << "Case " << j+1 << ": " << m << "/" << n << "\n";
	}


	return 0;
}