#include<bits/stdc++.h>
using namespace std;
#define int  long long
void read(int &x){
	x=0;
	char c=getchar();
	int w=1;
	while(!isdigit(c))
	{
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=w;
}
const int N=1e6+1;
int n,x[N],p[N],c[N],mn[2],f[2][N],dq[N]; 
signed main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	read(n);
	memset(mn,0x3f,sizeof mn);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		read(x[i]);
		read(p[i]);
		read(c[i]);
	}
	f[n&1][n]=c[n];
	mn[n&1]=c[n];
	for(int k=n-1;k>=1;k--){
		for(int i=1;i<=n;i++){
			f[k&1][i]=1234567891234567;
		}
		mn[k&1]=1234657891234567;
		for(int j=k+1;j<=n;j++){
			f[k&1][j]=f[(k+1)&1][j]+p[k]*(x[j]-x[k]);
			mn[k&1]=min(mn[k&1],f[k&1][j]);
		}
		f[k&1][k]=mn[(k+1)&1]+c[k];
		mn[k&1]=min(mn[k&1],f[k&1][k]);
	}
	int ans=1234567891235467;
	for(int i=1;i<=n;i++)ans=min(ans,f[1][i]);
	cout<<ans;
}
