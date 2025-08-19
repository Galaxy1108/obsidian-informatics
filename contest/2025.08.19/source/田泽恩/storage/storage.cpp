#include <bits/stdc++.h>
using namespace std;
long long n,x[1919810],dp[1919810],q[1919810],p[1919810],g[1919810],c[1919810],hd,tl;
long long slope_up(long long k,long long j){
	return dp[k]-dp[j]+g[j]-g[k];
}
long long slope_down(long long k,long long j){
	return p[j]-p[k];
}
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>p[i]>>c[i];
		p[i]+=p[i-1];
	}
	for(int i=1;i<=n;++i){
		g[i]=(p[i]-p[i-1])*(x[n]-x[i]);
		g[i]+=g[i-1];
	}
	int hd=1,tl=1;
	for(int i=1;i<=n;++i){
		while(hd<tl&&slope_up(q[hd+1],q[hd])<=(x[n]-x[i])*slope_down(q[hd+1],q[hd])) ++hd;
		int j=q[hd];
		dp[i]=dp[j]+g[i]-g[j]-(p[i]-p[j])*(x[n]-x[i])+c[i];
		while(hd<tl&&slope_up(i,q[tl])*slope_down(q[tl],q[tl-1])>=slope_up(q[tl],q[tl-1])*slope_down(i,q[tl])) --tl;
		q[++tl]=i;
	}
	cout<<dp[n];
	return 0;
}
