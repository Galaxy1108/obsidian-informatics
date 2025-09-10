#include<bits/stdc++.h>
using namespace std;
int n,m;
int tag[1010][1010];
long double f[1010][1010];
long double F(int a,int b){
	if(a<0||b<0) return 0;
	if(a==0) return 0;
	if(b==0) return 1;
	if(a+b<=2) return 0.5;
	if(tag[a][b]) return f[a][b];
	tag[a][b]=1;
	long double ans=(long double)(a)/(a+b);
	ans+=(long double)(b)/(a+b)*(long double)(b-1)/(a+b-1)*(long double)(b-2)/(a+b-2)*F(a,b-3);
	ans+=(long double)(b)/(a+b)*(long double)(b-1)/(a+b-1)*(long double)(a)/(a+b-2)*F(a-1,b-2);
	f[a][b]=ans;
	return ans;
}
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%.9Lf",F(n,m));
	return 0;
}
