#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int maxn=5e3+5;
int a[maxn][maxn],n,seed,vis[maxn],ch[maxn],b[maxn],ans[maxn],rev[maxn][maxn],A,B;
int getans(){for(int i=1;i<=n+1;i++)if(!vis[i])return i;}
void upd(int x){
	int tmp;
	if(rev[x][A]<ch[x])vis[a[x][ch[x]]]=0,tmp=a[x][ch[x]],ch[x]=rev[x][A],vis[A]=1,A=tmp;
	if(rev[x][B]<ch[x])vis[a[x][ch[x]]]=0,tmp=a[x][ch[x]],ch[x]=rev[x][B],vis[B]=1,B=tmp;
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>seed;
	mt19937 rng(seed);
	for(int i=1;i<=n;i++){
		if(seed==0)for(int j=1;j<=n+1;j++)cin>>b[j];
		else{
			for(int j=1;j<=n+1;j++)b[j]=j;
			for(int j=1;j<=n+1;j++)swap(b[j],b[rng()%j+1]);
		}
		for(int j=1;j<=n+1;j++)a[i][b[j]]=j,rev[i][j]=b[j];
		// for(int j=1;j<=n+1;j++)cerr<<a[i][j]<<" ";
		// cerr<<endl;
	}
	for(int i=n;i>=1;i--){
		int v;
		for(int j=1;j<=n+1;j++)if(!vis[a[i][j]]){v=a[i][j];ch[i]=j;break;}
		vis[v]=1;
	}	
	A=(ans[1]=getans()),B=-1;
	for(int i=n;i>=2;i--){
		int t=a[i][ch[i]];vis[t]=0;ch[i]=0;
		if(A==-1)A=t;else B=t;
		for(int j=i-1;j>=1;j--)upd(j);
		for(int j=n;j>=i+1;j--)upd(j);
		if(rev[i][A]<rev[i][B])ch[i]=rev[i][A],ans[i]=B,vis[A]=1,A=-1;
		else ch[i]=rev[i][B],ans[i]=A,vis[B]=1,B=-1;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	return 0;
}