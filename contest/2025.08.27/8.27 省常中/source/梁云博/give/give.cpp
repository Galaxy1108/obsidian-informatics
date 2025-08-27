#include <bits/stdc++.h>
#define N 205
using namespace std;
int a[N];
int b[N];
int cnt,len;
int m,s,n;
void dfs(int p,int sum)
{
	if(sum>s || p>m)return;
	if(sum==s && p==m)
	{
		cnt^=1;
		return;
	}
	for(int i=1;i<=len;i++)
	{
		dfs(p+1,sum+a[i]);
	}
}
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		len=cnt=0;
		cin>>m>>s>>n;
		if(m>10 || s>500)
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)cin>>b[i],a[i]=b[i];
		sort(a+1,a+1+n);
		len=unique(a+1,a+1+n)-a-1;
		dfs(0,0);
		cout<<cnt<<'\n';
	}
	return 0;
} 
