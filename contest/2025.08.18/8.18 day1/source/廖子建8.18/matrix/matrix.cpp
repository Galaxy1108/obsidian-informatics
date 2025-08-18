#include<bits/stdc++.h>
#define int long long
#define N 100
#define K 10
#define Inf (1ll*INT_MAX*10000)
#define Ins (1ll*INT_MIN*10000)
using namespace std;
int n,m,k,dp1[N+5][N+5][K+5],dp2[N+5][N+5][N+5][K+5],f[4][N+5][N+5],a[N+5],b[N+5],ua,ub,uc,ud,ans=Ins;
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read(),k=read();
	if(m==1){
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			f[1][i][i]=a[i];
//			cout<<i<<" "<<i<<" "<<f[1][i][i]<<"\n";
			for(int j=i+1;j<=n;j++)f[1][i][j]=max(f[1][i][j-1],0ll)+a[j]/*,cout<<i<<" "<<j<<" "<<f[1][i][j]<<"\n"*/;
		}
		for(ua=0;ua<=n;ua++)for(ub=0;ub<=n;ub++)for(uc=0;uc<=k;uc++)dp1[ua][ub][uc]=Ins;
		dp1[1][0][0]=0;
		for(ua=1;ua<=n;ua++){
			for(ub=0;ub<ua;ub++){
				for(uc=0;uc<=k;uc++){
//					while(!dp1[ua][ub][uc])cout<<f[1][ub+1][ua]<<"\n";
//					while(ua==3&&ub==1&&uc==1)cout<<dp1[ua][ub][uc]<<" "<<f[1][ub+1][ua]<<"\n";
					if(uc<k)dp1[ua+1][ua][uc+1]=max(dp1[ua+1][ua][uc+1],dp1[ua][ub][uc]+f[1][ub+1][ua]);
					dp1[ua+1][ub][uc]=max(dp1[ua+1][ub][uc],dp1[ua][ub][uc]);
				}
			}
		}
		for(ub=0;ub<=n;ub++)ans=max(ans,dp1[n+1][ub][k]);
		print(ans);
		return 0;
	}
	else{
		for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
		for(int i=1;i<=n;i++){
			f[1][i][i]=a[i];
			for(int j=i+1;j<=n;j++)f[1][i][j]=max(f[1][i][j-1],0ll)+a[j];
		}
		for(int i=1;i<=n;i++){
			f[2][i][i]=b[i];
			for(int j=i+1;j<=n;j++)f[2][i][j]=max(f[2][i][j-1],0ll)+b[j];
		}
		for(int i=1;i<=n;i++){
			f[3][i][i]=a[i]+b[i];
			for(int j=i+1;j<=n;j++)f[3][i][j]=max(f[3][i][j-1],0ll)+a[j]+b[j];
		}
		for(ua=0;ua<=n;ua++)for(ub=0;ub<=n;ub++)for(uc=0;uc<=n;uc++)for(ud=0;ud<=k;ud++)dp2[ua][ub][uc][ud]=Ins;
		dp2[1][0][0][0]=0;
		for(ua=1;ua<=n;ua++){
			for(ub=0;ub<ua;ub++){
				for(uc=0;uc<ua;uc++){
					for(ud=0;ud<=k;ud++){
						if(ud<k){
							dp2[ua+1][ua][uc][ud+1]=max(dp2[ua+1][ua][uc][ud+1],dp2[ua][ub][uc][ud]+f[1][ub+1][ua]);
							dp2[ua+1][ub][ua][ud+1]=max(dp2[ua+1][ub][ua][ud+1],dp2[ua][ub][uc][ud]+f[2][uc+1][ua]);
							dp2[ua+1][ua][ua][ud+1]=max(dp2[ua+1][ua][ua][ud+1],dp2[ua][ub][uc][ud]+f[3][max(ub,uc)+1][ua]);
						}
						if(ud<k-1)dp2[ua+1][ua][ua][ud+2]=max(dp2[ua+1][ua][ua][ud+2],dp2[ua][ub][uc][ud]+f[1][ub+1][ua]+f[2][uc+1][ua]);
						dp2[ua+1][ub][uc][ud]=max(dp2[ua+1][ub][uc][ud],dp2[ua][ub][uc][ud]);
					}
				}
			}
		}
		for(ub=0;ub<=n;ub++)for(uc=0;uc<=n;uc++)ans=max(ans,dp2[n+1][ub][uc][k]);
		print(ans);
		return 0;
	}
	return 0;
}
