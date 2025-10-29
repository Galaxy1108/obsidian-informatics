#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stdlib.h>
#define LL long long
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
	return sum;
}
int a,b,d;
LL rec[1001];
LL gcd(LL a,LL b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
inline void dfs(LL x,LL y,int dep,LL p)
{
	if(dep==d)
		{
			if(x!=1) return;
			printf("%d\n",d);
			for(int j=1;j<d;j++) printf("%lld ",rec[j]);
			printf("%lld",y);
			exit(0);
		}
	LL i,dis=d-dep+1,g;
	for(i=p+1;;i++)
		{
			if(x*i-y<=0) continue;
			if(x*i-y*dis>=0) break;
			rec[dep]=i;
			g=gcd(x*i-y,y*i);
			dfs((x*i-y)/g,y*i/g,dep+1,i+1);
		}
}

int main( )
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	a=read( );b=read( );
	if(a==1) {printf("1 %d\n",b);return 0;}
	for(d=2;;d++) dfs(a,b,1,1);
	return 0;
}
