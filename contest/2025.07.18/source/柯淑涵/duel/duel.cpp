#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100001],s[1001];
long long f(long long x,long long y){
	if(abs(x-y)==1){
		return abs(a[x]-a[y]);
	}
	return abs(f(x,(x+y)/2)-f((x+y)/2+1,y));
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	s[0]=1;
	for(long long i=1;i<=30;i++){
		s[i]=s[i-1]*2;
	}
	if(n<=10000000&&m<=10000000){
		long long x,y,z;
		for(long long i=1;i<=m;i++){
			cin>>x;
			if(x==1){
				cin>>y>>z;
				a[y]=z;
			}
			else{
				cin>>y>>z;
				cout<<f(y,y+s[z]-1)<<endl;
			}
		}
	}
	return 0;
} 
/*
5 3 
4 8 2 0 7 
2 1 2 
1 1 9 
2 2 1

8 6 
1 2 3 4 5 6 7 8 
2 1 3 
1 4 1 
1 7 3 
2 1 3 
1 2 100 
2 2 2

9 5 
1 0 2 0 4 1 3 2 8 
2 2 3 
2 1 3 
1 5 1 
1 6 4 
2 4 2
*/
