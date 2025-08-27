#include<bits/stdc++.h>
using namespace std;
const int N=205;
int T,m,s,n,ary[N];
int memal[2005][5005];
bool visal[2005][5005];
#define mem memal[pos][sum]
#define vis visal[pos][sum]
int dfs(int pos,int sum)
{
	if(vis)return mem;
	vis=true;
	if(pos==m+1)return mem=(sum==s);
	int res=0;
	for(int i=1;i<=n;i++)if(sum+ary[i]<=s)res=(res+dfs(pos+1,sum+ary[i]))%2;
	return mem=res;
}
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		memset(memal,0,sizeof(memal));
		memset(visal,false,sizeof(visal));
		cin>>m>>s>>n;
		for(int i=1;i<=n;i++)cin>>ary[i];	
		if(m>2000||s>5000)
		{
			cout<<0<<"\n";
			continue;
		}
		cout<<dfs(1,0)<<"\n";
	}
	
	return 0;
} 
