#include <bits/stdc++.h>

using namespace std;

int main(void){
	
	int n, m;
	double xn, xm;

	while(cin >> n){
		cin >> m;
		int auxn=sqrt(n);
		int auxm=sqrt(m);
		double yn, ym;

		if((n%2)==(auxn%2)) yn=3*auxn;
		else yn=3*auxn-1;
		if((m%2)==(auxm%2)) ym=3*auxm;
		else ym=3*auxm-1;
		

		xn=(n-pow(auxn, 2)-auxn)/2;
		xm=(m-pow(auxm, 2)-auxm)/2;

		double ans=pow(xm-xn,2)+pow(ym-yn,2)/12;
		ans=sqrt(ans);

		cout << fixed << setprecision(3) << ans << "\n";

	}



	return 0;
}