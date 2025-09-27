#include<bits/stdc++.h>
using namespace std;
int a,lb,rb,b,c,q,w,cnt,o,cnn;
int id[2000005],su[2000005],idd[2000005],si[2000005],h[2000005];
bool l[2000005],m[2000005],v[2000005];
char s[2000005];
struct p{int q,w;}g[8000005];
void dfs(int qq)
{
	v[qq]=1;idd[qq]=cnn;si[cnn]++;
	for(int i=h[qq];i;i=g[i].w) if(!v[g[i].q]) dfs(g[i].q);
}
void add(int qq,int ww)
{
	g[++o].q=ww,g[o].w=h[qq],h[qq]=o;
	g[++o].q=qq,g[o].w=h[ww],h[ww]=o;
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	scanf("%d%d%d",&a,&lb,&rb);
	b=lb;scanf("%s",s+1);
	long long ss=0,la=0,tt=1,yy=0;cnt=0;
	for(int i=1;i<=a;i++) l[i]=(s[i]=='a'),ss+=l[i];
	for(int i=1;i<=a;i++)
	{
		if(l[i]) m[++cnt]=1,la=0;
		else if(!la) la=1,m[++cnt]=0;id[i]=cnt;
	}
	for(int i=1;i<=cnt;i++) su[i]=su[i-1]+m[i];
	for(int i=1;i<=cnt;i++)
	{
		while(tt<=cnt&&yy+m[tt]<b) yy+=m[tt],tt++;
		while(tt<=cnt&&yy+m[tt]<=b)
		{
			if(i+1<=cnt&&m[i+1]==1&&m[i]==0) add(i+1,tt);
			add(i,tt),yy+=m[tt],tt++;
		}yy-=m[i];
	}scanf("%d",&c);
	for(int i=1;i<=cnt;i++) if(!v[i]) ++cnn,dfs(i);
	for(int i=1;i<=c;i++)
	{
		scanf("%d%d",&q,&w);
		if(q==w){puts("Yes");continue;}
		q=id[q],w=id[w];
		if(lb==rb)
		{
			int f1=idd[q],f2=idd[w];
			if(si[f1]!=1&&f1==f2) puts("Yes");
			else puts("No");
		}
		else
		{
			if(lb<=ss/2) puts("Yes");
			else
			{
				long long gg=ss-lb+1;
				if((su[q-1]<gg||su[q]>ss-gg)&&(su[w-1]<gg||su[w]>ss-gg)) puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}
