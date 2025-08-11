//#include<bits/stdc++.h>
#include<algorithm> 
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}

typedef long long ll;
constexpr const int N=2.5e6,P=1e9+7;
int n,k,s[N+1],st[N+1][__lg(N)+1];
ll dp[N+1];
int qpow(int base,int n){
	int ans=1;
	while(n){
		if(n&1){
			ans=1ll*base*ans%P;
		}
		base=1ll*base*base%P;
		n>>=1;
	}
	return ans;
}
void stPre(){
	for(int i=1;i<=n;i++){
		st[i][0]=s[i];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int x=1;x+(1<<i)-1<=n;x++){
			st[x][i]=max(st[x][i-1],st[x+(1<<i-1)][i-1]);
		}
	}
}
int stQuery(int l,int r){
	if(r<l){
		return 0;
	}
	int s=__lg(r-l+1);
	return max(st[l][s],st[r-(1<<s)+1][s]);
}
int main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	
	/*ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);*/
	
//	cin>>n>>k;
	n=Qread(),k=Qread();
	for(int i=1;i<=n;i++){
		s[i]=Qread();
//		cin>>s[i];
	}
	stPre();
	for(int i=1;i<=k;i++){
		dp[i]=max(dp[i-1],1ll*s[i]);
	}
	for(int i=k+1;i<=n;i++){
		dp[i]=1ll<<62;
		for(int j=i-k;j<i;j++){
			dp[i]=min(dp[i],dp[j]+stQuery(j+1,i));
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+dp[i]*qpow(23,n-i)%P)%P;
	}
	cout<<ans<<'\n';
	
	cout.flush(); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
