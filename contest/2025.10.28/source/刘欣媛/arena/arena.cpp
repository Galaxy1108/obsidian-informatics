#include <bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long f[505][505];
int a[10];
int n,x;
long long ans;
inline void dfs(int k)
{
	if(k>=n){
		bool fl=1;
		int c1=n-1,c2=0;
		while(1)
		{
			c2=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]-c1>0) c2++;
				a[i]-=c1; 
			}
			c1=c2;
			if(c2==1){
				fl=0;
				break;
			}
			if(c2==0){
				break;
			}
		}
		if(fl==1){
			ans++;
		}
		return;
		
		
	}
	for(int i=1;i<=x;i++)
	{
		a[k+1]=i;
		dfs(k+1);
	}
}
int main()
{
//	freopen("arena.in","r",stdin);
//	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>x;
	if(n==2){
		cout<<x;
		return 0;
	}
	if(n==3){
		for(int i=1;i<=x;i++)
		{
			if(i%2==1&&i!=x){
				f[3][x]+=3*(i+1);
			}
			else
			{
				f[3][x]+=3*i;
			}
			
		}
		f[3][x]-=2*x;
		f[3][x]%=p;
		cout<<f[3][x]<<"\n";
		return 0;
	}
	if(x==2)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			if(ans>p) ans%=p;
		}
		cout<<ans;
		return 0;
	}
	if(x==1){
		cout<<1;
		return 0;
	}
	dfs(0);
	ans%=p;
	cout<<ans;
	
	return 0;
 } 
