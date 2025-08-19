#include<bits/stdc++.h>
#define ll long long
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
const int N=1e6+5;
int n;
ll su[N],A[N],x[N],p[N],c[N];
ll dp[N];
int que[N];
inline double op(int j){
	return dp[j]+A[j];
}
inline double g(int j,int k){
	return (op(k)-op(j))/(su[k]-su[j]);
}
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	n=ra();
	for(ri int i=1;i<=n;++i){
		x[i]=ra(),p[i]=ra(),c[i]=ra();
		su[i]=su[i-1]+p[i];
		A[i]=A[i-1]+p[i]*x[i];
	}
	int h=1,t=1,tot;
	for(int i=1;i<=n;++i){
		while(h<t&&g(que[h],que[h+1])<x[i]) h++;
		tot=que[h];
		dp[i]=c[i]+dp[tot]+(su[i]-su[tot])*x[i]-(A[i]-A[tot]);
		que[++t]=i;
		while(h+1<t&&g(que[t-2],que[t-1])>g(que[t-1],que[t])) {
			que[t-1]=que[t],t--;
		}
	}
	ll ans=dp[n];
	for(int i=n;i>=1&&p[i]==0;--i){
		ans=min(ans,dp[i-1]);
	}
	cout<<ans;
	return 0;
}
