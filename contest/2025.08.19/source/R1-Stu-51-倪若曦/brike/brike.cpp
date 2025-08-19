#include<bits/stdc++.h>
#define F(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define il inline
#define cs const
#define ri register

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

int a[55][55],n,m;
int sum[55][55],cnt[55][55];

signed main(){
	F("brike");
	n=rd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			a[i][j]=rd();
			sum[i][j]=sum[i-1][j]+sum[i-1][j+1]-sum[i-2][j+1]+a[i][j];
			cnt[i][j]=(i+1)*i/2;
		}
	}
	if(m==cnt[n][1]){
		wt(sum[n][1]);
		return 0;
	}
	if(m==cnt[n][1]-1){
		wt(sum[n][1]-a[n][1]);
		return 0;
	}
	if(m==cnt[n][1]-2){
		wt(max(sum[n][1]-a[n][1]-a[n-1][1],sum[n][1]-a[n][1]-a[n-1][2]));
		return 0;
	}
	if(m==cnt[n][1]-3){
		int ans=max(sum[n][1]-a[n][1]-a[n-1][1]-a[n-2][1],sum[n][1]-a[n][1]-a[n-1][2]-a[n-2][3]);
		ans=max(ans,sum[n][1]-a[n][1]-a[n-1][1]-a[n-1][2]);
		wt(ans);
		return 0;
	}
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[1][i]);
		}
		wt(maxx);
		return 0;
	}
	if(m==2){
		int maxx=0,lm=0;
		for(int i=1;i<=n;i++){
			if(a[1][i]>=maxx){
				lm=maxx;
				maxx=a[1][i];
			}
			else if(a[1][i]>lm){
				lm=a[1][i];
			}
		}
		wt(maxx+lm);
		return 0;
	}
	if(m==3){
		int ans=0;
		int maxx=0,lm=0,llm=0;
		for(int i=1;i<=n;i++){
			if(a[1][i]>=maxx){
				llm=lm;
				lm=maxx;
				maxx=a[1][i];
			}
			else if(a[1][i]>=lm){
				llm=lm;
				lm=a[1][i];
			}
			else if(a[1][i]>llm){
				llm=a[1][i];
			}
		}
		ans=lm+llm+maxx;
		for(int i=1;i<n;i++){
			ans=max(ans,sum[2][i]);
		}
		wt(ans);
		return 0;
	}
	int a1=0,a2=0;
	for(int i=0;i<cnt[n][1]-m;i++){
		a1+=a[n-i][1];
		a2+=a[n-i][1+i];
	}
	wt(sum[n][1]-min(a1,a2));
	return 0;
}

