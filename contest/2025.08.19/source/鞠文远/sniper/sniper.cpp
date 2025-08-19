#include<bits/stdc++.h>
#define int long long
using namespace std;
const int wi[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
const int N=8005,T=25005;
int n,w[N],u[N],t[N],sni[T],sp[T],tw[T][25],tp[T][25];
int memal[T][25][2];
bool visal[T][25][2];
#define mem memal[ttm][pos][cmv]
#define vis visal[ttm][pos][cmv]
int dfs(int ttm,int pos,bool cmv)
{
	if(vis)return mem;
	vis=true;
	if(sni[ttm]&&(abs(pos-sp[ttm])>2||!cmv))return mem=(-0x3f3f3f3f);
	if(ttm>t[n])return mem=0;
	int res=-0x3f3f3f3f;
	if(!sni[ttm]||pos==sp[ttm])
	{
		res=max(res,dfs(ttm+1,pos,1));	
		if(tp[ttm][pos]&&cmv)res=max(res,wi[tw[ttm][pos]]+dfs(ttm+1,pos,0));
	}
	if((!sni[ttm]||pos-1==sp[ttm])&&pos>1&&cmv)
	{
		res=max(res,dfs(ttm+1,pos-1,1));
		if(tp[ttm][pos-1]&&cmv)res=max(res,wi[tw[ttm][pos-1]]+dfs(ttm+1,pos-1,0));
	}
	if((!sni[ttm]||pos-2==sp[ttm])&&pos>2&&cmv)
	{
		res=max(res,dfs(ttm+1,pos-2,1));
		if(tp[ttm][pos-2]&&cmv)res=max(res,wi[tw[ttm][pos-2]]+dfs(ttm+1,pos-2,0));
	}
	if((!sni[ttm]||pos+1==sp[ttm])&&pos<20&&cmv)
	{
		res=max(res,dfs(ttm+1,pos+1,1));
		if(tp[ttm][pos+1]&&cmv)res=max(res,wi[tw[ttm][pos+1]]+dfs(ttm+1,pos+1,0));
	}
	if((!sni[ttm]||pos+2==sp[ttm])&&pos<19&&cmv)
	{
		res=max(res,dfs(ttm+1,pos+2,1));
		if(tp[ttm][pos+2]&&cmv)res=max(res,wi[tw[ttm][pos+2]]+dfs(ttm+1,pos+2,0));
	}
	return mem=res;
}
signed main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>u[i]>>t[i];	
		tw[t[i]][u[i]]=w[i];
		tp[t[i]][u[i]]=u[i];
	}
	int cnt=1;
	for(int i=1;i<=t[n];i++)
	{
		while(t[cnt]==i)
		{
			if(w[cnt]==15)
			{
				sni[i]=1;
				sp[i]=u[cnt];
			}
			cnt++;
		}
	}
	int anslt=0;
	for(int i=1;i<=20;i++)anslt=max(anslt,dfs(0,i,1));
	cout<<anslt;
	
	return 0;
} 
