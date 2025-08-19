#include<bits/stdc++.h>
#define F(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define il inline
#define cs const
#define ri register
#define int long long

using namespace std;

il int rd(){
	ri int x=0,f=1;
	ri char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

il void wt(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar(x%10+48);
	return;
}

cs int N=8005;
cs int v[25]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
struct lst{
	int w,u,t;
}a[N];
int n;
int f[N][N];

il int dfs(int fi,int i0){
	int cnt=0;
	if(i0>n) return 0;
	if(f[fi][i0]) return f[fi][i0];
	if(a[i0].w==15){
		if((a[i0].t-a[fi].t-1)&&abs(a[i0].u-a[fi].u)<=(a[i0].t-a[fi].t-1)*2){
			cnt=dfs(i0,i0+1)+v[a[i0].w];
		}
		else cnt=-1000000;
	}
	else{
		if((a[i0].t-a[fi].t-1)&&abs(a[i0].u-a[fi].u)<=(a[i0].t-a[fi].t-1)*2){
			cnt=dfs(i0,i0+1)+v[a[i0].w];
		}
		cnt=max(dfs(fi,i0+1),cnt);		
	}
	f[fi][i0]=cnt;
	return cnt;
}
int ans;
signed main(){
	F("sniper");
	n=rd();
	for(int i=1;i<=n;i++){
		a[i].w=rd(),a[i].u=rd(),a[i].t=rd();
	}
	for(int i=1;i<n;i++){
		ans=max(ans,dfs(i,i+1)+v[a[i].w]);	
	}
	wt(ans);
	return 0;
}

