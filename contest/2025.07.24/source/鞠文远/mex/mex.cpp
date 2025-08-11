#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,m,ary[N];
int memal[N][N];
bool visal[N][N];
#define mem memal[pos][qz]
#define vis visal[pos][qz]
int fp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int dfs(int pos,int qz)
{
	if(vis)return mem;
	vis=true;
	if(pos==n+1)return mem=1;
	int res=0;
	if(ary[pos]==0)
	{
		if(qz<=m)
		{
			res+=dfs(pos+1,qz+1)*max(0ll,m-qz)%mod;
			res%=mod; 
		}//²»ÖØ¸´
		res+=dfs(pos+1,qz)*qz%mod;//ÖØ¸´ 
		res%=mod;
	}
	else
	{
		if(qz>m)return 0;
		res+=dfs(pos+1,qz+1);
		res%=mod;
	}
	res%=mod;
	return mem=res;
}
signed main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ary[i]; 
	if(n<=m)
	{
		int cnt0=0;
		for(int i=1;i<=n;i++)cnt0+=(ary[i]==0);
		cout<<fp(m,cnt0);
		return 0;
	}
	cout<<dfs(1,0);
	
	return 0;
} 
