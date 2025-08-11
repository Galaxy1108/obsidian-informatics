#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
constexpr int N=1.5e5+5;
int n;
struct node{
	int x,y,z;
}a[N];
int s[N];
int lim;
vector<int>lsh;
int ans;
inline void add(int x,int v)
{
	while(x<=lim)
		s[x]=max(s[x],v),x+=lowbit(x);
}
inline int ask(int x)
{
	int res=0;
	while(x)
		res=max(res,s[x]),x-=lowbit(x);
	return res;
}
int premx1,premx2;
pii pre1,pre2;
void solve()
{
	memset(s,0,sizeof s);
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	lim=lsh.size()-1;
	for(int i=1;i<=n;i++)
		a[i].y=lower_bound(lsh.begin(),lsh.end(),a[i].y)-lsh.begin();
	for(int i=1;i<=n;i++)
	{
		if(i!=1 && a[i-1].x!=a[i].x)
		{
			if(premx1<premx2)
				premx1=premx2,pre1=pre2;
			premx2=0;
		}
		if(pre1.fi>a[i].y && pre1.se>a[i].z)
			ans=max(ans,a[i].x+premx1);
		int res=ask(a[i].y-1);
		if(res>a[i].z && premx2<lsh[a[i].y]+res)
			premx2=lsh[a[i].y]+res,pre2=mp(lsh[a[i].y],res);
		add(a[i].y,a[i].z);
	}
	for(int i=1;i<=n;i++)
		a[i].y=lsh[a[i].y];
}
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	scanf("%d",&n);
	lsh.pb(0);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),lsh.pb(a[i].y);
	sort(a+1,a+1+n,[](node x,node y){return x.x<y.x;});
	solve();
	lsh.clear();
	lsh.pb(0);
	for(int i=1;i<=n;i++)
		swap(a[i].y,a[i].z),lsh.pb(a[i].y);
	solve();
	if(!ans)
		puts("-1");
	else
		printf("%d",ans);
	return 0;
}
