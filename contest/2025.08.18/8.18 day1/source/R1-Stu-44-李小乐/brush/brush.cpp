#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	x=0;
	char c=getchar();
	int w=(c=='-'?-1:1);
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-48;
		c=getchar();
	}
	x*=w;
}
int n,m,cost[10001],f[10001][101],mn[10001][101];
signed main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)read(cost[i]);
	memset(f,0x3f,sizeof f);
	memset(mn,0x3f,sizeof mn);
	for(int i=0;i<=m;i++)mn[0][i]=0;
	for(int i=1;i<=n;i++){
		int tmp=min(m-2,i-1);
		for(int j=0;j<=tmp;j++){
			f[i][j]=mn[i-j-1][m-j-2]*(i-j-1>=0)*(m-j-2>=0)+cost[i];
			if(j)mn[i][j]=min(mn[i][j-1],f[i][j]);
			else mn[i][j]=f[i][j];
		}
	}
	int ans=13456789;
	for(int i=n-m+1;i<=n;i++){
		for(int j=0;j+n-i<m-1;j++){
			ans=min(ans,f[i][j]);
		}
	}
	printf("%lld",ans);
} 
