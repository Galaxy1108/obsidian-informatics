#include<bits/stdc++.h>
//#define int long long 
using namespace std;
const int mx=1e5+10;
const int inf=1e8;
int n;
int a[mx];
int cnt[mx][20];
long long ans=0;

signed main() 
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i],p=0;
		while(x)
		{
			if(x%2==1) cnt[i][p]=cnt[i-1][p]+1;
			x/=2;
			p++;
		}
	} 

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=min(n,i+1000);j++)
		{
			bool flag=1;
			for(int p=1;p<=20;p++)
			{
				if(cnt[j][p]-cnt[i][p]==j-i) flag=0;
				if((cnt[j][p]-cnt[i][p])%2==1) flag=0;
				
			}
			if(flag==1)ans++;
		}
	}
	cout<<ans;

	return 0;
}
