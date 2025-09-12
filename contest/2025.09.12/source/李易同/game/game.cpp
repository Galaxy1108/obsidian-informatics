#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int n,m;
long long val[200010];
long long rs;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i) val[i]=0;rs=0;
		for(int i=1,u,v,w;i<=m;++i)
		{
			cin>>u>>v>>w;
			val[u]+=w,val[v]+=w;
		}
		sort(val+1,val+n+1);
		for(int i=n;i>=1;i-=2) rs+=val[i]-val[i-1];
		cout<<(rs>>1)<<'\n';
	}
	return 0;
}
