#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[1000005],ans,now,a[1000005],n,pp;
signed main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	cin>>n>>pp;
	for(int i = 1; i <= n; i++)
	{
		a[i]=n-i+1;
	} 
	do
	{
		now=0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i+1; j <= n; j++)
			{
				if(a[i]>a[j]) now++;
			}
		}
		//cout<<now<<endl;
		for(int i = 0; i < now; i++) ans+=p[i];
		p[now]++;
	}while(prev_permutation(a+1,a+n+1));
	cout<<ans%pp<<endl;
}
