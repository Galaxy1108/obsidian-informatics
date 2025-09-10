#include<bits/stdc++.h>
#define int long long 
#define N 5
using namespace std;
int n,flag[N+5];
mt19937 rnd;
int Rand(int l,int r){
	return rnd()%(r-l+1)+l;
}
main(){
	freopen("permutation.in","w",stdout);
	rnd.seed(time(0));
	n=N;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++)cout<<(i%n+1)<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++){
		int u;
		do{
			u=Rand(1,n);
		}while(flag[u]);
		flag[u]=1;
		cout<<u<<" ";
	}
	cout<<"\n";
}
