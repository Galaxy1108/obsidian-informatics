#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,anslt,ary[N];
void dfs(int mx,int st)
{
	if(st>100||mx>=anslt)return;
	bool pd=true;
	for(int i=2;i<=n;i++)
		if(ary[i]>ary[i-1])
		{
			pd=false;
			break;
		}
	if(pd)anslt=min(anslt,mx);
	for(int i=1;i<n;i++)
	{
		if(ary[i]>=ary[i+1])continue;
		int a=ary[i],b=ary[i+1];
		ary[i]=b-1;
		ary[i+1]=a+1;
		dfs(max(mx,a+b),st+1);
		ary[i]=a;
		ary[i+1]=b;
	}
	return;
}
signed main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		anslt=2e18;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>ary[i];
		dfs(0,0);
		cout<<(anslt==2e18?-1:anslt)<<"\n";
	}
	
	return 0;	
} 
