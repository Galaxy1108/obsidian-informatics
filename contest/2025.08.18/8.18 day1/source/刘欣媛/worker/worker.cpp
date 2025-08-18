#include <bits/stdc++.h>
using namespace std;
int f[105][3],cc[3];
char b[10005];
const int inf=1e9;
int n;
int dfs(int i,int type,int cnt,int c[3])
{
	if(c[type]==0) return inf;
	if(i>=n) 
	{
		//cnt+=min(c[0],1)+min(c[1],1)+min(c[2],1);
		return cnt;
	}
	int k=i+min(10,c[type]);
	k=min(k,n);
	c[type]=max(0,c[type]-10);
	//cout<<i<<" "<<cnt<<"\n";
	//i++;
	//cout<<i<<" "<<k<<" \n";
	//int u=i;
	for(i;i<=k;i++)
	{
		if(i>n) break;
		c[b[i]-'A']++;
	}
	//i=k;
	//cout<<i<<" "<<cnt<<"\n";
	
	return min(min(dfs(i,0,cnt+1,c),dfs(i,1,cnt+1,c)),dfs(i,2,cnt+1,c));
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=10;i++)
	{
		cc[b[i]-'A']++;
	}
	//cout<<"c:"<<c[0]<<" "<<c[1]<<" "<<c[2]<<"\n";
	if(n<=10)
	{
		cout<<min(cc[0],1)+min(cc[1],1)+min(cc[2],1);
		return 0;
	}
	int ans=min(min(dfs(10,0,0,cc),dfs(10,1,0,cc)),dfs(10,2,0,cc));
	//cout<<ans<<" "<<c[0]<<" "<<c[1]<<" "<<c[2]<<"\n";
	ans+=min(cc[0],1)+min(cc[1],1)+min(cc[2],1);
	cout<<ans;
//	int cnt=0;
//	while(1)
//	{
//		f[++cnt][]
//	}
	
	return 0;
 } 
