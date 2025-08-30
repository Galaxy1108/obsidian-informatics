#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int n,k,ary[N],lry[N],fa[N];
bool vis[N];
pair<int,int>ed[N];
int fdfa(int x){return (x==fa[x]?fa[x]:fa[x]=fdfa(fa[x]));}
int gcd(int a,int b){return (a%b==0?b:gcd(b,a%b));}
int sol(int x)
{
	int anslt=0;
	for(int i=1;i<=n;i++)ary[i]=lry[i];
	for(int i=1;i<=n;i++)fa[i]=i,vis[i]=false;
	int av=n-k-1;
	while(av--)
	{
		int mi=0x3f3f3f3f,miid=0;
		for(int i=1;i<n;i++)
		{
			if(vis[i])continue;
			int u=fdfa(ed[i].first);
			int v=fdfa(ed[i].second);
			int qz=ary[u]+ary[v]-gcd(ary[u],ary[v]);
			int pd=rand()%x;
			if(qz<mi||(qz<=mi&&pd==0))
			{
				miid=i;
				mi=qz;
			}
		}
		vis[miid]=true;
		int u=fdfa(ed[miid].first);
		int v=fdfa(ed[miid].second);
		ary[u]=ary[v]=gcd(ary[u],ary[v]);
		fa[v]=u;
	}
	for(int i=1;i<=n;i++)if(fa[i]==i)anslt+=ary[i];
	return anslt;
}
signed main()
{
	freopen("plan.in","r",stdin); 
	freopen("plan.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>n>>k;
	for(int i=1;i<n;i++)cin>>ed[i].first>>ed[i].second;
	for(int i=1;i<=n;i++)cin>>lry[i];
	int anslt=0;
	for(int i=1;i<=100;i++)anslt=max(anslt,sol(i));
	anslt=max(anslt,sol(998244353));
	cout<<anslt;
	
	return 0;
} 
