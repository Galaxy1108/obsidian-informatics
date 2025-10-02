#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e3+5;

int N,a[MAXN];
int maxn[MAXN][MAXN];
int minn[MAXN][MAXN]; 
int ans=0;


signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout); 
	cin>>N;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=N;i++){
		maxn[i][i]=minn[i][i]=a[i];
		for(int j=i+1;j<=N;j++){
			maxn[i][j]=max(maxn[i][j-1],a[j]);
			minn[i][j]=min(minn[i][j-1],a[j]);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			ans=max(ans,maxn[i][j]*minn[i][j]*(j-i+1));
		}
	}
	cout<<ans;	
} 
