#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll K;
ll f[20];
struct Mat{
	int n,m;
	ll c[12][12];
	void clear(){
		memset(c,0,sizeof(c));
	}
	Mat operator*(Mat x){
		Mat res; res.clear();
		res.n=n; res.m=x.m;
		for(int i=0;i<n;i++){
			for(int j=0;j<x.m;j++){
				for(int k=0;k<m;k++){
					res.c[i][j]+=c[i][k]*x.c[k][j]%mod;
					res.c[i][j]%=mod;
				}
			}
		}
		return res;
	}
}base,A;
void build(){
	base.n=base.m=10;
	for(int i=0;i<=9;i++){//Ã¶¾ÙÁÐ 
		for(int k=max(0,i-2);k<=min(9,i+2);k++){
			base.c[k][i]=1;
		}
	} 
	A.n=1; A.m=10;
	for(int i=1;i<=9;i++) A.c[0][i]=1; 
}
Mat qpow(Mat d,ll z){
	Mat res; res.clear();
	res.n=d.n; res.m=d.m;
	for(int i=0;i<res.n;i++) res.c[i][i]=1;
	while(z){
		if(z&1) res=res*d;
		d=d*d; z>>=1;
	}
	return res;
}
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	cin>>K;
	build();
	A=A*qpow(base,K-1);
	ll ans=0;
	for(int i=0;i<=9;i++){
		ans=(ans+A.c[0][i])%mod;
	} 
	cout<<ans;
	return 0;
}

