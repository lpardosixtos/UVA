#include <bits/stdc++.h>

using namespace std;

int main(void){

	string n;
	getline(cin,n);
	int j=0;
	string N="";
	while(n[j]==' '){
		j++;
	}
	N.push_back(n[j]);
	int x=n[j]-'0';
	int s=n.size();

	while(x!=0 || (s>j+1 && n[j+1]!=' ')){
		int sum=x;
		for(int i=j+1; i<s; i++){
			if(n[i]==' ') i=s;

			else{
				N.push_back(n[i]);
				x=n[i]-'0';
				if((i-j) & 1) sum-=x;
				else sum+=x;
			}
		}

		if(sum%11==0) cout << N << " is a multiple of 11.\n";
		else cout << N << " is not a multiple of 11.\n";

		getline(cin, n);
		j=0;
		while(n[j]==' '){
			j++;
		}
		x=n[j]-'0';
		N="";
		s=n.size();
		N.push_back(n[j]);


	}


	return 0;
}