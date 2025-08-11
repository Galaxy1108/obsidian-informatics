#include<bits/stdc++.h>
using namespace std; 
const int mx=1e6+10;
int H,W;
long long a[mx],b[mx];
long long dfs(int x,int y)
{
	if(x==1&&y==1) return 0;
	else
	{
		long long ans=1e18;
		if(x-1>=1) ans=min(ans,dfs(x-1,y)+b[y]);
		if(y-1>=1) ans=min(ans,dfs(x,y-1)+a[x]);
		return ans;
	}
}
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin>>H>>W;
	for(int i=1;i<=H;i++) cin>>a[i];
	for(int i=1;i<=W;i++) cin>>b[i];
	cout<<dfs(H,W);
	return 0;
}
