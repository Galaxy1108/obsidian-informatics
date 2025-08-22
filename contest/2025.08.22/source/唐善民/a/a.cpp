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
using namespace std;
constexpr const int N=1e7,M=1e7;
int n,m,P,ans;
int sum[N+1];
vector<vector<int> >pre,preSumPre,suf,sufSumSuf;
void Start(){
	pre.resize(n+1);
	for(auto &i:pre){
		i.resize(m+1);
	}
	preSumPre.resize(n+1);
	for(auto &i:preSumPre){
		i.resize(m+1);
	}
	suf.resize(n+1);
	for(auto &i:suf){
		i.resize(m+2);
	}
	sufSumSuf.resize(n+1);
	for(auto &i:sufSumSuf){
		i.resize(m+2);
	}
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>P;
	Start();
	for(int l=1;l<=m;l++){
		suf[1][l]=m-l+1;
	}
	for(int r=1;r<=m;r++){
		pre[1][r]=r;
	}
	sum[1]=(m*(m+1ll)>>1)%P;
	for(int r=1;r<=m;r++){
		pre[1][r]=(pre[1][r]+pre[1][r-1])%P;
		preSumPre[1][r]=(pre[1][r]+preSumPre[1][r-1])%P;
	}
	sufSumSuf[1][m]=suf[1][m];
	for(int l=m-1;1<=l;l--){
		suf[1][l]=(suf[1][l+1]+suf[1][l])%P;
		sufSumSuf[1][l]=(suf[1][l]+sufSumSuf[1][l+1])%P;
	}
	for(int i=2;i<=n;i++){
		for(int r=1;r<=m;r++){
			pre[i][r]=(1ll*r*(sum[i-1]-suf[i-1][r+1])-preSumPre[i-1][r-1])%P;
		}
		for(int l=1;l<=m;l++){
			suf[i][l]=((m-l+1ll)*(sum[i-1]-pre[i-1][l-1])-sufSumSuf[i-1][l+1])%P;
		}
		for(int l=1;l<=m;l++){
			sum[i]=(sum[i]+(m-l+1ll)*(sum[i-1]-pre[i-1][l-1])%P-sufSumSuf[i-1][l+1])%P;
		}
		for(int r=1;r<=m;r++){
			pre[i][r]=(pre[i][r]+pre[i][r-1])%P;
			preSumPre[i][r]=(pre[i][r]+preSumPre[i][r-1])%P;
		}
		sufSumSuf[i][m]=suf[i][m];
		for(int l=m-1;1<=l;l--){
			suf[i][l]=(suf[i][l+1]+suf[i][l])%P;
			sufSumSuf[i][l]=(suf[i][l]+sufSumSuf[i][l+1])%P;
		}
	}
	int ans=suf[n][1];
	if(ans<0){
		ans+=P;
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
