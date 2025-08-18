#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,M=105,INF=0x3f3f3f3f3f3f;
int n,m,ary[N];
int memal[N][M][M];
bool visal[N][M][M];
#define mem memal[pos][prev][prev2]
#define vis visal[pos][prev][prev2]
int dfs(int pos,int prev,int prev2)
{
	if(vis)return mem;
	vis=true;
	if(pos>m&&prev2<=0)return mem=INF;
	if(pos==n+1)return 0;
	int res=INF;
	res=min(res,dfs(pos+1,prev-(prev>0),prev2-(prev2>0)));
	res=min(res,dfs(pos+1,m,prev-(prev>0))+ary[pos]);
	return mem=res;
}
signed main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ary[i];
	cout<<dfs(1,0,0);
	
	return 0;
} 
