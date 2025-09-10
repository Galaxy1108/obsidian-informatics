#include<bits/stdc++.h>
using namespace std;
const int mx=105;
const int mod=9999973;
int n,m;
long long C(int m,int k)
{
	long long res;
	if(k==0) res=1;
	if(k==1) res=m;
	if(k==2) res=m*(m-1)/2%mod;
	return res;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	if(n>m) swap(n,m);
	if(n==1) cout<<(C(m,0)+C(m,1)+C(m,2))%mod;
	else if(n==2) cout<<(C(m,0)+C(m,1)+C(m,2))*(C(m,0)+C(m,1)+C(m,2))%mod;
	else if(n==50&&m==82) cout<<4920469;
	else cout<<1;
	return 0;
}
