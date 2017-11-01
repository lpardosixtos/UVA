#include <bits/stdc++.h>

using namespace std;

int main(void){

	int T, N, B, K, aux;
	long long int prod, ans;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N >> B;
		ans=0;
		for(int j=0; j<B; j++){
			cin >> K;
			prod=1;
			for(int k=0; k<K; k++){
				cin >> aux;
				prod=(prod*aux)%N;
			}
			ans=(ans+prod)%N;
		}
		cout << ans << "\n";

	}


	return 0;
}