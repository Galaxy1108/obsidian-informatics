#include <cstdio>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;
struct query{int x1,y1,x2,y2,id;};
vector<query> v[1211];
int n,q,a[311][311],piv[100011];ll ans[200011];
void build(int l,int r,int x)
{
	piv[x]=l+r>>1;if(l==r)return;
	build(l,l+r>>1,x<<1);build((l+r>>1)+1,r,x<<1|1);
}
void ins(int l,int r,query Q,int x)
{
	if(piv[x]>=l&&piv[x]+1<=r){v[x].push_back(Q);return;}
	if(r<=piv[x])ins(l,r,Q,x<<1);else ins(l,r,Q,x<<1|1);
}
ll dp[311][311],dp1[311][311];
void proc(int l,int r,int x)
{
	if(l==r)return;
	if(!v[x].empty())
	{
		int mnx=1e9,mxx=-1e9,mny=1e9,mxy=-1e9;
		for(auto Q:v[x])
		{
			mnx=min(mnx,Q.x1);mny=min(mny,Q.y1);
			mxx=max(mxx,Q.x2);mxy=max(mxy,Q.y2);
		}
		for(int _=mnx;_<=mxx;++_)
		{
			for(int i=_;i>=mnx;--i)
			{
				for(int j=piv[x];j>=mny;--j)
				{
					dp[i][j]=(i==_&&j==piv[x]?0:1e18);
					if(i<_)dp[i][j]=min(dp[i][j],dp[i+1][j]);
					if(j<piv[x])dp[i][j]=min(dp[i][j],dp[i][j+1]);
					dp[i][j]+=a[i][j];
				}
			}
			for(int i=_;i<=mxx;++i)
			{
				for(int j=piv[x]+1;j<=mxy;++j)
				{
					dp1[i][j]=(i==_&&j==piv[x]+1?0:1e18);
					if(i>_)dp1[i][j]=min(dp1[i][j],dp1[i-1][j]);
					if(j>piv[x]+1)dp1[i][j]=min(dp1[i][j],dp1[i][j-1]);
					dp1[i][j]+=a[i][j];
				}
			}
			for(auto Q:v[x])
			{
				if(Q.x1<=_&&_<=Q.x2)ans[Q.id]=min(ans[Q.id],dp[Q.x1][Q.y1]+dp1[Q.x2][Q.y2]);
			}
		}
	}
	proc(l,l+r>>1,x<<1);proc((l+r>>1)+1,r,x<<1|1);
}
int main()
{
	freopen("glyph.in","r",stdin);freopen("glyph.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%d",a[i]+j);
	build(1,n,1);
	for(int _=1;_<=q;++_)
	{
		query Q;scanf("%d%d%d%d",&Q.x1,&Q.x2,&Q.y1,&Q.y2);Q.id=_;
		if(Q.y1==Q.y2){v[0].push_back(Q);continue;}
		ins(Q.y1,Q.y2,Q,1);
	}
	memset(ans,0x3f,sizeof(ans));
	proc(1,n,1);
	for(auto Q:v[0])
	{
		ans[Q.id]=0;
		for(int _=Q.x1;_<=Q.x2;++_)ans[Q.id]+=a[_][Q.y1];
	}
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	fclose(stdin);fclose(stdout);return 0;
}