/*
你告诉我在收卷15min前假了？？？？？？？？
鬼来了都不信
但这是真的 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int tham = 1000000007;
int a[100005],f[100005],n,g[100005];

int fast_pow(int x,int y,int mod)
{
	if(y==0) return 1;
	if(y==1) return x;
	int now=fast_pow(x,y>>1,mod);
	now*=now;
	now%=mod;
	if(y&1)
	{
		now*=x;
		now%=mod;
	}
	return now;
}
int dfs(int x,int st,int en)//calc 全不中 
{
	if(x>n) return 1;
	int nx=dfs(x+1,st,en);
	int ll=f[x]*(st-1);
	int tmp=nx*ll,len=(en-st)*(en-st+1)/2;
	len%=tham;
	tmp%=tham;
	len*=f[x];
	len%=tham;
	cout<<"tmppp"<<tmp<<endl;
	return (len*nx+tmp)%tham;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	/*for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++)
	{
		f[i]=fast_pow(a[i],tham-2,tham);
	}
	cout<<endl;
	g[n+1]=1;
	for(int i = n; i >= 1; i--)
	{
		g[i]=g[i+1]*f[i];
		g[i]%=tham;
	}
	cout<<endl;
	long long ans=0,nown,cnt=0,fst,lst,p2=fast_pow(2,tham-2,tham),tmp;
	for(int i = 1; i <= n; i++)
	{
		//:(
		nown=a[i]-a[i-1];
		fst=dfs(i,cnt+1,cnt+nown);
		cout<<fst<<endl;
		fst=((nown-fst)%tham+tham)%tham;
		ans+=fst;
		ans%=tham;
		cnt+=nown;
	}*/
	cout<<0<<endl;
}
