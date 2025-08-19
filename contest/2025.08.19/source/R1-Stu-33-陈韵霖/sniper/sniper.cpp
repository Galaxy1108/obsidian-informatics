#include<bits/stdc++.h>
#define ri register
using namespace std;
inline int ra(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int v[24]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int n;
bool tt[25005];
int dp[25005][22];
struct peo{
	int wi,ui,ti;
}c[8005];
int cnt=1;
void do_dp(int a){
	if(tt[a]){
		while(c[cnt].wi!=15) cnt++;
		for(int i=1;i<=20;++i){
			if(i!=c[cnt].ui) dp[a][i]=-1e6;
			else dp[a][i]+=50;
		}
		for(int j=max(1,c[cnt].ui-2);j<=min(20,c[cnt].ui+2);++j){
			dp[a+2][j]=max(dp[a+2][j],dp[a][c[cnt].ui]);
		}
		while(c[cnt].ti==a) cnt++;
		return;
	}
	if(c[cnt].ti>a){
		for(int i=1;i<=20;++i){
			for(int j=max(1,i-2);j<=min(20,i+2);++j){
				dp[a+1][j]=max(dp[a+1][j],dp[a][i]);
			}
		}
		return;
	}
	for(int i=1;i<=20;++i){
		for(int j=max(1,i-2);j<=min(20,i+2);++j){
			dp[a+1][j]=max(dp[a+1][j],dp[a][i]);
		}
	}
	if(tt[a+1]) return;
	while(c[cnt].ti==a){
		for(int j=max(1,c[cnt].ui-2);j<=min(20,c[cnt].ui+2);++j){
			dp[a+2][j]=max(dp[a+2][j],dp[a][c[cnt].ui]+v[c[cnt].wi]);
		}
		cnt++;
	}
	return;
}
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	n=ra();
	for(int i=1;i<=n;++i){
		c[i].wi=ra(),c[i].ui=ra(),c[i].ti=ra();
		if(c[i].wi==15) tt[c[i].ti]=1;
	}
	
	for(ri int i=1;i<=25000;++i)
		for(ri int j=1;j<=20;++j)
			dp[i][j]=-1e6;
	
	do_dp(0);
	for(int i=1;i<=c[n].ti+1;++i){
		do_dp(i);
	}
	int ans=0;
	for(int i=1;i<=20;++i){
		ans=max(ans,dp[c[n].ti+2][i]);
	}
	cout<<ans;
}
