#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
const long long inf=1e18;
int N,i,j,k,st,ch,tw;
int C[1030],F;
bool situ[1030];
long long sum[1030][11],f[23][1030][1030],g[1030][1030],ans;
void get_min(long long &a,long long b)
{
	if(a>b) a=b;
	return;
}
void dfs(int dep,int num)
{
	if(dep==N+1)
	{
		int ge=0,ch=0,cnt=0;
		for(int i=0;i<=st;i++)
		{
			for(ge=0,cnt=1,ch=i;ch;ch>>=1,cnt++)
				if(ch&1)
					ge+=sum[num][cnt];
			f[dep][1][i]=ge;
			f[dep][0][i]=sum[num][0]-ge;
			f[dep][!situ[num]][i]+=C[num];
		}
		return;
	}
	dfs(dep+1,num);
	memcpy(f[dep+1+N],f[dep+1],sizeof(f[dep]));
	dfs(dep+1,num+(1<<N-dep));
	int st1=(1<<dep-1),st2=(1<<(N-dep+1)),st3;
	for(i=0;i<st1;i++)
	for(j=0;j<=st2;j++)
	{
		st3=i+((j<=st2/2)?st1:0);
		f[dep][j][i]=inf;
		for(k=max(0,j-st2/2);k<=j&&k<=st2/2;k++)
			get_min(f[dep][j][i],f[dep+1][k][st3]+f[dep+1+N][j-k][st3]);
	}
	return;
}
int main()
{
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	
	N=Qread();
	st=(1<<N)-1;
	tw=(1<<N);
	for(i=1;i<=tw;i++)
		situ[i]=Qread();
	for(i=1;i<=tw;i++)
		C[i]=Qread();
	for(i=1;i<=tw;i++)
	for(j=i+1;j<=tw;j++)
	{
		F=Qread();
		for(ch=0,k=0;k<N;k++,ch+=(1<<(N-k)))
			if(((i-1)&ch)!=((j-1)&ch))
				break;
		sum[i][0]+=F;
		sum[j][0]+=F;
		sum[i][k]+=F;
		sum[j][k]+=F;
	}
	dfs(1,1);
	ans=inf;
	for(i=0;i<=tw;i++)
		get_min(ans,f[1][i][0]);
	cout<<ans;
	return 0;
}