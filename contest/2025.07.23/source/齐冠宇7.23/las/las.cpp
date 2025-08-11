#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+5;
int n;
int c[N];
queue<int>q;
int ans[N];
inline int get(int i)
{
	if(ans[i] || !(c[i]>c[i%n+1]*2 || c[i]*2<c[i%n+1]))
		return 0;
	return (c[i]>c[i%n+1]*2)?i:i%n+1;
}
signed main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i],c[i]<<=1;
	for(int i=1;i<=n;i++)
		if(get(i))
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		//cout<<u<<' ';
		if(!get(u))
			continue;
		ans[u]=get(u);
		//cout<<ans[u]<<' ';
		c[ans[u]]>>=1;
		if(get(ans[u]))q.push(ans[u]);
		int pre=ans[u]-1;
		if(!pre)pre+=n;
		//cout<<pre<<' ';
		if(get(pre))q.push(pre);
	}
	for(int i=1;i<=n;cout<<ans[i++]<<' ')
		if(!ans[i])
		{
			int ft=(c[i]>c[i%n+1])?i:i%n+1;
			ans[i]=ft,c[ft]>>=1; 
		}
	return 0;
}
