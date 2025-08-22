#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5003;
int n,seed,ans[N],now[N],a[N][N],b[N][N];
bool ban[N];
void Gen()
{
	if(!seed)
	{
		for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)cin>>a[i][j];
		return; 
	}
	mt19937 rd(seed);
    for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)
	    a[i][j]=j,swap(a[i][j],a[i][rd()%j+1]);
}
void Init()
{
	for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)b[i][a[i][j]]=j;
	for(int i=n;i>=1;i--)for(int j=1;j<=n+1;j++)
	    if(!ban[b[i][j]]){ban[b[i][j]]=1;now[i]=b[i][j];break;}
}
int Get(){for(int i=1;i<=n;i++)if(!ban[i])return i;return n+1;}
int Pre(int x){return x==1?n:x-1;} 
void Sol(int x)
{
	ban[now[x]]=0;int id=now[x],s=0;
	for(int i=Pre(x);i!=x;i=Pre(i))
		if(a[i][id]<a[i][now[i]])ban[id]=1,ban[now[i]]=0,swap(id,now[i]);
	for(int i=1;i<=n+1;i++)if(i!=id&&!ban[i])s=i;
	now[x]=a[x][s]<a[x][id]?s:id;ban[now[x]]=1;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>seed;Gen();Init();
	for(int i=n;i>=1;i--)ans[i==n?1:i+1]=Get(),Sol(i);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
