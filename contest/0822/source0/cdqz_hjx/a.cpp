#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,m,mod,res,nw;
vector<vector<int> > fl,fr;
vector<int> tmpl,tmpr,gl,gr;
int suml(int i,int j){
	int res=0;
	for(int k=1;k<=j;++k)
	res=(res+fl[i][k])%mod;
	return res;
}
int sumr(int i,int j){
	int res=0;
	for(int k=j;k<=m;++k)
	res=(res+fr[i][k])%mod;
	return res;
}
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>mod;tmpl.push_back(0);
	gr.push_back(0);gl.push_back(0);tmpr.push_back(0);
	if(m==1){
		cout<<1;
		return 0;
	}
	if(n==1){
		cout<<(m*(m+1)/2)%mod;
		return 0;
	}
	for(int i=1;i<=m;++i){
		tmpl.push_back((tmpl[i-1]+i)%mod);
		int x=(m-i+1);
		tmpr.push_back((x*(x+1)/2)%mod);
		gr.push_back(0);gl.push_back((gl[i-1]+tmpl[i])%mod);
	}gl.push_back(0);gr.push_back(0);gr.push_back(0);tmpr.push_back(0);
	fl.push_back(gl);fl.push_back(tmpl);
	fr.push_back(gl);fr.push_back(tmpr);
	for(int i=m;i>=1;--i)
		gr[i]=(gr[i+1]+tmpr[i])%mod;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=m;++j)
			fl[nw][j]=(mod+fl[nw][j-1]+(j*(fr[nw^1][1]-fr[nw^1][j+1]+mod))-gl[j-1])%mod;		
		for(int j=1;j<=m;++j)
			gl[j]=(gl[j-1]+fl[nw][j])%mod;
		for(int j=m;j>=1;--j)
			fr[nw][j]=(mod+fr[nw][j+1]+((m-j+1)*(fl[nw^1][m]-fl[nw^1][j-1]+mod))-gr[j+1])%mod;
		for(int j=m;j>=1;--j)
			gr[j]=(gr[j+1]+fr[nw][j])%mod;
		nw^=1;
	}		
	cout<<fl[nw^1][m];
	return 0;
}  
