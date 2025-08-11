#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,mx=2e6;
int n,L[N],R[N],tot,a[N],m;
int v[N][N],dp[N][N],sum[N][N];
set<int>st;
int calc(int x){return x*x;}
void chkmin(int&x,const int&y){if(x>y)x=y;}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		L[i]=m+1;m+=x;R[i]=m;
		for(int j=L[i];j<=R[i];j++)scanf("%lld",a+j);
	}
	for(int i=1;i<=m;i++){
		int val=mx*mx;
		st.clear();st.insert(0),st.insert(mx);
		for(int j=i;j<=m;j++){
			if(st.find(a[j])==st.end()){
				auto p2=st.upper_bound(a[j]),p1=prev(p2);
				val-=calc((*p2)-(*p1));
				val+=calc((*p2)-a[j]);
				val+=calc(a[j]-(*p1)); 
				st.insert(a[j]);
			}v[i][j]=val;
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=L[1];i<=R[1];i++)for(int j=R[1];j<R[2];j++)dp[i][j]=v[i][j];
	for(int i=2;i<n;i++){
		for(int j=L[i];j<=R[i];j++)for(int k=R[i];k<R[i+1];k++)for(int l=L[1];l<=R[1];l++)
			chkmin(dp[l][k],dp[l][j-1]+v[j][k]);
	}
	for(int i=0;i<R[1];i++){
		int val=mx*mx;
		st.clear();st.insert(0),st.insert(mx);
		for(int j=1;j<=i;j++){
			if(st.find(a[j])==st.end()){
				auto p2=st.upper_bound(a[j]),p1=prev(p2);
				val-=calc((*p2)-(*p1));
				val+=calc((*p2)-a[j]);
				val+=calc(a[j]-(*p1)); 
				st.insert(a[j]);
			}
		}
		for(int j=R[n];j>=L[n];j--){
			if(st.find(a[j])==st.end()){
				auto p2=st.upper_bound(a[j]),p1=prev(p2);
				val-=calc((*p2)-(*p1));
				val+=calc((*p2)-a[j]);
				val+=calc(a[j]-(*p1)); 
				st.insert(a[j]);
			}sum[i][j]=val;
		}
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<R[1];i++)for(int j=L[n];j<=R[n];j++)
		chkmin(ans,sum[i][j]+dp[i+1][j-1]);
	printf("%lld\n",ans);
	return 0;
}
/*
某个集训队互测题，Xun_Xiaoyao未能场切 
考虑m<=1000 
所有的V(l,r)是容易O(n^2logn)求出的
设dp[l][r]为左端点为l,右端点为r的取值
可以O(m^3)转移?
相信常数 
*/
