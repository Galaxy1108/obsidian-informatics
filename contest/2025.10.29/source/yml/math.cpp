#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long  LL;
int a,b,temp[100],ans[100];

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}

void dfs(LL a,LL b,int last,int k)
{
	if (k==1)
		{
			if ((a==1)&&((!ans[0])||(b<ans[1])))
				memcpy(ans,temp,sizeof(ans)),ans[0]=1,ans[1]=b;
			return;
		}
	LL oa=a,ob=b,g;
	for (int x=last+1; ; x++)
		{
			a=oa,b=ob;
			if (a*x>=b*k)  break;
			a=a*x-b,b*=x,g=gcd(a,b),a/=g,b/=g,temp[k]=x;
			if ((a>0)&&(b>0))  dfs(a,b,x,k-1);
		}
}

void work()
{
	scanf("%d %d",&a,&b);
	for (int i=1; ; i++)
		{
			dfs(a,b,0,i);
			if (ans[0])
				{
					printf("%d\n",i);
					for (int j=i; j; j--)  printf("%d ",ans[j]);
					return;
				}
		}
}

int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	work();
	return 0;
}
