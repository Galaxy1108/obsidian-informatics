//O(n^2)
//n方过百万 暴力碾标算
//带飞了 orz
#include<bits/stdc++.h>
using namespace std;
int n,q,r[200005],b[200005],x,y,aac[1000005],aaccnt,ans[1000005],aac2[1000005],pp;
vector<int> v[200005];
vector<int> id[200005];
int f;
char ch;
int read()
{
	f=0;
	ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		f*=10;
		f+=ch-'0';
		ch=getchar();
	}
	return f;
}
void write(int x)
{
	if(x>=10) write(x/10);
	putchar((x%10)+'0');
	return;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	//scanf("%d%d",&n,&q); 
	n=read();
	q=read();
	for(int i = 1; i <= n; i++)
	{
		r[i]=read();
	}
	for(int i = 1; i <= q; i++)
	{
		x=read();
		y=read();
		if(x<=n)
		{
			v[x].push_back(y);
			id[x].push_back(i);
		}
		else
		{
			aaccnt++;
			aac[aaccnt]=y;
			aac2[aaccnt]=i;
		}
		/*if(x<=n) printf("%d\n",r[x][y]);
		else printf("%d\n",r[n][y]);*/
	}
	for(int i = 0; i < v[0].size(); i++)
	{
		ans[id[0][i]]=r[v[0][i]];
	}
	for(int t = 1; t <= n; t++)
	{
		//cerr<<t<<endl; 
		for(int i = 1; i <= n; i++) b[i]=r[i];
		int lp=1,rp=n/2+1;
		for(int i = 1; i <= n; i++)
		{
			//cerr<<i<<endl;
			if(lp<=n/2&&rp<=n&&b[lp]>b[rp])
			{
				r[i]=b[rp];
				rp++;
			}
			else if(lp<=n/2)
			{
				r[i]=b[lp];
				lp++;
			}
			else
			{
				break;
			}
		}
		for(int i = 0; i < v[t].size(); i++)
		{
			ans[id[t][i]]=r[v[t][i]];
		}
		bool isok=1;
		for(int j = 1; j <= n; j++)
		{
			if(r[j]!=b[j])
			{
				isok=0;
				break;
			}
		}
		if(isok)
		{
			pp=t;
			//return 0;
			break;
		}
	}
	for(int t = pp+1; t <= n; t++)
	{
		for(int i = 0; i < v[t].size(); i++)
		{
			ans[id[t][i]]=r[v[t][i]];
		}
	 } 
	for(int i = 1; i <= aaccnt; i++)
	{
		ans[aac2[i]]=r[aac[i]];
	}
	for(int i = 1; i <= q; i++)
	{
		//printf("%d\n",ans[i]);
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}
