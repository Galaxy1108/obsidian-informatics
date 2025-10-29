#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n; int a,b,A[105];
int gcd(int x,int y){ return x ? gcd(y%x,x) : y;}
void dfs(int t,int p,int dep,int a,int b)
{
	int i; int g=gcd(a,b);
	a/=g,b/=g;
  if(a<dep-t+1) return ;
	if(t>=dep){
		if(a==1){
			printf("%d\n",dep);
			for(i=1;i<dep;i++)
				cout<<A[i]<<' ';
			cout<<b;
			exit(0);
		  }
		return ;
	  }
	for(i=p;i<=2000;i++)
		if(1.0*a/b>1.0/i&&1.0*a/b<(dep-t+1)*1.0/i)
	  	A[t]=i,dfs(t+1,i+1,dep,a*i-b,b*i);
}
int main()
{
	int i;
	freopen("math.in","r" , stdin);
	freopen("math.out","w",stdout);
	cin>>a>>b;
	for(i=1;;i++)
		dfs(1,1,i,a,b);
	return 0;
}
