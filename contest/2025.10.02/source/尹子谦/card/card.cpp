#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=2e6+10;
int n,m,q,res[N];
bool num[2];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(res,-1,sizeof res);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		int s;
		cin>>s;
		num[s%2]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int p,b;
		cin>>p>>b;
		res[p]=b%2;
	}
	while(q--)
	{
		int p,b,op;
		cin>>op;
		if(op==1)
		{
			cin>>p;
			res[p]=-1;
		}
		else 
		{
			cin>>p>>b;
			res[p]=b%2;
		}
		int lst=1,ans=0;
		for(int i=2;i<=n;i++)
		{
			if(res[i]==-1) continue;
			else ans+=(res[i]!=res[lst]),lst=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
