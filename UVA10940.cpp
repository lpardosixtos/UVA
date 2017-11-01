#include <bits/stdc++.h>

using namespace std;

int mem[500000];
int rem(int n){

	if(mem[n]!=-1) return mem[n];

	for(int i=0; i<n; i++){
		if((1<<i)& n){
			if((1<<i)==n){
				mem[n]=1;
				return 1;
			}
			else break;
		}
	}

	if(n%2==0) {
		mem[n]=(2*rem(n/2))-1;
		return mem[n];
	}
	else{
		if(rem(n/2)==1){
			mem[n]=n-1;
			return mem[n];
		}
		else{
			mem[n]=2*(rem(n/2)-1);
			return mem[n];
		}
	}
}


int main(void){
	
	int n;
	memset(mem, -1, sizeof mem);
	cin >> n;
	while(n!=0){
		cout << n-rem(n)+1 << "\n";
		cin >> n;
	}



	return 0;
}