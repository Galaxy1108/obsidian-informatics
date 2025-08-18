#include<bits/stdc++.h>
#define ri register 
#define il inline
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define fil(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define int long long
using namespace std;
inline int rd(){
	register int x=0,f=1;
	register char c=getchar();
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
inline void wt(int n){
	if(n<0) putchar('-'),n=-n;
	if(n>10) wt(n/10);
	putchar(n%10+48);
	return;
}
const int N=10002;
int n,m,c[N],f[N][102][2],ans;
signed main(){
	fil("brush");
	n=rd(),m=rd();
	for(ri int i=1;i<=n;i++) c[i]=rd(),ans+=c[i];
	if(m>=n){
		int minn=ans,lmin=ans;
		for(int i=1;i<=n;i++){
			if(c[i]<=minn){
				lmin=minn;
				minn=c[i];
			}
			else if(c[i]<lmin){
				lmin=c[i];
			}
		}
		wt(minn+lmin);
		return 0;
	}
	for(ri int i=1;i<=n;i++){
		for(ri int j=1;j<=m;j++){
			f[i][j][1]=f[i][j][0]=ans;
		}
	}
	f[0][0][0]=f[0][0][1]=0; 
	f[1][1][0]=0,f[1][1][1]=c[1];
	for(ri int i=2;i<=n;i++){
		for(ri int j=i-1,l=j-1;l>=max(j+1-m,0);l--){
			if(l>=i+1-m) f[i][i-j][0]=min(f[j][j-l][1],f[i][i-j][0]);
			f[i][i-j][1]=min(f[j][j-l][1]+c[i],f[i][i-j][1]);
		}
		for(ri int j=i-2;j>=max(i+1-m,0);j--){
			f[i][i-j][1]=f[i-1][i-1-j][0]+c[i];
			for(ri int l=j-1;l>=max(i+1-m,0);l--){
				f[i][i-j][0]=min(f[j][j-l][1],f[i][i-j][0]);
			}
		}
	}
	for(ri int j=n-1;j>=n-m+1;j--) ans=min(ans,min(f[n][n-j][1],f[n][n-j][0]));
	wt(ans);
	return 0;
}
